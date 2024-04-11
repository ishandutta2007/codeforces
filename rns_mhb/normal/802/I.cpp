#include <bits/stdc++.h>
using namespace std;

#define N 101010

int sa[N], rnk[N], lcp[N], cnt[N];

void build(char *s) {
	int n = strlen(s) + 1, m = 256;
	int *x = rnk, *y = lcp, *z;
	for (int i = 0; i < m; i ++) cnt[i] = 0;
	for (int i = 0; i < n; i ++) cnt[x[i]=s[i]] ++;
	for (int i = 1; i < m; i ++) cnt[i] += cnt[i-1];
	for (int i = n - 1; i >= 0; i --) sa[--cnt[x[i]]] = i;
	for (int j = 1, p = 1; p < n; j <<= 1, m = p) {
		p = 0;
		for (int i = n - j; i < n; i ++) y[p++] = i;
		for (int i = 0; i < n; i ++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (int i = 0; i < m; i ++) cnt[i] = 0;
		for (int i = 0; i < n; i ++) cnt[x[i]] ++;
		for (int i = 1; i < m; i ++) cnt[i] += cnt[i-1];
		for (int i = n - 1; i >= 0; i --) sa[--cnt[x[y[i]]]] = y[i];
		z = x, x = y, y = z;
		x[sa[0]] = 0, p = 1;
		for (int i = 1; i < n; i ++) {
			x[sa[i]] = (y[sa[i]] == y[sa[i-1]] && y[sa[i]+j] == y[sa[i-1]+j]) ? p - 1 : p ++;
		}
	}
	for (int i = 0; i < n; i ++) rnk[sa[i]] = i;
	for (int i = 0, k = 0; i < n - 1; lcp[rnk[i++]] = k) {
		if (k) k --;
		for (int j = sa[rnk[i]-1]; s[i+k] == s[j+k]; k ++);
	}
}

char s[N];

int prv[N], nxt[N];

int main() {
	//freopen("r.in", "r", stdin);
	int T;
	scanf("%d\n", &T);
	while (T --) {
		gets(s);
		int n = strlen(s);
		build(s);
		long long rlt = 0;
		lcp[1] = 0, lcp[n+1] = 0;
		for (int i = 1; i <= n; i ++) rlt += n - sa[i] - max(lcp[i], lcp[i+1]);
		for (int i = 2, now; i <= n; i ++) {
			now = i - 1;
			while (now > 1 && lcp[i] <= lcp[now]) now = prv[now];
			prv[i] = now;
		}
		for (int i = n, now; i >= 2; i --) {
			now = i + 1;
			while (now <= n && lcp[i] < lcp[now]) now = nxt[now];
			nxt[i] = now;
		}
		for (int i = 2; i <= n; i ++) rlt += 1ll * (nxt[i] - prv[i]) * (nxt[i] - prv[i]) * (lcp[i] - max(lcp[prv[i]], lcp[nxt[i]]));
		printf("%I64d\n", rlt);
	}

	return 0;
}