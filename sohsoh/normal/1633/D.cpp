#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e3 + 10;
const ll MAXK = 1e6 + 10;

int cost[MAXN], n, k, dp[MAXN * 20], B[MAXN];
map<int, vector<int>> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(cost, 63, sizeof cost);
	cost[1] = 0;

	for (int i = 1; i < MAXN; i++) {
		for (int x = 1; x <= i; x++) {
			int j = i + i / x;
			if (j < MAXN)
				cost[j] = min(cost[j], cost[i] + 1);
		}
	}

	int t;
	cin >> t;
	while (t--) {
		mp.clear();
		memset(dp, 0, sizeof dp);

		cin >> n >> k;
		k = min(k, 20 * n);

		for (int i = 1; i <= n; i++) cin >> B[i];
		for (int i = 1; i <= n; i++) {
			int c;
			cin >> c;

			for (int j = k; j >= 0; j--) {
				if (j - cost[B[i]] >= 0) {
					dp[j] = max(dp[j], dp[j - cost[B[i]]] + c);
				}
			}
		}

		cout << dp[k] << endl;
	}
	return 0;
}