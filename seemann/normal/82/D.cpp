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
const int MAXN = 1002;

int a[MAXN];
int dp[MAXN][MAXN];
int p[MAXN][MAXN];
int w[MAXN];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	scanf("%d", &n);
	FOR(i, n)
		scanf("%d", &a[i]);
	FOR(i, MAXN)
		FOR(j, MAXN)
			dp[i][j] = INF;
	dp[0][0] = 0;
	p[0][0] = -1;
	FOR(i, n / 2 + n % 2)
	{
		FOR(j, n)
		{
			if (dp[i][j] == INF) continue;
			if (2 * i == n - 2)
			{
				if (dp[i + 1][0] > dp[i][j] + max(a[j], a[n - 1]))
				{
					dp[i + 1][0] = dp[i][j] + max(a[j], a[n - 1]);
					p[i + 1][0] = j;
				}
				continue;
			}
			if (2 * i == n - 1)
			{
				if (dp[i + 1][0] > dp[i][j] + a[j])
				{
					dp[i + 1][0] = dp[i][j] + a[j];
					p[i + 1][0] = j;
				}
				continue;
			} 
			int c1 = i * 2 + 1;
			int c2 = i * 2 + 2;
			if (dp[i + 1][j] > dp[i][j] + max(a[c1], a[c2]))
			{
				dp[i + 1][j] = dp[i][j] + max(a[c1], a[c2]);
				p[i + 1][j] = j;
			}
			if (dp[i + 1][c1] > dp[i][j] + max(a[j], a[c2]))
			{
				dp[i + 1][c1] = dp[i][j] + max(a[j], a[c2]);
				p[i + 1][c1] = j;
			}
			if (dp[i + 1][c2] > dp[i][j] + max(a[c1], a[j]))
			{
				dp[i + 1][c2] = dp[i][j] + max(a[c1], a[j]);
				p[i + 1][c2] = j;
			}
		}
	}
	
	int l =  n / 2 + n % 2;
	
	int last = 0;
	for (int i = l; i >= 0; --i)
	{
		w[i] = p[i][last];
		last = w[i];
	}
	printf("%d\n", dp[l][0]);
	set <int> st;
	for (int i = 1; i < l; ++i)
	{
		st.insert(w[i]);
		st.insert(2 * i - 1);
		st.insert(2 * i);
		st.erase(w[i + 1]);
		foreach(st, it)
			printf("%d ", *it + 1);
		st.clear();
		printf("\n");
	}
	if (n % 2 == 1)
		printf("%d", w[l] + 1);
	else printf("%d %d", w[l] + 1, n);


	return 0;
}