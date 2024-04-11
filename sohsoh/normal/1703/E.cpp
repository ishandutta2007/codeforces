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

const ll MAXN = 1e2 + 10;

bool G[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				char c;
				cin >> c;
				G[i][j] = (c == '1');
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int cnt = G[i][j] + G[j][n - i + 1] + G[n - i + 1][n - j + 1] + G[n - j + 1][i];
				ans += min(cnt, 4 - cnt);
			}
		}

		cout << ans / 4 << endl;
	}
	return 0;
}