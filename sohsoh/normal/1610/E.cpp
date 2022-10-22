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
vector<int> X;
map<int, int> cnt;

inline void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		X.push_back(x);
		cnt[x]++;
	}

	sort(all(X));
	X.resize(unique(all(X)) - X.begin());

	int ans = 0;
	for (int i = 0; i < X.size(); i++) {
		int tans = cnt[X[i]], b = X[i];
		while (true) {
			auto it = lower_bound(all(X), 2 * b - X[i]);
			if (it == X.end()) break;
			if (*it == b) it++;
			if (it == X.end()) break;

			b = *it;
			tans++;
		}

		ans = max(ans, tans);
	}

	cout << n - ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		X.clear();
		cnt.clear();
		solve();
	}
	return 0;
}