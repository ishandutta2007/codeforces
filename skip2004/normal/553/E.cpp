#include<bits/stdc++.h>
typedef double db;
struct complex{
    db x,y;
    inline complex(db a = 0,db b = 0){ x = a,y = b; }
    inline complex operator * (const complex & b) const { return complex(x * b.x - y * b.y, x * b.y + y * b.x); }
	inline void operator += (const complex & b) { x += b.x, y += b.y; }
	inline complex operator - (const complex & b) const { return complex(x - b.x, y - b.y); }
    inline void operator /= (const int & lim) { x /= lim; }
};
struct istream
{
	static const int size = 1 << 24;
	char buf[size], *vin;
	inline istream()
	{
		fread(buf,1,size,stdin);
		vin = buf - 1;
	}
	inline istream& operator >> (int & x)
	{
		for(;isspace(*++vin););
		for(x = *vin & 15;isdigit(*++vin);) x = x * 10 + (*vin & 15);
		return * this;
	}
} cin;
const db pi = std::acos(-1);
const int maxn = 1 << 15;
complex wn[maxn << 1];
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
int n, m, t, x;
int p[110][maxn];
int suf[110][maxn];
int a[maxn], b[maxn], c[maxn], mincost[maxn];
db ans[51][maxn];
db sum[110][maxn];
int dis[60][60];
complex g0[maxn], g1[maxn];
inline void solve(int l,int r) {
	if(l == r) {
		for(int i = 1;i < n;++i) ans[i][l] = 1./0;
		for(int i = 0;i < m;++i)
			ans[a[i]][l] = std::min(ans[a[i]][l], sum[i][l] + suf[i][t - l + 1] / 100000. * mincost[b[i]] + c[i]);
		return ;
	}
	int mid = l + r >> 1, len = r - l + 1;
	solve(mid + 1, r);
	init(len + r - mid);
	for(int i = 0;i < m;++i) {
		int to = b[i];
		for(int i = mid + 1;i <= r;++i) g0[i - mid - 1] = ans[to][i];
		for(int j = 1;j < len;++j) g1[j] = (db) p[i][len - j] / 100000;
		for(int i = r - mid;i < lim;++i) g0[i] = 0;
		for(int i = len;i < lim;++i) g1[i] = 0;
		fft(g0, 1), fft(g1, 1);
		for(int i = 0;i < lim;++i) g0[i] = g0[i] * g1[i];
		fft(g0, 0);
		for(int j = l;j <= mid;++j) sum[i][j] += g0[j + len - mid - 1].x;
	}
	solve(l, mid);
}
int main() {
	for(int mid = 1;mid < maxn;mid <<= 1) for(int i = 0;i < mid;++i)
		wn[mid + i] = complex(std::cos(pi * i / mid), std::sin(pi * i / mid));
	cin >> n >> m >> t >> x;
	for(int i = 1;i <= n;++i) for(int j = 1;j < i;++j) dis[i][j] = dis[j][i] = 1e9;
	for(int i = 0;i < m;++i) {
		cin >> a[i] >> b[i] >> c[i];
		dis[a[i]][b[i]] = std::min(dis[a[i]][b[i]], c[i]);
		for(int j = 1;j <= t;++j) cin >> p[i][j];
		for(int j = t;j >= 1;--j) suf[i][j] = suf[i][j + 1] + p[i][j];
	}
	for(int k = 1;k <= n;++k) for(int i = 1;i <= n;++i) for(int j = 1;j <= n;++j) dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
	for(int i = 1;i <= n;++i) mincost[i] = dis[i][n] + x;
	solve(0, t);
	printf("%.10lf\n", ans[1][0]);
}