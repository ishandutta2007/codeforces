#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

map < string, int > MP;
int n;
string s1, s2, s3;

int calc(string s)
{
	int u = 0, v = 0;
	for (int i = 0; i < s.size(); i ++)
		if (s[i] == '&') u ++;
	for (int i = 0; i < s.size(); i ++)
		if (s[i] == '*') v ++;
	string cur = "";
	for (int i = 0; i < s.size(); i ++)
		if (s[i] != '*' && s[i] != '&')
			cur += s[i];
	if (MP.count(cur))
	{
		int x = MP[cur];
		if (x == -1) return -1;
		int y = x + v - u;
		if (y < 0) return -1;
		return y;
	} else return -1;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	MP["void"] = 0;
	MP["errtype"] = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i ++)
	{
		cin >> s1;
		if (s1 == "typedef")
		{
			cin >> s2; 
			cin >> s3;
			int x = calc(s2);
			MP[s3] = x;
		} else
		{
			cin >> s2;
			int x = calc(s2);
			if (x == -1) printf("errtype\n"); else
			{
				printf("void");
				for (int j = 0; j < x; j ++)
					printf("*");
				printf("\n");
			}
		}
	}
	return 0;
}