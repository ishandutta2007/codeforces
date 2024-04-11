//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 150005;
int x;
ll pw[maxn];
ll c(int a, int b) {
	return pw[a + b] - pw[a] - pw[b] + 1;
}
int cal(vi a, vi b, int f, int j) {
	if (!a.size() && !b.size()) return 0;
	// f : whether reverse or not
	if (j == -1) {
		ll ans = pw[a.size() + b.size()] - 1;
		return ans;
	}
	int cur = (x & (1 << j));
	vi x[2], y[2];
	for (auto v : a)
		if (v & (1 << j)) x[1].pb(v);
		else x[0].pb(v);
	for (auto v : b)
		if (v & (1 << j)) y[1].pb(v);
		else y[0].pb(v);
	if (cur == 0) {
		ll ans = cal(x[0], y[0], f, j - 1) + cal(x[1], y[1], f, j - 1);
		ans %= mod;
		if (f) {
			ans += c(x[0].size(), x[1].size());
			ans += c(y[0].size(), y[1].size());
			ans %= mod;
		}
		return ans;
	}
	else {
		if (!f) {
			for (auto v : y[0]) x[0].pb(v);
			for (auto v : y[1]) x[1].pb(v);
			return cal(x[0], x[1], 1, j - 1);
		}
		ll a1 = cal(x[0], y[1], 1, j - 1);
		ll a2 = cal(x[1], y[0], 1, j - 1);
		ll ans = (a1 + 1) * (a2 + 1) % mod - 1;
		return ans;
	}

}
int main() {
	pw[0] = 1;
	for (int i = 1; i < maxn; i++)
		pw[i] = pw[i - 1] * 2 % mod;
	int n;
	cin >> n >> x;
	vi c(n); for (int i = 0; i < n; i++) cin >> c[i];
	ll ans = cal(c, vi(0), 0, 29);
	ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
    return (0-0); //<3
}