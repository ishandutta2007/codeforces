#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int n;
string s;

int main()
{
	cin >> n;
	cin >> s;
	if (n % 2 == 0)
	{
		for (int i = 0; i < s.size() / 2; i ++)
		{
			if (i != 0) printf("-");
			printf("%c%c", s[2 * i], s[2 * i + 1]);
		}
		printf("\n");
	} else
	{
		for (int i = 0; i < s.size() / 2; i ++)
		{
			if (i != 0) printf("-");
			printf("%c%c", s[2 * i], s[2 * i + 1]);
		}
		printf("%c\n", s[s.size() - 1]);
	}
	return 0;
}