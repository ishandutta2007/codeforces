#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, col, C[MAXN];
vector<pll> D;
vector<int> vec[MAXN];

inline int ask(int v) {
	cout << "? " << v << endl;
	int x;
	cin >> x;
	return x;
}

inline int solve() {
	D.clear();
	for (int i = 0; i < n + 10; i++) C[i] = 0, vec[i].clear();
	col = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int d;
		cin >> d;
		D.push_back({d, i});
	}

	sort(all(D), greater<pll>());
	for (auto [d, v] : D) {
		if (C[v]) continue;
		
		vec[++col].push_back(v);
		C[v] = col;

		while (d--) {
			int u = ask(v);
			if (C[u]) {
				for (int e : vec[col]) vec[C[u]].push_back(e), C[e] = C[u];
				break;
			}

			C[u] = col;
			vec[col].push_back(u);
		}
	}

	cout << "! ";
	for (int i = 1; i <= n; i++) cout << C[i] << sep;
	cout << endl;
	return 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}