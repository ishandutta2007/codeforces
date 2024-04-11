#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 1 << 16;
typedef long long ll;
const int mod = 998244353;
inline ll pow(ll a,int b,int ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1)
		ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
int wn[maxn], rev[maxn], lim;
inline void init(int len){
	for(lim = 1;lim < len;lim <<= 1);
	for(int i = 1;i < lim;++i) rev[i] = rev[i >> 1] >> 1 | (i % 2 * lim / 2);
	for(int mid = 1;mid < lim;mid <<= 1){
		wn[mid] = 1; const int W = pow(3,mod / mid / 2);
		for(int i = 1;i < mid;++i) wn[i + mid] = (ll) wn[i + mid - 1] * W % mod;
	}
}
inline void fft(int * a,int type){
	typedef unsigned long long u64;
	static u64 t[maxn];
	for(int i = 0;i < lim;++i) t[rev[i]] = a[i];
	for(int mid = 1;mid < lim;mid <<= 1){
		for(int j = 0;j < lim;j += mid + mid){
			for(int k = 0;k < mid;++k){
				const u64 x = t[j + k + mid] * wn[mid + k] % mod;
				t[j + k + mid] = t[j + k] + mod - x; t[j + k] += x;
			}
		}
	}
	if(type){
		for(int i = 0;i < lim;++i) a[i] = t[i] % mod;
	} else {
		const int lm = inverse(lim); a[0] = t[0] % mod * lm % mod;
		for(int i = 1;i < lim;++i) a[i] = t[lim - i] % mod * lm % mod;
	}
}
const int M = 1 << 16;
struct Mat { int a[2][2][M]; } E, I, T, D;
int n, k;
inline Mat operator * (Mat a, Mat b) {
	Mat c = E;
	for(int i = 0;i < 4;++i) {
		fft(a.a[i >> 1][i & 1], 1);
		fft(b.a[i >> 1][i & 1], 1);
	}
	for(int i = 0;i < 2;++i) {
		for(int j = 0;j < 2;++j) {
			for(int k = 0;k < 2;++k) {
				for(int l = 0;l < lim;++l) {
					c.a[i][k][l] = (c.a[i][k][l] + (ll) a.a[i][j][l] * b.a[j][k][l]) % mod;
				}
			}
		}
	}
	for(int i = 0;i < 2;++i) {
		for(int j = 0;j < 2;++j) {
			fft(c.a[i][j], 0);
			for(int i0 = k + 1;i0 < lim;++i0) c.a[i][j][i0] = 0;
		}
	}
	return c;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	I.a[0][0][0] = I.a[1][1][0] = 1;
	T.a[1][0][0] = T.a[1][1][0] = 1;
	T.a[0][1][1] = T.a[1][1][1] = 1;
	D.a[0][0][0] = D.a[0][1][0] = D.a[0][1][1] = 1;
	init(M);
	for(int b = n - 1;b;b >>= 1, T = T * T) {
		if(b & 1) {
			D = D * T;
		}
	}
	for(int i = 1;i <= k;++i) {
		cout << D.a[0][1][i] << ' ';
	}
}