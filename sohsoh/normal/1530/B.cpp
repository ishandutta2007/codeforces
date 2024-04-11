// Um_nlk :)))))
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

const ll MAXN = 100 + 10;

int n, m;
bool ans[MAXN][MAXN];

inline bool Check(int i, int j) {
	return !(ans[i - 1][j] || ans[i + 1][j] || ans[i][j - 1] || ans[i][j + 1] || ans[i - 1][j - 1] 
			|| ans[i - 1][j + 1] || ans[i + 1][j - 1] || ans[i + 1][j + 1]);
}

inline void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) ans[1][i] = Check(1, i);
	for (int i = 2; i <= n; i++) ans[i][m] = Check(i, m);
	for (int i = m - 1; i >= 1; i--) ans[n][i] = Check(n, i);
	for (int i = n - 1; i > 1; i--) ans[i][1] = Check(i, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
		       cout << ans[i][j];
		cout << endl;	
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < n + 10; i++)
			for (int j = 0; j < m + 10; j++)
				ans[i][j] = false;
		solve();
	}
	return 0;
}