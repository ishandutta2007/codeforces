#include<bits/stdc++.h>
using std::cin;
using std::cout;
typedef long double db;
int n, k;
const int N = 600;
const int maxn = 1 << 17;
db dp[2][N];
db p[100100];

const db pi = std::acos(-1);
struct complex{
    db x,y;
    inline complex(db a = 0,db b = 0){ x = a,y = b; }
    inline complex operator * (const complex & b) const { return complex(x * b.x - y * b.y, x * b.y + y * b.x); }
	inline void operator += (const complex & b) { x += b.x, y += b.y; }
	inline complex operator - (const complex & b) const { return complex(x - b.x, y - b.y); }
    inline void operator /= (const int & lim) { x /= lim; }
};
complex wn[maxn << 1];
complex g[maxn];
inline complex pow(complex x, int b) {
	complex ans = 1;
	for(;b;b >>= 1, x = x * x) if(b & 1)
		ans = ans * x;
	return ans;
}
int rev[maxn], lim;
inline void init(int len) {
	for(lim = 1;lim < len;lim <<= 1);
	for(int i = 1;i < lim;++i) rev[i] = rev[i >> 1] >> 1 | (i % 2 * lim / 2);
}
inline void fft(complex * a,int type) {
	for(int i = 1;i < lim;++i) if(rev[i] > i) std::swap(a[i], a[rev[i]]);
	for(int mid = 1;mid < lim;mid <<= 1) for(int j = 0;j < lim;j += mid + mid) for(int k = 0;k < mid;++k) {
		const complex x = a[mid + j + k] * wn[mid + k];
		a[mid + j + k].x = a[j + k].x - x.x;
		a[mid + j + k].y = a[j + k].y - x.y;
		a[j + k] += x;
	}
	if(!type) {
		std::reverse(a + 1,a + lim);
		for(int i = 0;i < lim;++i) a[i] /= lim;
	}
}

int main(){
	cin >> n >> k;
	init(n + 1);
	g[0] = (k - 1.) / k;
	g[1] = 1. / k ;
	for(int mid = 1;mid < lim;mid <<= 1) for(int i = 0;i < mid;++i)
		wn[mid + i] = complex(std::cos(pi * i / mid), std::sin(pi * i / mid));
	fft(g, 1);
	for(int i = 0;i < lim;++i) g[i] = pow(g[i], n);
	fft(g, 0);
	dp[1][1] = 1;
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j < N;++j) dp[0][j] = dp[1][j], dp[1][j] = 0;
		p[i] = p[i - 1];
		for(int j = 1;j + 1 < N;++j) {
			p[i] += dp[0][j] * j / (j + 1.);
			p[i] += dp[0][j] * j / 2;
			dp[1][j] += dp[0][j] * j / (j + 1.);
			dp[1][j + 1] += dp[0][j] / (j + 1.);
		}
	}
	db ans = 0, su = 0;
	for(int i = 0;i <= n;++i) {
		ans += g[i].x * p[i];
		su += g[i].x;
	}
	printf("%.20Lf\n", ans * k);
}