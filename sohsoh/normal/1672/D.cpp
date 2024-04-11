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

inline vector<pll> f(vector<int> vec) {
	vector<pll> ans;
	for (int e : vec) {
		if (ans.empty() || ans.back().X != e)
			ans.push_back({e, 0});
		ans.back().Y++;
	}

	return ans;
}

int lst[MAXN], n, g[MAXN];

inline int solve() {
	for (int i = 0; i < n + 5; i++)
		lst[i] = g[i] = 0;

	cin >> n;
	vector<int> ta, tb;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ta.push_back(x);
	}
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		tb.push_back(x);
	}

	vector<pll> a = f(ta), b = f(tb);
	for (int i = int(a.size()) - 1; i >= 0; i--) {
		g[i] = lst[a[i].X];
		lst[a[i].X] = i;
	}

	int pa = 0;
	for (int pb = 0; pb < int(b.size()); pb++) {
		while (pa < int(a.size()) && (a[pa].X != b[pb].X || a[pa].Y < b[pb].Y)) {
			a[g[pa]].Y += a[pa].Y;
			pa++;
		}

		if (pa == int(a.size())) return cout << "NO" << endl, 0;
		a[g[pa]].Y += a[pa].Y - b[pb].Y;
		pa++;
	}

	cout << "YES" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}