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
int s[maxn];
inline bool ins(int x) {
	for(int i = 30;i >= 0;--i) {
		if(x >> i & 1) {
			if(s[i]) {
				x ^= s[i];
			} else {
				return bool(s[i] = x);
			}
		}
	}
	return 0;
}
int n;
int a[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0;i < n;++i) {
		cin >> a[i];
	}
	for(int m = 29;;--m) {
		memset(s, 0, sizeof s);
		std::vector<int> vc;
		for(int i = 0;i < n;++i) {
			if(a[i] < 1 << m && ins(a[i])) {
				vc.push_back(a[i]);
			}
		}
		if(vc.size() == m) {
			cout << m << '\n';
			for(int i = 0;i < 1 << m;++i) {
				int s = i ^ i >> 1, out = 0;
				for(int j = 0;j < m;++j) if(s >> j & 1) {
					out ^= vc[j];
				}
				cout << out << ' ';
			}
			return 0;
		}
	}
}