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

const ll MAXN = 3e5 + 10;

set<pll> bad;
map<int, int> cnt;
vector<int> vec[MAXN], cnt_vec;
int n, m;

inline bool valid(int x, int y) {
	return bad.find(make_pair(x, y)) == bad.end();
}

inline ll best_pair(vector<int>& A, vector<int>& B) {
	if (A.empty() || B.empty()) return -1;
	if (valid(A[0], B[0])) return A[0] + B[0];	
	int n = A.size(), m = B.size();

	int ans = -1;
	for (int i = 0; i < n; i++) {
		int p = 0;
		while (p < m && !valid(A[i], B[p])) p++;
		if (p < m) ans = max(ans, A[i] + B[p]);
	}

	return ans;
}

inline void solve() {
	// clearrrrrrrrrrr
	// insert {y, x} {x, x}
	// sort vectors non increasing
	bad.clear();
	cnt.clear();
	for (int i = 0; i < n + 5; i++)
		vec[i].clear();
	cnt_vec.clear();

	cin >> n >> m;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		bad.insert({x, x});
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		bad.insert({x, y});
		bad.insert({y, x});
	}

	for (pll e : cnt) {
		cnt_vec.push_back(e.Y);
		vec[e.Y].push_back(e.X);
	}

	sort(all(cnt_vec));
	cnt_vec.resize(unique(all(cnt_vec)) - cnt_vec.begin());
	
	for (int i = 0; i < int(cnt_vec.size()); i++) {
		sort(all(vec[cnt_vec[i]]), greater<int>());
		for (int j = 0; j <= i; j++)
			ans = max(ans, best_pair(vec[cnt_vec[j]], vec[cnt_vec[i]]) * (cnt_vec[j] + cnt_vec[i]));
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