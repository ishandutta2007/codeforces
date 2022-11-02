#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char s[110000];
char s1[110];
char s2[110];

bool check(char s[], char s1[], char s2[])
{
	int n = strlen(s), n1 = strlen(s1), n2 = strlen(s2);
	for (int i = 0; i <= n - n1; i ++)
	{
		bool have = true;
		for (int j = 0; j < n1; j ++)
			if (s1[j] != s[i + j]) {have = false; break;}
		if (have)
		{
			for (int j = i + n1; j <= n - n2; j ++)
			{
				bool good = true;
				for (int k = 0; k < n2; k ++)
					if (s2[k] != s[j + k]) {good = false; break;}
				if (good) return true;
			}
			return false;
		}
	}
	return false;
}

int main()
{
	gets(s);
	gets(s1);
	gets(s2);
	bool f = check(s, s1, s2); 
	reverse(s, s + strlen(s));
	bool b = check(s, s1, s2);
	if (f && !b) printf("forward\n"); else
		if (f && b) printf("both\n"); else
			if (!f && !b) printf("fantasy\n"); else
				printf("backward\n");
	return 0;
}