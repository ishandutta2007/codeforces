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
const int MAXN = 301;

int a[MAXN][MAXN];
int b[MAXN];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;
	FOR(i, n)
		FOR(j, n)
		{
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	FOR(i, n)
	{
		scanf("%d", &b[i]);
		b[i]--;
	}
	FOR(i, n)
		FOR(j, n)
		{
			if (a[i][j] == i)
				continue;
			int mn = INF;
			FOR(g, n)
			{
				if (b[g] == i)
					continue;
				if (b[g] == a[i][j])
					break;
				mn = min(mn, b[g]);
			}
			if (mn > a[i][j])
			{
				cout << a[i][j] + 1 << ' ';
				break;
			}
		}
	return 0;
}