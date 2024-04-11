#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

string s;

int main()
{
	cin >> s;
	int t = 0;
	while (true)
	{
		if (t >= s.size()) return 0;
		if (s[t] == '.') printf("0"), t ++; else
		if (s[t] == '-' && s[t + 1] == '.') printf("1"), t += 2; else
			printf("2"), t += 2;
	}
	printf("\n");
	return 0;
}