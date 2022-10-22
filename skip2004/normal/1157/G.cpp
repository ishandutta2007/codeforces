#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 202;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int n, m;
bool s[maxn][maxn];
bool t[maxn][2];
inline void check() {
	for(int i = 0;i < n;++i) {
		t[i][0] = t[i][1] = 0;
		for(int j = 0;j < m;++j) {
			t[i][s[i][j] ^ s[0][j]] = 1;
		}
		if(t[i][0] && t[i][1]) {
			return ;
		}
	}
	cout << "YES" << '\n';
	for(int i = 0;i < n;++i) {
		cout.put(48 + t[i][1]);
	}
	cout.put(10);
	for(int i = 0;i < m;++i) {
		cout.put(48 + s[0][i]);
	}
	exit(0);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n;++i) {
		for(int j = 0;j < m;++j) {
			char c; cin >> c;
			s[i][j] = c & 1;
		}
	}
	check();
	for(int i = n - 1;i >= 0;--i) {
		for(int j = m - 1;j >= 0;--j) {
			s[i][j] ^= 1;
			check();
		}
	}
	cout << "NO" << '\n';
	return 0;
}