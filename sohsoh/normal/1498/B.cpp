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

int n, W;

inline int solve() {
	cin >> n >> W;
	multiset<int> st;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}

	int ans = 0;
	while (!st.empty()) {
		ll rem = W;
		while (!st.empty()) {
			auto it = st.upper_bound(rem);
			if (it == st.begin()) break;
			it--;
			rem -= *it;
			st.erase(it);
		}

		ans++;
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}