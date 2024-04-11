#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

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

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os<<"{";
    rep(i, v.size()) {
        if (i) os<<",";
        os<<v[i];
    }
    os<<"}";
    return os;
}

const ll MOD = 998244353;
const int B = 2010;

inline void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

ll dp[B][B * 2];

int main() {
	int n, k;
	cin >> n >> k;
	V<int> h(n);
	rep(i, n) cin >> h[i];

	dp[0][B] = 1;
	rep(i, n) {
		bool f = (h[i] == (h[(i+1) % n]));
		rep(j, B * 2) {
			if (dp[i][j] == 0) continue;
			if (f) {
				add(dp[i+1][j], dp[i][j] * k % MOD);
			} else {
				add(dp[i+1][j-1], dp[i][j]);
				add(dp[i+1][j+1], dp[i][j]);
				add(dp[i+1][j], dp[i][j] * (k - 2) % MOD);
			}
		}
	}

	ll ans = 0;
	for (int j = B + 1; j < B * 2; ++j) {
		add(ans, dp[n][j]);
	}
	cout << ans << endl;


	return 0;
}