#include<bits/stdc++.h>
const int maxn = 500100;
const int mod = 1e9 + 7;
typedef long long ll;
typedef double db;
const ll inf = 1e10;
using std::cin;
using std::cout;
int n, q;
db s[maxn];
db pw[maxn];
int a[maxn];
int p2[maxn], sum[maxn];
int fa[maxn], pre[maxn];
int suf[maxn], ans[maxn];

inline int sub(int l, int r) {
	return (suf[l] + (ll) (mod - suf[r + 1]) * p2[r - l + 1]) % mod;
}
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
std::vector<std::pair<int, int>> v[maxn];

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	*pw = *p2 = 1;
	for(int i = 1;i < maxn;++i) {
		p2[i] = p2[i - 1] * 2 % mod;
		pw[i] = pw[i - 1] * 2;
	}
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		s[i] = a[i];
		fa[i] = i;
		pre[i] = i - 1;
	}
	for(int i = n;i >= 1;--i) {
		suf[i] = (suf[i + 1] * 2u + a[i] + mod) % mod;
	}
	for(int i = 1, l, r;i <= q;++i) {
		cin >> l >> r;
		v[r].emplace_back(i, l);
	}
	for(int i = 1;i <= n;++i) {
		for(;s[i] >= -0.5 && pre[i];) {
			const int x = pre[i], y = i;
			fa[x] = y, pre[y] = pre[x];
			if(fabs(s[y]) < 0.5) {
				s[y] = s[x];
			} else {
				s[y] = round(s[y] * pw[x - pre[x]] + s[x]);
			}
		}
		sum[i] = (sum[pre[i]] + sub(pre[i] + 1, i) * 2u) % mod;
		for(const auto & x : v[i]) {
			int p = find(x.second);
			ans[x.first] = (sub(x.second, p) + sum[i] - sum[p] + mod + 0u) % mod;
		}
	}
	for(int i = 1;i <= q;++i) {
		cout << ans[i] << '\n';
	}
}