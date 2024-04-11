#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5, M = N * 20;
int t, q, n, m, shit = 'z' + 1, s[N];
char opt[N];
int sa[N], rk[N], ht[N], cnt[N], id[N], p;
int col[N], L[N], R[N], st[N], ed[N], f[N][21], len[N];
int rt[N], lc[M], rc[M], sum[M], tot;

inline void GetSA() {
	m = shit;
	for(int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
	for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	for(int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
	for(int w = 1; w < n && p < n; w <<= 1, m = p) {
		p = 0;
		for(int i = n; i > n - w; i--) id[++p] = i;
		for(int i = 1; i <= n; i++) if(sa[i] > w) id[++p] = sa[i] - w;
		for(int i = 1; i <= m; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) ++cnt[rk[i]];
		for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for(int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i], id[i] = 0;
		swap(id, rk);
		rk[sa[1]] = 1, p = 1;
		for(int i = 2; i <= n; i++)
			rk[sa[i]] = (id[sa[i]] == id[sa[i - 1]] && id[sa[i] + w] == id[sa[i - 1] + w])? p : ++p;
	}
}

inline void GetHeight() {
	for(int i = 1, k = 0; i <= n; i++) {
		if(k) --k;
		while(s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
		ht[rk[i]] = k;
	}
}

void ST_init() {
	for(register int i = 1; i <= n; i++) f[i][0] = ht[i];
	for(register int j = 1; j <= 20; j++) 
		for(register int i = 1; i + (1 << j) - 1 <= n; i++)
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int ST_query(int l, int r) {
	int len = (int)(1.0 * log(r - l + 1) / log(2));
	return min(f[l][len], f[r - (1 << len) + 1][len]);
}

int build(int l, int r) {
	int now = ++tot;
	if(l == r) return now;
	int mid = l + r >> 1;
	lc[now] = build(l, mid), rc[now] = build(mid + 1, r);
	return now;
}

int update(int u, int l, int r, int x) {
	int now = ++tot;
	lc[now] = lc[u], rc[now] = rc[u], sum[now] = sum[u] + 1;
	if(l == r) return now;
	int mid = l + r >> 1;
	if(x <= mid) lc[now] = update(lc[now], l, mid, x);
	else rc[now] = update(rc[now], mid + 1, r, x);
	return now;
}

int query(int u, int v, int l, int r, int a, int b) {
	if(a <= l && r <= b) return sum[v] - sum[u];
	int mid = l + r >> 1, res = 0;
	if(a <= mid) res += query(lc[u], lc[v], l, mid, a, b);
	if(b > mid) res += query(rc[u], rc[v], mid + 1, r, a, b);
	return res;
} 

signed main() {
	t = get(), q = get();
	for(int i = 1; i <= t; i++) {
		scanf("%s", opt + 1);
		len[i] = strlen(opt + 1), st[i] = n + 1;
		for(int j = 1; j <= len[i]; j++) s[++n] = opt[j], col[n] = i;
		ed[i] = n, s[++n] = shit++; 
	}
	GetSA();
	GetHeight();
	ST_init();
	for(int i = 1; i <= t; i++) {
		int u = rk[st[i]];
		int l = 1, r = u - 1; L[i] = u;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(ST_query(mid + 1, u) == len[i]) r = mid - 1, L[i] = mid;
			else l = mid + 1; 
		}
		l = u + 1, r = n, R[i] = u;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(ST_query(u + 1, mid) == len[i]) l = mid + 1, R[i] = mid;
			else r = mid - 1; 
		}
	}
	for(int i = 1; i <= n; i++) rt[i] = update(rt[i - 1], 1, n, rk[i]);
	while(q--) {
		int l = get(), r = get(), k = get();
		printf("%d\n", query(rt[st[l] - 1], rt[ed[r]], 1, n, L[k], R[k]));
	}
	return 0;
}

/*
2 1
a
abab
1 2 1
*/