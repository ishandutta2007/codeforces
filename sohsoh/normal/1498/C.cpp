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

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int val[MAXN][MAXN];

inline void mkey(int& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
} 

inline void solve() {
	int n, k;
	cin >> n >> k;
	val[k][0] = 1;
	for (int i = k; i > 1; i--) {
		if (k % 2 == i % 2) {
			for (int j = 0; j < n; j++) {
				mkey(val[i][j + 1] += val[i][j]);
				mkey(val[i - 1][j] += val[i][j]);
				val[i][j] = 0;
			}
		} else {
			for (int j = n; j > 0; j--) {
				mkey(val[i][j - 1] += val[i][j]);
				mkey(val[i - 1][j] += val[i][j]);
				val[i][j] = 0;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= k + 4; i++)
		for (int j = 0; j <= n + 4; j++)
			mkey(ans += val[i][j]), val[i][j] = 0;
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}