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

const ll MAXN = 1e6 + 10;

int n, ans[MAXN];
vector<pll> Q[MAXN];

inline int i_feel_stupid_mn(int i, int x) {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (i / mid > x) l = mid + 1;
		else r = mid;
	}

	return l;
}

inline int i_feel_stupid_mx(int i, int x) {
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (i / mid < x) r = mid - 1;
		else l = mid;
	}

	return l;
}

inline void solve() {
	for (int i = 0; i < n + 10; i++)
		Q[i].clear();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		Q[i_feel_stupid_mn(i, x)].push_back({i_feel_stupid_mx(i, x), i});
	}

	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for (int i = 1; i <= n; i++) {
		for (pll e : Q[i]) pq.push(e);
		ans[pq.top().Y] = i;
		pq.pop();
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