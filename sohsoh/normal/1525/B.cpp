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

inline int solve() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	if (is_sorted(all(v))) cout << 0 << endl;
	else {
		for (int l = 0; l < n; l++) {
			for (int r = l; r < n; r++) {
				vector<int> vp = v;
				if (l == 0 && r == n - 1) continue;
				sort(vp.begin() + l, vp.begin() + r + 1);
				if (is_sorted(all(vp))) return cout << 1 << endl, 0;
			}
		}

		if (v[0] == n && v[n - 1] == 1) cout << 3 << endl;
		else cout << 2 << endl;
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