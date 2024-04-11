#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

char s[200];

int have[26];

int main()
{
	gets(s);
	for (int i = 0; i < strlen(s); i ++)
		if (s[i] >= 'a' && s[i] <= 'z') have[s[i] - 'a'] = i + 1; else
			if (s[i] >= 'A' && s[i] <= 'Z') have[s[i] - 'A'] = i + 1;

	int mx = 0;
	for (int i = 0; i < 26; i ++)
		if (have[i] > have[mx]) mx = i;
	if (mx + 'a' == 'a' || mx + 'a' == 'e' || mx + 'a' == 'i' || mx + 'a' == 'o' || mx + 'a' == 'u' || mx + 'a' == 'y')
		cout << "YES" << endl; else
		cout << "NO" << endl;
	return 0;
}