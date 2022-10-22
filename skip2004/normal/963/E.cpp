#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 8000;
typedef long long ll;
const int mod = 1e9 + 7;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int mem[300][300];
inline int&get(int x, int y) { return mem[x + 105][y + 105]; }
int R, p1, p2, p3, p4, a1, a2, a3, a4, tot;
int a[maxn][maxn];
int ans[maxn];
inline void gs() {
	for(int i = 1;i <= tot;++i) {
		const int inv = inverse(a[i][i]);
		static std::vector<int> has_pos;
		for(int j = i;j <= tot + 1;++j) if(a[i][j]) {
			has_pos.push_back(j);
		}
		for(int j = i + 1;j <= tot;++j) if(a[j][i]) {
			const int v = (ll) inv * a[j][i] % mod;
			for(int k : has_pos) a[j][k] = (a[j][k] + ll(mod - v) * a[i][k]) % mod;
		}
		has_pos.clear();
	}
	ans[tot + 1] = 1;
	for(int i = tot;i >= 1;--i) {
		for(int j = tot + 1;j > i;--j) {
			ans[i] = (ans[i] + (ll) (mod - ans[j]) * a[i][j]) % mod;
		}
		ans[i] = (ll) ans[i] * inverse(a[i][i]) % mod;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> R >> a1 >> a2 >> a3 >> a4;
	ll I = inverse(a1 + a2 + a3 + a4);
	p1 = I * a1 % mod; p2 = I * a2 % mod;
	p3 = I * a3 % mod; p4 = I * a4 % mod;
	rep(i, -R, R) {
		rep(j, -R, R) if(i * i + j * j <= R * R) {
			get(i, j) = ++ tot;
		}
	}
	rep(i, -R, R) {
		rep(j, -R, R) if(get(i, j)) {
			a[get(i, j)][get(i, j)] = mod - 1;
			a[get(i, j)][tot + 1] = 1;
			if(get(i - 1, j)) a[get(i, j)][get(i - 1, j)] = p1;
			if(get(i + 1, j)) a[get(i, j)][get(i + 1, j)] = p3;
			if(get(i, j - 1)) a[get(i, j)][get(i, j - 1)] = p2;
			if(get(i, j + 1)) a[get(i, j)][get(i, j + 1)] = p4;
		}
	}
	gs();
	cout << ans[get(0, 0)] << '\n';
}