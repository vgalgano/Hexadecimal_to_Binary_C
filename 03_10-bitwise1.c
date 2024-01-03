#include <stdio.h>

/* convert an integer into a string of 1s and 0s */
char *binString(unsigned short n)
{
	static char bin[17];
	int x;

	for(x=0;x<16;x++)
	{
		bin[x] = n & 0x8000 ? '1' : '0';
		n <<= 1; /* The bit shift operators ( >> and << ) move each binary digit one place over (depending on the direction of the arrows) and so on.
		Each bit sequence will be compared to 0x8000 - 1000000000000000
		1st iteration 1010101010101010 & 1000000000000000 -> 1
		2nd iteration (shift n of one bit to the left -> 0101010101010100 & 1000000000000000 -> 0
        3rd iteration 1010101010101000 & 1000000000000000 -> 1
        and so on...
		*/
	}
	bin[16] = '\0';

	return(bin);
}

int main()
{
	unsigned short a,b,c;

	a = 0xAAAA; /* 1010101010101010 */
	b = 0x00FF; /* 0000000011111111 */

	printf("Start: %04X - %s\n",a,binString(a));
	printf("     & %04X - %s\n",b,binString(b));
	c = a & b;
	printf("  End: %04X - %s\n",c,binString(c));

	return 0;
}
