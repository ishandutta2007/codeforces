#include<bits/stdc++.h>
using std::cin;
using std::cout;

typedef unsigned long long u64;
const u64 i5 = 57646075230342349;
const int N = 1e5;
struct wwj {
	u64 a0, a1, a2, a3;
	// 1, w, w^2, w^3

	// w^4 = w^3 - w^2 + w - 1
	// w^5 = -1
	// w^6 = -w

	inline wwj(u64 b0, u64 b1, u64 b2, u64 b3) :
		a0(b0), a1(b1), a2(b2), a3(b3) {}
	inline wwj() {}
	inline wwj& operator += (const wwj & b) { a0 += b.a0, a1 += b.a1, a2 += b.a2, a3 += b.a3; return *this; }
	inline wwj& operator -= (const wwj & b) { a0 -= b.a0, a1 -= b.a1, a2 -= b.a2, a3 -= b.a3; return *this; }
	inline wwj operator * (const wwj & b) {
		u64 w4 = a1 * b.a3 + a2 * b.a2 + a3 * b.a1;
		return wwj(
			 a0 * b.a0 - a2 * b.a3 - a3 * b.a2 - w4
			,a0 * b.a1 + a1 * b.a0 - a3 * b.a3 + w4
			,a0 * b.a2 + a1 * b.a1 + a2 * b.a0 - w4
			,a0 * b.a3 + a1 * b.a2 + a2 * b.a1 + a3 * b.a0 + w4
		);
	}
} a[N];
inline wwj pow(wwj a, int b) {
	wwj ans(1, 0, 0, 0);
	for(;b;b >>= 1, a = a * a) if(b & 1)
		ans = ans * a;
	return ans;
}
inline wwj operator + (wwj x, const wwj & y){ return x += y; }
inline wwj operator - (wwj x, const wwj & y){ return x -= y; }

int n;

wwj wn[10];

inline void dft(wwj ** a, int type) {
	static wwj res[10];
	for(int i = 0;i < 10;++i) {
		res[i] = wwj(0, 0, 0, 0);
		for(int j = 9;j >= 0;--j) {
			res[i] = res[i] * wn[i] + *a[j];
		}
	}
	if(type) std::reverse(res + 1, res + 10);
	for(int i = 0;i < 10;++i) {
		*a[i] = res[i];
	}
}
inline void dft(wwj * a, int lim, int type) {
	wwj*buf[10];
	for(int mid = 1;mid < lim;mid *= 10) {
		for(int j = 0;j < lim;j += mid * 10) {
			for(int k = 0;k < mid;++k) {
				for(int l = 0;l < 10;++l) 
					buf[l] = a + j + k + mid * l;
				dft(buf, type);
			}
		}
	}
}
int main() {
	*wn = wwj(1, 0, 0, 0);
	wn[1] = wwj(0, 1, 0, 0);
	for(int i = 2;i < 10;++i) {
		wn[i] = wn[i - 1] * wn[1];
	}
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 0, x;i < n;++i) {
		cin >> x;
		a[x].a0 += 1;
	}
	dft(a, N, 0);
	for(int i = 0;i < N;++i) {
		a[i] = pow(a[i], n);
	}
	dft(a, N, 1);
	for(int i = 0;i < n;++i) {
		u64 res = a[i].a0 >> 5;
		cout << (res * i5 * i5 * i5 * i5 * i5 << 6 >> 6) << '\n';
	}
}