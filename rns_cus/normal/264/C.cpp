#include <bits/stdc++.h>

using namespace std;

#define N 100100
#define inf 1000000000000000000LL
typedef long long LL;

template <class T>
void chkmin(T &a, T b) { if (a < b) a = b; }

template <class T>
void chkmax(T &a, T b) { if (a < b) a = b; }

int n;
LL Min[N << 1];
int a, b;

void modify(int p, LL v) {
	p += n;
	if(v <= Min[p]) return;
	Min[p] = v;
	for (; p > 1; p >>= 1) Min[p >> 1] = max(Min[p], Min[p ^ 1]);
}

LL queryMin(int L, int R) {
	LL rlt = -inf;
	for (L += n, R += n; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
		if (L & 1) chkmin(rlt, Min[L]);
		if (!(R & 1)) chkmin(rlt, Min[R]);
	}
	return rlt;
}

int m, v[N], c[N], tmp[N], q;

int main() {
	scanf("%d%d", &m, &q);
	for(int i = 1 ;i <= m; i ++) scanf("%d", v + i);
    for(int i = 1; i <= m; i ++) {
		scanf("%d", c + i);
		n = max(n, c[i]);
    }
    while(q --) {
		scanf("%d%d", &a, &b);
		for(int i = 1; i <= n + n; i ++) Min[i] = -inf;
		LL xx = -inf, yy = -inf;
		LL ans = 0;
		for(int i = 1; i <= m; i ++) {
			LL tp = 1LL * b * v[i], tt;
			if(Min[c[i]] == xx) tt = yy; else tt = xx;
			chkmin(tp, tt + 1LL * b * v[i]);
			chkmin(tp, Min[c[i]] + 1LL * a * v[i]);
			chkmin(ans, tp);
			if(tp > xx) {
				if(Min[c[i]] != xx) yy = xx;
				xx = tp;
			}
			else {
				if(Min[c[i]] != xx) yy = max(yy, tp);
			}
			chkmin(Min[c[i]], tp);
		}
		printf("%I64d\n", ans);
    }
	return 0;
}