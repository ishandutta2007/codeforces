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
const int MAXN = 1000002;

char s[MAXN];
int p[MAXN];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	scanf("%s", &s);
	int n = strlen(s);
	p[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		int cur = i - 1;
		while (cur >= 0 && s[i] != s[p[cur]])
		{
			cur = p[cur] - 1;
		}
		if (cur < 0) p[i] = 0;
			else p[i] = p[cur] + 1;
	}
	int mx = 0;
	for (int i = 1; i < n - 1; ++i)
		mx = max(mx, p[i]);
	int cur = n - 1;
	while (cur >= 0 && p[cur] > mx)
        cur = p[cur] - 1;
    mx = p[cur];
	if (mx == 0)
	{
		printf("Just a legend");
	}
	else
		FOR(i, mx)
			printf("%c", s[i]);
	return 0;
}