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

const ll MAXN = 1e6 + 10;
const ll SIG = 26;

int f[SIG], n, f_r[SIG];

int dfs(int v) {
	return f[v] >= 0 ? dfs(f[v]) : v;
}

inline void solve() {
	fill(f, f + SIG, -1);
	fill(f_r, f_r + SIG, -1);
	string fans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		if (count(f, f + SIG, -1) == 1) {
			int a = find(f, f + SIG, -1) - f;
			int b = find(f_r, f_r + SIG, -1) - f_r;

			f[a] = b;
			f_r[b] = a;
		}

		char tc;
		cin >> tc;

		int c = int(tc - 'a');
		int ans = 0;

		if (f[c] >= 0) ans = f[c];
		else {
			for (int k = 0; k < SIG; k++) {
				if (k == c || f_r[k] >= 0 || dfs(k) == c) continue;
				f[c] = k;
				f_r[k] = c;
				break;
			}

			ans = f[c];
		}

		fans.push_back(char(ans + 'a'));
	}

	cout << fans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}