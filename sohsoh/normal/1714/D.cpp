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

const ll MAXN = 1e5 + 10;

pair<int, pll> dp[MAXN];
int n;
string t, S[MAXN];

inline void solve() {
	cin >> t >> n;
	for (int i = 1; i <= n; i++) cin >> S[i];
	
	t = "#" + t;
	for (int i = 1; i < int(t.size()); i++) {
		dp[i] = {MAXN, {0, 0}};
		for (int j = 1; j <= n; j++) {
			bool flag = true;
			int m = S[j].size();
			if (m > i) continue;

			for (int k = 0; k < m; k++)
				flag &= (S[j][m - k - 1] == t[i - k]);

			if (flag) {
				int mn_ind = i - m;
				for (int f = i - m; f < i; f++)
					if (dp[f] < dp[mn_ind])
						mn_ind = f;

				dp[i] = min(dp[i], {dp[mn_ind].X + 1, {mn_ind, j}});
			}
		}
	}

	int m = t.size() - 1;
	if (dp[m].X == MAXN) {
		cout << -1 << endl;
		return;
	}

	cout << dp[m].X << endl;
	while (m) {
		cout << dp[m].Y.Y << sep << m - int(S[dp[m].Y.Y].size()) + 1 << endl;
		m = dp[m].Y.X;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}