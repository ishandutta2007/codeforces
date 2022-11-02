#include <cstdio>
#include <algorithm>

using namespace std;

#define N 200200
#define M 2002000
typedef long long LL;

template <class T> void chkmax(T &x, T y) { if(x < y) x = y; }
template <class T> void chkmin(T &x, T y) { if(x > y) x = y; }

char ans[M];
int n, l, s[N], id[N];
LL t[N], x[N], y[N], G[N];
int p[2], f[2][M];
LL lo, hi;

bool cmp(int i, int j) { return s[i] < s[j]; }
inline LL _abs(LL a) { return a < 0 ? -a : a; }
inline LL calcl(LL x, LL y) { return x >= 0 ? (x + y - 1) / y : x / y; }
inline LL calcu(LL x, LL y) { return x >= 0 ? x / y : (x - y + 1) / y; }

bool update(LL a, LL b, LL c, LL d, int e) {
	if(a == b) {
		if(_abs(c-d) > e) return 0;
		return 1;
	}
	if(a > b) a ^= b ^= a ^= b, c ^= d ^= c ^= d;
	chkmax(lo, calcl(d - c - e, b - a)); chkmin(hi, calcu(d - c + e, b - a));
	return 1;
}

bool run(int k) {
	lo = -l; hi = l;
	for(int i = 1; i <= n; i ++) {
		int j = id[i-1], jj = id[i];
		if(!update(G[j], G[jj], x[j], x[jj], s[jj] - s[j])) return 0;
	}
	int j = 0, jj = 1;
	chkmax(lo, calcl(x[id[n]] - l + s[id[n]], G[id[n]] + 1)); chkmin(hi, calcl(x[id[n]] + l - s[id[n]], G[id[n]] + 1));
	if((lo&1) != (l&1)) lo ++;
	if((hi&1) != (l&1)) hi --;
	if(lo > hi) return 0;
	p[k] = lo;
	id[n+1] = n+1; G[n+1] = 0; x[n+1] = lo; s[n+1] = l;
	for(int i = 1; i <= n+1; i ++) {
		int j = id[i-1], jj = id[i];
		x[jj] -= G[jj] * lo;
		if(s[j] == s[jj]) continue;
		int t = (int)((x[jj] - x[j] + s[jj] + s[j]) >> 1);
		for(int r = s[j]; r < t; r ++) f[k][r] = 1;
		for(int r = t; r < s[jj]; r ++) f[k][r] = 0;
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &l);
	int ok = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%I64d %I64d %I64d\n", t + i, x + i, y + i);
		id[i] = i; x[i] += y[i]; y[i] = x[i] - y[i] * 2;
		if((t[i] & 1) != (x[i] & 1)) { puts("NO"); return 0; }
		G[i] = (t[i] - 1) / l; s[i] = (int)((t[i] - 1) % l) + 1;
	}
	sort(id + 1, id + n + 1, cmp);
	if(!run(0)) { puts("NO"); return 0;}
	for(int i = 1; i <= n; i ++) x[i] = y[i];
	if(!run(1)) { puts("NO"); return 0;}
	for(int i = 0; i < l; i ++) {
		if(f[0][i]) ans[i] = f[1][i] ? 'R' : 'U';
		else ans[i] = f[1][i] ? 'D' : 'L';
	}
	ans[l] = 0; puts(ans);
	return 0;
}