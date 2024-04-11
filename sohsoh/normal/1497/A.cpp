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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

map<int, int> cnt;

inline void solve() {
	cnt.clear();
	int n;
	cin >> n;
	set<int> st;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		st.insert(x);
	}

	for (int e : st) cout << e << sep, cnt[e]--;
	for (auto e : cnt) {
		int t = e.Y;
		while (t--) cout << e.X << sep;
	}

	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}