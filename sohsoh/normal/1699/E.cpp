#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e7 + 10;

int n, m, f[MAXN], c[MAXN];
bool vis[MAXN];

inline void solve() {
	cin >> n >> m;
	for (int i = 1; i <= 2 * m; i++) {
		f[i] = 2 * m;
		c[i] = 0;
		vis[i] = false;
	}

	int mn = m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (!vis[x]) {
			vis[x] = true;
			mn = min(mn, x);
			c[2 * m]++;
		}
	}

	int ans = MAXN, tans = 2 * m;
	for (int i = m; i > 0; i--) {
		if (vis[i]) c[f[i]]--;
		f[i] = i;
		if (vis[i]) c[f[i]]++;

		for (int j = i; j <= m; j += i) {
			if (vis[j]) c[f[j]]--;
			f[j] = min(f[j], f[j / i]);
			if (vis[j]) c[f[j]]++;
		}

		while (!c[tans]) tans--;
		ans = min(ans, tans - i);
	}

	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}