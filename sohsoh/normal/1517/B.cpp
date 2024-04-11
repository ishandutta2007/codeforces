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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m;
multiset<int> st[MAXN];

inline int solve() {
	for (int i = 0; i < n + 3; i++) st[i].clear();
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			st[i].insert(x);
		}
	}

	vector<vector<pll>> V;
	for (int i = 1; i <= m; i++) {
		int mn_ind = 1;
		V.push_back({});
		for (int i = 1; i <= n; i++)
			if (*st[i].begin() < *st[mn_ind].begin())
				mn_ind = i;
		V.back().push_back({mn_ind, *st[mn_ind].begin()});
		st[mn_ind].erase(st[mn_ind].begin());
		for (int i = 1; i <= n; i++) {
			if (i == mn_ind) continue;
			V.back().push_back({i, *st[i].rbegin()});
			st[i].erase(st[i].find(*st[i].rbegin()));
		}
	}

	for (int i = 1; i <= m; i++)
		sort(all(V[i - 1]));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << V[j][i].Y << sep;
		cout << endl;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}