#include <bits/stdc++.h>

#define L 500100
#define Min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int wws[L], wv[L], tmpx[L], tmpy[L];

inline int cmp(int *r, int a, int b, int l) { return r[a] == r[b] && r[a + l] == r[b + l]; }

void da(int *r, int *sa, int n, int m) {
	int *x = tmpx, *y = tmpy;
	for (int i = 0; i < m; i ++) wws[i] = 0;
	for (int i = 0; i < n; i ++) wws[x[i] = r[i]] ++;
	for (int i = 1; i < m; i ++) wws[i] += wws[i - 1];
	for (int i = n - 1; i >= 0;i --) sa[-- wws[x[i]]] = i;
	for (int j = 1, p = 1; p < n; j <<= 1, m = p) {
		p = 0;
		for (int i = n - j; i < n; i ++) y[p ++] = i;
		for (int i = 0; i < n; i ++) if (sa[i] >= j) y[p ++] = sa[i] - j;
		for (int i = 0; i < n; i ++) wv[i] = x[y[i]];
		for (int i = 0; i < m; i ++) wws[i] = 0;
		for (int i = 0; i < n; i ++) wws[wv[i]] ++;
		for (int i = 1; i < m; i ++) wws[i] += wws[i - 1];
		for (int i = n - 1; i >= 0; i --) sa[-- wws[wv[i]]] = y[i];
		swap(x, y), p = 1, x[sa[0]] = 0;
		for (int i = 1; i < n; i ++) x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p ++;
	}
}

int rnk[L], lcp[L];
int r[L], sa[L];

void calc_lcp(int *r, int *sa, int n) {
	lcp[0] = 0;
	for (int i = 0; i < n; i ++) rnk[sa[i]] = i;
	for (int h = 0, i = 0; i < n; i ++) if (rnk[i] > 0) {
		int j = sa[rnk[i] - 1];
		while (r[i + h] == r[j + h]) h ++;
		lcp[rnk[i]] = h;
		if (h > 0) h --;
	}
}

char s[L];
int len, sum[L];
int f[20][L], g[20][L];
#define oo 1e9

int calc(int k) {
    int t = sum[k] - 1, i;
    for(i = 18; i >= 0; i --) if(f[i][k] >= t) break;
    int x = k + (1<<i);
    while(i >= 0 && x < len) {
        if(f[i][x] >= t) {
            x += (1<<i);
        } else i --;
    }
    x --;
    if(x >= len) x = len - 1;
    return x;
}

int gg(int k, int x) {
    if(x < k) return 0;
    int t = sum[k] - 1;
    int i;
    for(i = 18; i >= 0; i --) if(k + (1<<i) - 1 <= x) break;
    int rt = 0;
    if(f[i][k] == t) rt += g[i][k];
    int y = k + (1<<i);
    while(i >= 0 && y <= x) {
        if(y + (1<<i) - 1 <= x) {
            if(f[i][y] == t) rt += g[i][y];
            y += (1<<i);
        } else i --;
    }
    return rt;
}

void run() {
    sum[0] = s[0] == '(' ? 1 : -1;
    for(int i = 1; i < len; i ++) sum[i] = sum[i-1] + (s[i] == '(' ? 1 : -1);
    for(int i = 0; i < len; i ++) f[0][i] = sum[i], g[0][i] = 1;
    for(int j = 1; j < 19; j ++) {
        for(int i = 0; i < len; i ++) {
            f[j][i] = f[j-1][i]; g[j][i] = g[j-1][i];
            if(i + (1<<j-1) < len) {
                if(f[j][i] == f[j-1][i + (1<<j-1)]) g[j][i] += g[j-1][i+(1<<j-1)];
                else if(f[j][i] > f[j-1][i+(1<<j-1)]) {
                    f[j][i] = f[j-1][i+(1<<j-1)]; g[j][i] = g[j-1][i+(1<<j-1)];
                }
            }
        }
    }
    long long ans = 0;
    for(int i = 1; i <= len; i ++) {
        int k = sa[i];
        if(s[k] == ')') break;
        int t = calc(k);
        int x = lcp[i];
        //printf("%d %d %s\n", k, lcp[i-1], s + k);
        if(t - k + 1 <= x) continue;
        ans += gg(k, t) - gg(k, k + x - 1);
    }
    printf("%I64d\n", ans);
}

int main() {
    //freopen("in.txt","r",stdin);

	scanf("%d", &len); gets(s);
	gets(s);
	s[len] = 0;
	for (int i = 0; i <= len; i ++) r[i] = (s[i] == '(' ? 1 : 2);
	r[len] = 0;
	da(r, sa, len + 1, 3);
	calc_lcp(r, sa, len + 1);
	run();
    return 0;
}