#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define popc __builtin_popcount
using std::cin; using std::cout;
const int maxn = 1 << 21;
const int N = maxn / 16;
int n;
typedef unsigned __m32i, u32;
const u32 two = 0xaaaaaaaa;
const u32 one = 0x55555555;

inline u32 _mm32_add_epi2(u32 x, u32 y) { return x ^ y ^ ((x & y & one) << 1); }
inline u32 neg(u32 x) { return _mm32_add_epi2(~x, one); }
inline u32 _mm32_sub_epi2(u32 x, u32 y) { return _mm32_add_epi2(x, neg(y)); }
inline u32 _mm32_mullo_epu2(u32 x, u32 y) { return (x & y & one) | (((x << 1 & y) ^ (x & y << 1)) & two); }

const u32 s0 = 0xcccccccc, s1 = 0xf0f0f0f0, s2 = 0xff00ff00, s3 = 0xffff0000;
inline void fwt(__m32i * a) {
	for(int i = 0;i < N;++i) {
		a[i] = _mm32_add_epi2(a[i], a[i] << 2 & s0);
		a[i] = _mm32_add_epi2(a[i], a[i] << 4 & s1);
		a[i] = _mm32_add_epi2(a[i], a[i] << 8 & s2);
		a[i] = _mm32_add_epi2(a[i], a[i] << 16 & s3);
	}
	for(int i = 1;i < N;i <<= 1) {
		for(int j = 0;j < N;j += i + i) {
			for(int k = 0;k < i;++k) {
				a[i + j + k] = _mm32_add_epi2(a[i + j + k], a[j + k]);
			}
		}
	}
}
inline void ifwt(__m32i * a) {
	for(int i = 0;i < N;++i) {
		a[i] = _mm32_sub_epi2(a[i], a[i] << 2 & s0);
		a[i] = _mm32_sub_epi2(a[i], a[i] << 4 & s1);
		a[i] = _mm32_sub_epi2(a[i], a[i] << 8 & s2);
		a[i] = _mm32_sub_epi2(a[i], a[i] << 16 & s3);
	}
	for(int i = 1;i < N;i <<= 1) {
		for(int j = 0;j < N;j += i + i) {
			for(int k = 0;k < i;++k) {
				a[i + j + k] = _mm32_sub_epi2(a[i + j + k], a[j + k]);
			}
		}
	}
}
__m32i a[22][N], b[22][N], c[22][N];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	char ch;
	for(int i = 0;i < 1 << n;++i) {
		cin >> ch;
		a[popc(i)][i / 16] |= (ch & 15) << ((i & 15) << 1);
	}
	for(int i = 0;i < 1 << n;++i) {
		cin >> ch;
		b[popc(i)][i / 16] |= (ch & 15) << ((i & 15) << 1);
	}
	for(int i = 0;i <= 21;++i) {
		fwt(a[i]), fwt(b[i]);
	}
	for(int i = 0;i <= 21;++i) {
		for(int j = 0;i + j <= 21;++j) {
			__m32i * A = a[i], * B = b[j], * C = c[i + j];
			for(int k = 0;k < N;++k) {
				C[k] = _mm32_add_epi2(C[k], _mm32_mullo_epu2(A[k], B[k]));
			}
		}
	}
	for(int i = 0;i <= 21;++i) {
		ifwt(c[i]);
	}
	for(int i = 0;i < 1 << n;++i) {
		cout.put((c[popc(i)][i / 16] >> ((i & 15) << 1) & 3) | 48);
	}
}