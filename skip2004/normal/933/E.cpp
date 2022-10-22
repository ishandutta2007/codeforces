#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 300200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n;
int a[maxn], go[maxn];
ll dp[maxn];
std::vector<int> v;
inline void clear(int x) {
	if(0 < x && x < n && a[x] && a[x + 1]) {
		v.push_back(x);
		int min = std::min(a[x], a[x + 1]);
		a[x] -= min, a[x + 1] -= min;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	dp[2] = a[1];
	for(int i = 3;i <= n + 1;++i) {
		ll v0 = dp[i - 3] + std::max(a[i - 1], a[i - 2]), v1 = dp[i - 2] + a[i - 1];
		dp[i] = std::min(v0, v1);
		go[i] = v0 < v1 ? i - 3 : i - 2;
	}
	for(int i = dp[n] < dp[n + 1] ? n : n + 1;i;i = go[i]) {
		if(go[i] == i - 2) {
			clear(i - 1);
			clear(i - 2);
		} else {
			clear(i - 2);
			clear(i - 1);
			clear(i - 3);
		}
	}
	cout << v.size() << '\n';
	for(int i : v) {
		cout << i << '\n';
	}
}