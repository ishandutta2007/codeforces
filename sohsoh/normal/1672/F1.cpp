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

int n;
set<int> st;
vector<int> vec[MAXN], ans;

inline void cyc_shift(vector<int> t) {
	if (t.empty()) return;
	int x = ans[t.back()];

	for (int i = int(t.size()) - 1; i > 0; i--)
		ans[t[i]] = ans[t[i - 1]];
	ans[t.front()] = x;
}

inline void solve() {
	st.clear();
	for (int i = 0; i < n + 5; i++)
		vec[i].clear();
	ans.clear();

	ans.push_back(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		vec[x].push_back(i);
		st.insert(i);
		ans.push_back(x);
	}
	
	while (!st.empty()) {
		vector<int> tmp, t;
		for (int e : st) {
			if (vec[e].empty()) tmp.push_back(e);
			else t.push_back(vec[e].back()), vec[e].pop_back();
		}

		cyc_shift(t);
		for (int e : tmp)
			st.erase(e);	
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << sep;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}