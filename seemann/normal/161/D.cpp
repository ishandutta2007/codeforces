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
const int MAXN = 50001;
const int MAXL = 502;

vector<int> e[MAXN];
int dp[MAXN][MAXL];
ll ans = 0;
bool use[MAXN];
int n, k;

void dfs(int v) {
	use[v] = true;
	dp[v][0] = 1;
	FOR(i, e[v].size()) {
		int v1 = e[v][i];
		if (use[v1])
			continue;
		dfs(v1);
		FOR(j, k) {
			ans += ((ll)dp[v][j]) * dp[v1][k - j - 1];
		}
		FOR(j, k - 1) {
			dp[v][j + 1] += dp[v1][j];
		}
	}
	return;
}

int main()
{
	//freopen("a.in", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	
	scanf("%d%d", &n, &k);
	FOR(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	clr(use);
	clr(dp);
	dfs(0);
	cout << ans;

	return 0;
}