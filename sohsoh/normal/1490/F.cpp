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

int n, A[MAXN];
map<int, int> cnt;
vector<int> cnt_v;

inline int solve() {
	cnt.clear();
	cnt_v.clear();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], cnt[A[i]]++;
	for (auto e : cnt) cnt_v.push_back(e.Y);
	sort(all(cnt_v));
	int ans = n, tans = n, p = 0;
	for (int i = 1; i <= n; i++) {
		while (p < cnt_v.size() && cnt_v[p] < i) tans += cnt_v[p], p++;
		tans -= cnt_v.size() - p;
		ans = min(tans, ans);
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