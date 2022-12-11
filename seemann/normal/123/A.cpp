#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;

vector <int> pr;
char s1[1002];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	string s;
	int c[200];
	cin >> s;
	int n = s.length();
	clr(c);
	FOR(i, n)
		c[s[i]]++;
	pr.push_back(1);
	for (int i = 2; i <= n; ++i)
	{
		bool ind = true;
		for (int j = 2;j < i; ++j)
			if (i % j == 0)
			{
				ind = false;
				break;
			}
		if (!ind) continue;
		if (i * 2 > n)
			pr.push_back(i);
	}
	int sz = n - pr.size();
	char mc;
	bool ind = false;
	for (char i = 'a'; i <= 'z'; ++i)
		if (c[i] >= sz)
		{
			ind = true;
			c[i] -= sz;
			mc = i;
			break;
		}
	if (!ind)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	clr(s1);
	FOR(i, n)
		s1[i] = mc;
	char p1 = 'a';
	FOR(i, pr.size())
	{
		while (c[p1] == 0)
			p1++;
		s1[pr[i] - 1] = p1;
		c[p1]--;
	}
	printf("%s", s1);

		

	return 0;
}