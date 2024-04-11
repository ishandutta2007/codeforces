#include<bits/stdc++.h>
const int maxn = 10010000;
typedef long long ll;
using std::cin;
using std::cout;
inline ll c(int n){ return (ll) n * (n - 1) >> 1; }
int n, m;
int phi[maxn], d[maxn];
int cnt[maxn], pre[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n, m = n / 2 + 1;
	for(int i = 1;i <= n;++i) phi[i] = i;
	for(int i = 2;i <= n;++i) if(phi[i] == i) 
		for(int j = i;j <= n;j += i) phi[j] = phi[j] / i * (i - 1);
	for(int i = n;i >= 2;--i) if(phi[i] == i - 1)
		for(int j = i;j <= n;j += i) d[j] = i;
	for(int i = 1;i <= n;++i) ++ cnt[d[i]];
	for(int i = 1;i <= n;++i) pre[i] = pre[i - 1] + cnt[i];
	ll c0 = 0, c1 = 0, c2 = 0, c3 = 0;
	c0 = n;
	for(int i = m;i <= n;++i) c0 -= phi[i] == i - 1;
	c0 = c(n) - c(c0 - 1);
	for(int i = 2;i <= n;++i) c1 += i - phi[i] - 1;
	for(int i = 1;i <= n;++i) c2 += (ll) cnt[i] * pre[n / i];
	for(int i = 1;i <= n;++i) c2 -= (ll) d[i] * d[i] <= n;
	c2 /= 2;
	c2 -= c1;
	c3 = c(n) - c0 - c1 - c2;
	cout << std::max<ll>(0, c1 + c2 * 2 + c3 * 3 - 1) << '\n';
}