#include <bits/stdc++.h>

#define L 500100
#define Min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int tmps[L], wv[L], tx[L], ty[L];

inline int cmp(int *r, int a, int b, int l) {
	return r[a] == r[b] && r[a + l] == r[b + l];
}

void suffixArray(int *r, int *sa, int n, int m) {
	int *x = tx, *y = ty;
	for (int i = 0; i < m; i ++) tmps[i] = 0;
	for (int i = 0; i < n; i ++) tmps[x[i] = r[i]] ++;
	for (int i = 1; i < m; i ++) tmps[i] += tmps[i - 1];
	for (int i = n - 1; i >= 0;i --) sa[-- tmps[x[i]]] = i;
	for (int j = 1, p = 1; p < n; j <<= 1, m = p) {
		p = 0;
		for (int i = n - j; i < n; i ++) y[p ++] = i;
		for (int i = 0; i < n; i ++)
			if (sa[i] >= j) y[p ++] = sa[i] - j;
		for (int i = 0; i < n; i ++)
			wv[i] = x[y[i]];
		for (int i = 0; i < m; i ++)
			tmps[i] = 0;
		for (int i = 0; i < n; i ++)
			tmps[wv[i]] ++;
		for (int i = 1; i < m; i ++)
			tmps[i] += tmps[i - 1];
		for (int i = n - 1; i >= 0; i --)
			sa[-- tmps[wv[i]]] = y[i];
		swap(x, y), p = 1, x[sa[0]] = 0;
		for (int i = 1; i < n; i ++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p ++;
	}
}

int rnk[L], lcp[L];
int r[L], sa[L];

void calc_lcp(int *r, int *sa, int n) {
	lcp[0] = 0;
	for (int i = 0; i < n; i ++)
		rnk[sa[i]] = i;
	for (int h = 0, i = 0; i < n; i ++) if (rnk[i] > 0) {
		int j = sa[rnk[i] - 1];
		while (r[i + h] == r[j + h])
			h ++;
		lcp[rnk[i]] = h;
		if (h > 0) h --;
	}
}

char s[L];
int length, _s[L];
int f[20][L], gg[20][L];
#define INF 1e9

int calc(int k) {
    int t = _s[k] - 1, i;
    for(i = 18; i >= 0; i --)
    	if(f[i][k] >= t) break;
    int x = k + (1<<i);
    while(i >= 0 && x < length) {
        if(f[i][x] >= t) {
            x += (1<<i);
        } else i --;
    }
    x --;
    if(x >= length) x = length - 1;
    return x;
}

int doit(int k, int x) {
    if(x < k) return 0;
    int t = _s[k] - 1;
    int i;
    for(i = 18; i >= 0; i --)
    	if(k - 1 + (1<<i) <= x) break;
    int rt = 0;
    if(f[i][k] == t) rt += gg[i][k];
    int y = k + (1<<i);
    while(i >= 0 && y <= x) {
        if(y - 1 + (1<<i) <= x) {
            if(f[i][y] == t) rt += gg[i][y];
            y += (1<<i);
        } else i --;
    }
    return rt;
}

void run() {
    _s[0] = s[0] == '(' ? 1 : -1;
    for(int i = 1; i < length; i ++) _s[i] = _s[i-1] + (s[i] == '(' ? 1 : -1);
    for(int i = 0; i < length; i ++) f[0][i] = _s[i], gg[0][i] = 1;
    for(int j = 1; j < 19; j ++) {
        for(int i = 0; i < length; i ++) {
            f[j][i] = f[j-1][i]; gg[j][i] = gg[j-1][i];
            if((1<<j-1) < length - i) {
                if(f[j][i] == f[j-1][i + (1<<j-1)]) gg[j][i] += gg[j-1][i+(1<<j-1)];
                else if(f[j][i] > f[j-1][i+(1<<j-1)]) {
                    f[j][i] = f[j-1][i+(1<<j-1)]; gg[j][i] = gg[j-1][i+(1<<j-1)];
                }
            }
        }
    }
    long long ans = 0;
    for(int i = 1; i <= length; i ++) {
        int k = sa[i];
        if(s[k] == ')') break;
        int t = calc(k);
        int x = lcp[i];
        if(t - k + 1 <= x) continue;
        ans += doit(k, t) - doit(k, k + x - 1);
    }
    printf("%I64d\n", ans);
}

int main() {

	scanf("%d", &length); gets(s);
	gets(s);
	s[length] = 0;
	for (int i = 0; i <= length; i ++) r[i] = (s[i] == '(' ? 1 : 2);
	r[length] = 0;
	suffixArray(r, sa, length + 1, 3);
	calc_lcp(r, sa, length + 1);
	run();
    return 0;
}