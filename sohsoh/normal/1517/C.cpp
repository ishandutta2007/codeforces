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

int n, A[MAXN], ans[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		int k = t;
		int x = i, y = i;
		while (k > 0 && x > 0 && y > 0 && x <= n && y <= n) {
			k--;
			ans[x][y] = t;
			if (y == 1) x++;
			else if (ans[x][y - 1] == 0) y--;
			else x++;
		}

		if (k) return cout << -1 << endl, 0;
	}

	for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				cout << ans[i][j] << sep;
			}

			cout << endl;
		}
	return 0;
}