#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

int n, m, ans;
vector<int> D[MAXN];

int main() {
	scanf("%d %d", &n, &m);
	ll n_fact = 1;

	for (int i = 0; i < n; i++) {
		n_fact = n_fact * (i + 1) % MOD;
		for (int j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			D[j].push_back(x);
		}
	}

	for (int i = 0; i < m; i++) {
		sort(all(D[i]));
		ll cnt = 0, tans = 1;
		for (int j = 0; j < n; j++) {
			while (!D[i].empty() && D[i].back() >= n + 1 - j) D[i].pop_back(), cnt++;
			tans = tans * cnt % MOD;
			cnt--;	
		}	

		ans = (ans + n_fact - tans + MOD) % MOD;
	}
	
	printf("%lld \n", ans * poww(n_fact, MOD - 2) % MOD);
	return 0;
}