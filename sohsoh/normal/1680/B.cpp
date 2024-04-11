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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector<pll> vec;
		int n, m;
		cin >> n >> m;
		int u = n, l = m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				if (c == 'R') {
					vec.push_back({i, j});
					u = min(u, i);
					l = min(l, j);
				}
			}
		}

		bool flag = false;
		for (pll e : vec)
			if (e.X <= u && e.Y <= l)
				flag = true;
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}