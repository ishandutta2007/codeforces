#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 1e9 + 7;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int cnt[maxn], n;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		int x; cin >> x;
		if(x != -1) ++ cnt[x];
	}
	ll ans = 0;
	rep(i, 1, n) {
		ans += pow(2, cnt[i]) - 1;
	}
	ans = pow(2, n - 1) - 1 - ans;
	ans %= mod;
	cout << ans + (ans >> 63 & mod) << '\n';
}