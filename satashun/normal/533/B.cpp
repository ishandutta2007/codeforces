#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

ll INF = -100000000000;

int n;
vi g[200010];
int a[200010];
ll dp[200010][2][2];//dp[v][1][1]..NG
ll dp2[2][200010][2][2];

void dfs(int v) {
    int c = 0, f = 1;
    rep(i, 2) rep(j, 2) dp2[0][v][i][j] = INF;
    dp2[0][v][0][0] = 0;
    dp2[0][v][1][0] = a[v];

    for (int to : g[v]) {
	rep(i, 2) rep(j, 2) dp2[f][v][i][j] = INF;
	dfs(to);

	rep(i, 2) rep(j, 2) {
	    rep(k, 2) rep(l, 2) {
		if (k && l) continue;
		dp2[f][v][i][(j + l + k) & 1] = max(dp2[f][v][i][(j + l + k) & 1], dp2[c][v][i][j] + dp[to][k][l]);
	    }
	}
	swap(c, f);
    }

    rep(i, 2) rep(j, 2) {
	dp[v][i][j] = i && j ? INF : dp2[c][v][i][j];
    }
}

int main() {
    cin >> n;
    rep(i, n) {
	int p;
	cin >> p >> a[i];
	if (p != -1) g[p - 1].pb(i);
    }

    dfs(0);

    cout << max({dp[0][1][0], dp[0][0][1], dp[0][0][0]}) << endl;

    return 0;
}