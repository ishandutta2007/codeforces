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

const ll MAXN = 100 + 2;
const ll MAXM = 20;
const ll INF = 4e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[2][1 << MAXM], n, m, b;
vector<pair<pll, int>> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		int k, x, msk = 0, t;
		cin >> x >> k >> t;
		
		for (int j = 0; j < t; j++) {
			int x;
			cin >> x;
			msk |= (1 << (x - 1));
		}

		v.push_back({{k, x}, msk});
	}

	fill(dp[0], dp[0] + (1 << MAXM), INF);
	dp[0][0] = 0;
	sort(all(v));
	
	ll ans = INF, tans = 0;
	int lst = 0, ind = 1;
	for (auto e : v) {
		tans = (e.X.X - lst) * b;
		lst = e.X.X;
		for (int msk = 0; msk < (1 << m); msk++)
			dp[ind & 1][msk] = min(dp[1 - (ind & 1)][msk], dp[1 - (ind & 1)][msk ^ (msk & e.Y)] + e.X.Y) + tans;
		ans = min(ans, dp[ind & 1][(1 << m) - 1]);
		ind++;
	}

	cout << ((ans == INF) ? -1 : ans) << endl;
	return 0;
}