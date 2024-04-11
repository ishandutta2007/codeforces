#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

string s1, s2, s3;

int code(char s)
{
	if (s >= '6' && s <= '9') return s - '0';
	if (s == 'T') return 10;
	if (s == 'J') return 11;
	if (s == 'Q') return 12;
	if (s == 'K') return 13;
	return 14;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> s1 >> s2 >> s3;
	if (s2[1] == s1[0] && s3[1] == s1[0])
	{
		if (code(s2[0]) > code(s3[0]))
			printf("YES\n"); else
			printf("NO\n");
		return 0;
	}
	if (s2[1] != s1[0] && s3[1] != s1[0])
	{
		if (s2[1] == s3[1] && code(s2[0]) > code(s3[0]))
			printf("YES\n"); else
			printf("NO\n");
		return 0;
	}
	if (s2[1] == s1[0])
		printf("YES\n"); else
		printf("NO\n");
	return 0;
}