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

inline int solve() {
	int n;
	vector<int> a, b[2];
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	sort(all(a));
	for (int i = 0; i < n; i++)
		b[i >= n / 2].push_back(a[i]);

	if (b[0].size() != b[1].size()) return cout << "NO" << endl, 0;

	vector<int> ans;
	for (int i = 0; i < n / 2; i++)
		ans.push_back(b[0][i]), ans.push_back(b[1][i]);

	for (int i = 0; i < n; i++)
		if (ans[i] == ans[(i + 1) % n])
			return cout << "NO" << endl, 0;

	cout << "YES" << endl;
	for (int e : ans)
		cout << e << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}