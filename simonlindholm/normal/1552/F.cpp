#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 998244353;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	vi x(N), y(N), s(N);
	rep(i,0,N) {
		cin >> x[i] >> y[i] >> s[i];
	}
	ll res = x[N-1] + 1;
	vector<ll> dp(N), dpsums(N+1);
	ll dpsum = 0;
	rep(i,0,N) {
		int it = (int)(lower_bound(all(x), y[i]) - x.begin());
		dp[i] = (x[i] - y[i] + dpsum - dpsums[it]) % mod;
		dpsum += dp[i];
		dpsum %= mod;
		dpsums[i+1] = dpsum;
	}
	rep(i,0,N) if (s[i]) res += dp[i];
	res %= mod;
	if (res < 0) res += mod;
	cout << res << endl;
	exit(0);
}