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
const char * s[] = {
 "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};
int n, k;
char ch[maxn][10];
std::bitset<2010> can[2010];
inline int calc(const char * x, const char * ch) {
	int sum = 0;
	for(int j = 0;j < 7;++j) {
		if(x[j] == ch[j]) continue;
		if(x[j] == '1') ++ sum;
		else sum = 1e6;
	}
	return sum;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 0;i < n;++i) {
		cin >> ch[i];
	}
	can[n][0] = 1;
	for(int i = n - 1;i >= 0;--i) {
		for(auto x : s) {
			int v = calc(x, ch[i]);
			if(v <= 10) can[i] |= can[i + 1] << v;
		}
	}
	if(!can[0].test(k)) {
		cout << -1 << '\n';
		return 0;
	}
	for(int i = 0;i < n;++i) {
		for(int j = 9;j >= 0;--j) {
			int v = calc(s[j], ch[i]);
			if(v <= k && can[i + 1].test(k - v)) {
				cout.put(j + 48);
				k -= v;
				break;
			}
		}
	}
}