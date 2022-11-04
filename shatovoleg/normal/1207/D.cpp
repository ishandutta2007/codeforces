#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
 
void run();
 
signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

const int mod = 998244353;

void run() {
	int n;
	cin >> n;
	vector<int> fact(n + 1, 1);
	for (int i = 1; i < n + 1; ++i) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	vector<pii> v(n);
	map<int, int> x, y;
	map<pii, int> xy;
	for (auto &[a, b] : v) {
		cin >> a >> b;
		++x[a];
		++y[b];
		++xy[mp(a, b)];
	}
	int ans = 0;
	int cur = 1;
	for (auto &[a, b] : x) {
		cur *= fact[b];
		cur %= mod;
	}
	ans += cur;
	cur = 1;
	for (auto &[a, b] : y) {
		cur *= fact[b];
		cur %= mod;
	}
	ans += cur;
	cur = 1;
	for (auto &[a, b] : xy) {
		cur *= fact[b];
		cur %= mod;
	}
	sort(all(v));
	bool good = true;
	for (int i = 0; i + 1 < n; ++i) {
		good &= (v[i].second <= v[i + 1].second);
	}
	if (good) {
		ans -= cur;
	}
	ans = fact[n] - ans;
	ans %= mod;
	if (ans < 0) {
		ans += mod;
	}
	cout << ans << endl;
}