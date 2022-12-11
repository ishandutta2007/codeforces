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

const int MAXN = 2001;

char c[MAXN][MAXN];
int x[MAXN];
int y[MAXN];
int m[MAXN];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;
	FOR(i, n)
		FOR(j, n)
			scanf(" %c", &c[i][j]);
	FOR(i, n)
		FOR(j, n)
			c[i][j] -= '0';
	clr(x);
	clr(y);
	int ans = 0;
	FOR(i, n - 1)
	{
		int a = n - i - 1;
		int b = 0;
		FOR(j, i + 1)
		{
			if ((x[a] + y[b] + c[a][b]) % 2 == 1)
			{
				ans++;
				y[b]++;
				x[a]++;
			}
			a++;
			b++;
		}
	}
	clr(m);
	FOR(i, n)
		m[i] += x[i] + y[i];

	clr(x);
	clr(y);
	FOR(i, n - 1)
	{
		int a = 0;
		int b = n - i - 1;
		FOR(j, i + 1)
		{
			if ((x[a] + y[b] + c[a][b]) % 2 == 1)
			{
				ans++;
				y[b]++;
				x[a]++;
			}
			a++;
			b++;
		}
	}
	FOR(i, n)
		m[i] += x[i] + y[i];
	FOR(i, n)
		if ((m[i] + c[i][i]) % 2 == 1)
			ans++;
	cout << ans;
			

	return 0;
}