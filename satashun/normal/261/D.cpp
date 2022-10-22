#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<int, ll> pil;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define MX 100010
#define INF (1LL<<60)

inline void chmin(ll &x, ll y) { if (x > y) x = y; }

int k, n, mb, t;
int a[MX], ret;

int main() {
    scanf("%d%d%d%d", &k, &n, &mb, &t);
    vector<vector<ll>> dp(2, vector<ll>(mb));
    vector<vi> to(n + 1, vi(mb));
    vi hd(mb);

    while (k--) {
	for (int i = 0; i <= n; ++i) {
	    rep(j, mb) {
		to[i][j] = n;
	    }
	}

	rep(i, mb) {
	    hd[i] = n;
	    dp[1][i] = INF;
	}

	rep(i, n) scanf("%d", &a[i]), --a[i];

	for (int i = n - 1; i >= 0; --i) {
	    rep(j, mb) to[i][j] = hd[j];
	    hd[a[i]] = dp[1][a[i]] = i;
	}

	ret = 1;

	int c = 1, f = 0;

	for (int i = 2; i <= n; ++i) {
	    rep(j, mb) dp[f][j] = INF;

	    ll mi = INF;

	    rep(j, mb) {
		if (mi < (ll)n * t) {
		    int pos = mi % n, lp = mi / n;
		    
		    int x = hd[j];

		    if (x != n) chmin(dp[f][j], mi - pos + x + (x < pos ? n : 0));

		    x = to[pos][j];

		    if (x != n) chmin(dp[f][j], mi - pos + x);

		    if (dp[f][j] < (ll)n * t) ret = i;
		}
		chmin(mi, dp[c][j]);
	    }

	    if (ret != i) break;

	    swap(c, f);
	}

	printf("%d\n", ret);

    }
    return 0;
}