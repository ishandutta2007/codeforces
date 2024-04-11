#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 22;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

int n, ans, cc, a[N][N], b[N][N], c[N][N];
int tt, ss, va[N], vb[N], suf[N], hh[N];
int delta, slk[N], A[N], B[N], match[N];
int p[N], z[N];

bool findm(int x) {
	va[x] = tt;
	for(int i = 1; i <= n; i++) if(vb[z[i]] != tt){
		int y = z[i];
		if(A[x] + B[y] == c[x][y]) {
			vb[y] = tt;
			if(!match[y] || findm(match[y])) {
				match[y] = x;
				return 1;
			}
		} else slk[y] = _min(slk[y], A[x] + B[y] - c[x][y]);
	} return 0;
}

void dfs(int k, int s1, int s2) {
	if(k == n + 1) {ans = _max(ans, cc); return ;}
	if(cc + suf[k] <= ans) return ;
	if(clock() > 300) return ;
	if(s1 < n / 2 && s2 < n / 2) {
		int oA[N], oB[N], omatch[N], occ = cc;
		for(int i = 1; i <= n; i++) oA[i] = A[i], oB[i] = B[i], omatch[i] = match[i];
		int x = p[k];
		A[x] = -999999999;
		for(int j = 1; j <= n; j++) c[x][j] = a[x][j], A[x] = _max(A[x], c[x][j]), va[j] = vb[j] = 0;
		cc += A[x];
		tt = 0;
		while(1) {
			for(int j = 1; j <= n; j++) slk[j] = 999999999;
			tt++, delta = 999999999;
			if(findm(x)) break;
			for(int j = 1; j <= n; j++) if(!vb[j]) delta = _min(delta, slk[j]);
			for(int j = 1; j <= n; j++) {
				if(va[j] == tt) A[j] -= delta;
				if(vb[j] == tt) B[j] += delta;
			} cc -= delta;
		} dfs(k + 1, s1 + 1, s2);
		for(int i = 1; i <= n; i++) A[i] = oA[i], B[i] = oB[i], match[i] = omatch[i];
		cc = occ;
		A[x] = -999999999;
		for(int j = 1; j <= n; j++) c[x][j] = b[x][j], A[x] = _max(A[x], c[x][j]), va[j] = vb[j] = 0;
		cc += A[x];
		tt = 0;
		while(1) {
			for(int j = 1; j <= n; j++) slk[j] = 999999999;
			tt++, delta = 999999999;
			if(findm(x)) break;
			for(int j = 1; j <= n; j++) if(!vb[j]) delta = _min(delta, slk[j]);
			for(int j = 1; j <= n; j++) {
				if(va[j] == tt) A[j] -= delta;
				if(vb[j] == tt) B[j] += delta;
			} cc -= delta;
		} dfs(k + 1, s1, s2 + 1);
	} else if(s1 < n / 2) {
		int x = p[k];
		A[x] = -999999999;
		for(int j = 1; j <= n; j++) c[x][j] = a[x][j], A[x] = _max(A[x], c[x][j]), va[j] = vb[j] = 0;
		cc += A[x];
		tt = 0;
		while(1) {
			for(int j = 1; j <= n; j++) slk[j] = 999999999;
			tt++, delta = 999999999;
			if(findm(x)) break;
			for(int j = 1; j <= n; j++) if(!vb[j]) delta = _min(delta, slk[j]);
			for(int j = 1; j <= n; j++) {
				if(va[j] == tt) A[j] -= delta;
				if(vb[j] == tt) B[j] += delta;
			} cc -= delta;
		} dfs(k + 1, s1 + 1, s2);
	} else if(s2 < n / 2) {
		int x = p[k];
		A[x] = -999999999;
		for(int j = 1; j <= n; j++) c[x][j] = b[x][j], A[x] = _max(A[x], c[x][j]), va[j] = vb[j] = 0;
		cc += A[x];
		tt = 0;
		while(1) {
			for(int j = 1; j <= n; j++) slk[j] = 999999999;
			tt++, delta = 999999999;
			if(findm(x)) break;
			for(int j = 1; j <= n; j++) if(!vb[j]) delta = _min(delta, slk[j]);
			for(int j = 1; j <= n; j++) {
				if(va[j] == tt) A[j] -= delta;
				if(vb[j] == tt) B[j] += delta;
			} cc -= delta;
		} dfs(k + 1, s1, s2 + 1);
	}
}

int main() {
	n = read();
	for(int i = 1; i <= n; i++) p[i] = z[i] = i;
	random_shuffle(p + 1, p + n + 1), random_shuffle(z + 1, z + n + 1);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) a[i][j] = read(), hh[i] = _max(hh[i], a[i][j]);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) b[i][j] = read(), hh[i] = _max(hh[i], b[i][j]);
	for(int i = 1; i <= n; i++) suf[i] = hh[p[i]];
	for(int i = n; i >= 1; i--) suf[i] += suf[i + 1];
	dfs(1, 0, 0);
	put(ans), puts("");
	return 0;
}