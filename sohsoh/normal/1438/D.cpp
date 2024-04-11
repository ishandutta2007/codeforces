#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline int solve(int n) {
	cout << "YES" << endl;
	if (n == 3) return cout << 1 << endl << 1 << sep << 2 << sep << 3 << endl, 0;
	vector<tuple<int, int, int>> ans;
	for (int i = 1; i < n; i += 2) ans.push_back({i, i + 1, n});
	for (int i = n - 1; i > 0; i -= 2) ans.push_back({n, i, i - 1});
	cout << ans.size() << endl;
	for (auto e : ans)
		cout << get<0> (e) << sep << get<1> (e) << sep << get<2> (e) << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int xor_t = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		xor_t ^= x;
	}

	if (n & 1) solve(n);
	else if (xor_t) return cout << "NO" << endl, 0;
	else solve(n - 1);
	return 0;
}