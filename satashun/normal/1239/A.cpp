
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

const ll MOD = TEN(9) + 7;
const int MX = 100010;

ll dp[MX];
ll p2[MX];

int main() {
	p2[0] = 1;
	for (int i = 1; i < MX; ++i) {
		p2[i] = p2[i-1] * 2 % MOD;
	}

	int n, m;
	cin >> n >> m;

	dp[0] = 1;
	dp[1] = 1;
	
	for (int i = 2; i < MX; ++i) {
		dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	}

	ll ans = (dp[n] * 2 - 2) + 2 * dp[m];
	ans %= MOD;
	if (ans < 0) ans += MOD;
	cout << ans << endl;

	return 0;
}