#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[110], s2[110];

int main()
{
	gets(s1);
	gets(s2);
	sort(s1, s1 + strlen(s1));
	if (strlen(s1) == 1 && s1[0] == '0')
	{ 
		if (strlen(s2) == 1 && s2[0] == '0') cout << "OK" << endl; else
			cout << "WRONG_ANSWER" << endl;
		return 0;
	}
	for (int i = 0; i < strlen(s1); i ++)
		if (s1[i] != '0')
		{
			swap(s1[0], s1[i]);
			break;
		}
	if (strlen(s1) == strlen(s2))
	{
		for (int j = 0; j < strlen(s1); j ++)
			if (s1[j] != s2[j])
			{
				cout << "WRONG_ANSWER" << endl;
				return 0;
			}
		cout << "OK" << endl;
		return 0;
	}

	cout << "WRONG_ANSWER" << endl;
	return 0;
}