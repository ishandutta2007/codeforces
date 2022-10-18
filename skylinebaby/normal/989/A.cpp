#include<bits/stdc++.h>
using namespace std;
char s[123456];
int main()
{
	cin >> s;
	int x = strlen(s);
	for(int i = 2;i<x;i++)
	{
		if (s[i-2]!='.'&&(s[i-1]!='.'&&s[i]!='.'))
		{
			if (s[i-2]!=s[i-1]&&(s[i-1]!=s[i]&&s[i-2]!=s[i]))
			{
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}