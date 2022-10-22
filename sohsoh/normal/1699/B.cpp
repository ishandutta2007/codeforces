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

bool ans[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(ans, false, sizeof ans);
		int n, m;
		cin >> n >> m;
		
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < m / 2; j++) {
				if ((i + j) % 2 == 0)
					ans[i << 1][j << 1] = ans[i << 1 | 1][j << 1 | 1] = 1;
				else
					ans[i << 1 | 1][j << 1] = ans[i << 1][j << 1 | 1] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << ans[i][j] << sep;
			cout << endl;
		}
	}
	return 0;
}