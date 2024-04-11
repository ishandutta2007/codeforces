#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 10005;
int n, m;
char s[N];
int sa[N], rk[N], cnt[N], id[N], p, ht[N], f[N], mn[N][19];

void clear(int n) {
	for(int i = 1; i <= n; i++) sa[i] = rk[i] = cnt[i] = id[i] = ht[i] = f[i] = 0;
	p = 0;
}

void BuildSA() {
	m = 300;
	for(int i = 0; i <= m; i++) cnt[i] = 0;
	for(int i = 1; i <= n; i++) ++cnt[rk[i] = s[i]];
	for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
	for(int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
	for(int w = 1; w < n && p < n; w <<= 1, m = p) {
		p = 0;
		for(int i = n - w + 1; i <= n; i++) id[++p] = i;
		for(int i = 1; i <= n; i++) if(sa[i] > w) id[++p] = sa[i] - w;
		for(int i = 1; i <= m; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) ++cnt[rk[i]];
		for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
		for(int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i], id[i] = 0;
		swap(id, rk), rk[sa[1]] = p = 1;
		for(int i = 2; i <= n; i++)
			rk[sa[i]] = (id[sa[i]] == id[sa[i - 1]] && id[sa[i] + w] == id[sa[i - 1] + w])? p : ++p;
	}
	for(int i = 1, k = 0; i <= n; i++) {
		if(k) --k;
		while(s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
		ht[rk[i]] = k;
	}
	for(int i = 1; i <= n; i++) mn[i][0] = ht[i];
	for(int j = 1; j < 18; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++) 
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
}

int STQuery(int l, int r) {
	int len = (int)log2(r - l + 1);
	return min(mn[l][len], mn[r - (1 << len) + 1][len]);
}

int lcp(int x, int y) {
	int l = rk[x], r = rk[y];
	if(l > r) swap(l, r);
	return STQuery(l + 1, r);
}

void solve() {
	clear(n);
	n = get();
	scanf("%s", s + 1);
	BuildSA();
	for(int i = 1; i <= n; i++) f[i] = 0;
	f[1] = n;
	int ans = n;
	for(int i = 2; i <= n; i++) {
		f[i] = n - i + 1;
		for(int j = 1; j < i; j++) if(rk[j] < rk[i]) f[i] = max(f[i], f[j] + n - (i + lcp(i, j)) + 1);
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
8
acabacba
*/