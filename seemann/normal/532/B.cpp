#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;

const ll INF = 1e15;
const ldb EPS = 1e-8;
const int MAXN = 3e5 + 1000;

int p[MAXN];
int a[MAXN];
ll dp[2][MAXN];
vector<int> e[MAXN];
ll vd[2][MAXN];

void dfs(int v) {
    for(auto u : e[v])
        dfs(u);
    FOR(i, e[v].size() + 1) {
        vd[0][i] = vd[1][i] = -INF;
    }
    vd[0][0] = 0;

    FOR(i, e[v].size()) {
        int u = e[v][i];
        FOR(j, 2) {
            FOR(k, 2) {
                int st = j ^ k;
                vd[st][i + 1] = max(vd[st][i + 1], vd[j][i] + dp[k][u]);
            }
        }
    }
    vd[1][e[v].size()] = max(vd[1][e[v].size()], vd[0][e[v].size()] + a[v]);
    FOR(i, 2)
        dp[i][v] = vd[i][e[v].size()];
}

int main() {
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	scanf("%d", &n);
	FOR(i, n) {
	    scanf("%d%d", &p[i], &a[i]);
	    p[i]--;
	    if (i > 0)
	        e[p[i]].pb(i);

	}
	dfs(0);
	cout << max(dp[0][0], dp[1][0]);
	return 0;
}