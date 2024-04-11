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
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

const ll MOD = 998244353;
const int maxn = 1010;

string s;
vector<pii> g[maxn * 2];
ll p2[maxn * 2];
int col[maxn * 2];

bool dfs(int v, int c) {
	col[v] = c;
	for (pii e : g[v]) {
		if (col[e.fi] != -1 && col[e.fi] != (c ^ e.se)) {
			return false;
		}
		if (col[e.fi] == -1 && !dfs(e.fi, c ^ e.se)) {
			return false;
		}
	}
	return true;
}

int main() {
	p2[0] = 1;
	rep(i, maxn * 2 - 1) {
		p2[i + 1] = p2[i] * 2 % MOD;
	}

	cin >> s;
	int n = s.size();
	reverse(ALL(s));

	ll ans = 0;

	for (int l = 1; l < n; ++l) { //for a
		memset(col, -1, sizeof(col));
		rep(k, n * 2) g[k].clear();

		rep(k, l) {
			g[k].eb(l-1-k, 0);
		}
		rep(k, n) {
			g[n+k].eb(n+n-1-k, 0);
		}

		col[n+n-1] = 1;
		col[l-1] = 1;

		rep(k, n) {
			if (s[k] == '1') {
				if (k < l) {
					g[k].eb(n + k, 1);
					g[n + k].eb(k, 1);
				} else {
					col[n + k] = 1;
				}
			} else if (s[k] == '0') {
				if (k < l) {
					g[k].eb(n + k, 0);
					g[n + k].eb(k, 0);
				} else {
					col[n + k] = 0;
				}
			}
		}

		vi pcol(n * 2);
		rep(i, n * 2) pcol[i] = col[i];
		memset(col, -1, sizeof(col));

		int now = 0;
		bool ok = 1;

		rep(k, n * 2) if (pcol[k] != -1) {
			if (col[k] == -1) {
			if (!dfs(k, pcol[k])) {
				ok = 0;
				break;
			}
		} else {
			if (col[k] != pcol[k]) {
				ok = 0;
				break;
			}
		}
		}

		rep(k, n * 2) if ((k < l || k >= n) && col[k] == -1) {
			if (!dfs(k, 0)) {
				ok = 0;
				break;
			}
			now++;			
		}

		if (ok) {
			ans += p2[now];
			ans %= MOD;
		}
	}

	cout << ans << endl;

	return 0;
}