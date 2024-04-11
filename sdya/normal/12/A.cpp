#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

char s[4][4];

int main()
{
	gets(s[0]);
	gets(s[1]);
	gets(s[2]);
	for (int i = 0; i < 3; i ++)
		for (int j = 0; j < 3; j ++)
			if (s[i][j] == 'X' && s[2 - i][2 - j] != 'X')
			{
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
	return 0;
}