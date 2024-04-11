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
const ll INF = 1e9 + 7;

int n, m, pref_mn[MAXN], suff_mn[MAXN];
vector<pair<int, int>> vec[MAXN];
vector<int> tvec[MAXN];

inline int solve() {
	for (int i = 0; i <= max(n, m) + 5; i++)
		vec[i].clear(), tvec[i].clear();

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			vec[j].push_back({x, i});
			tvec[i].push_back(x);
		}
	}

	set<int> st;
	pref_mn[0] = suff_mn[n + 1] = INF;
	for (int i = 1; i <= n; i++) {
		sort(all(vec[i]));
		st.insert(vec[i].back().Y);
		pref_mn[i] = min(pref_mn[i - 1], vec[i].back().X);
	}

	for (int i = n; i > 0; i--)
		suff_mn[i] = min(suff_mn[i + 1], vec[i].back().X);

	if (st.size() < n) return cout << pref_mn[n] << endl, 0;

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		sort(all(tvec[i]));
		ans = max(ans, min(pref_mn[n], tvec[i][tvec[i].size() - 2]));
	}
	
	cout << ans << endl;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}