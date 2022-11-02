#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

int parse(string s) {return (s[2] - '0') * 10 + (s[3] - '0');}

map < string, int > MP;
map < string, int > S;
int n, m, k;
string buf;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n >> m;
	cin >> buf;
	k = parse(buf);

	for (int i = 1; i <= n; i ++)
	{
		string s;
		int level;
		cin >> s;
		cin >> level;
		MP[s] = level;
	}

	for (map < string, int > :: iterator it = MP.begin(); it != MP.end(); it ++)
	{
		int cur = it->second;
		cur = (cur * k) / 100;
		if (cur < 100) cur = 0;
		if (cur != 0)
			S[it->first] = cur;
	}

	for (int i = 1; i <= m; i ++)
	{
		string s;
		cin >> s;
		if (S.count(s) == 0) S[s] = 0;
	}

	printf("%d\n", S.size());
	for (map < string, int > :: iterator it = S.begin(); it != S.end(); it ++)
		cout << it->first << " " << it->second << endl;
	return 0;
}