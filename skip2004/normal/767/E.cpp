#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, m;
int c[maxn], w[maxn];
int is[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> c[i];
	}
	std::priority_queue<std::pair<int, int>> q;
	ll ans = 0;
	rep(i, 1, n) { 
		cin >> w[i];
		if(c[i] % 100) {
			q.emplace(-(100 - c[i] % 100) * w[i], i);
			if(m < c[i] % 100) {
				m += 100;
				is[q.top().second] = 1;
				ans -= q.top().first;
				q.pop();
			}
			m -= c[i] % 100;
		}
	}
	cout << ans << '\n';
	rep(i, 1, n) {
		if(is[i]) {
			cout << c[i] / 100 + 1 << ' ' << 0 << '\n';
		} else {
			cout << c[i] / 100 << ' ' << c[i] % 100 << '\n';
		}
	}
}