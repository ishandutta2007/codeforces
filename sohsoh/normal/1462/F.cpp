#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;

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

int n, ps1[MAXN], cnt1[MAXN], ps2[MAXN], cnt2[MAXN];
vector<pll> seg;
vector<int> v;

inline void Compress() {
	v.clear();
	for (pll e : seg) v.push_back(e.X), v.push_back(e.Y);
	sort(all(v));
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (pll& e : seg) {
		e.X = lower_bound(all(v), e.X) - v.begin() + 1;
		e.Y = lower_bound(all(v), e.Y) - v.begin() + 1;
	}	
}

void handy_fill(int* a) {
	for (int i = 0; i < 2 * n + 10; i++) a[i] = 0;
} 

int solve() {
	handy_fill(ps1);
	handy_fill(ps2);
	handy_fill(cnt1);
	handy_fill(cnt2);
	cin >> n;
	seg.clear();
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		seg.push_back({l, r});
	}

	Compress();	
	
	int ans = n;

	for (pll e : seg) {
		cnt1[e.X]++;
		cnt2[e.Y]++;
	}

	for (int i = 1; i <= 2 * n + 7; i++) ps1[i] = cnt2[i] + ps1[i - 1];
	for (int i = 2 * n + 7; i > 0; i--) ps2[i] = ps2[i + 1] + cnt1[i];
	for (pll e : seg) {
		ans = min(ans, ps1[e.X - 1] + ps2[e.Y + 1]);
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