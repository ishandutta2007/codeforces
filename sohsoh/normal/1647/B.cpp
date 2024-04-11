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

int n, m;
bool B[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char c;
				cin >> c;
				B[i][j] = (c == '1');
			}
		}

		bool flag = false;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				int cnt = (B[i][j] + B[i][j + 1] + B[i + 1][j] + B[i + 1][j + 1]);
				flag |= (cnt == 3);
			}
		}

		cout << (flag ? "NO" : "YES") << endl;
	}
	return 0;
}