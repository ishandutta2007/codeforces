#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e6 + 5;
char s[N];
int n, len, pre[N], suf[N], lg[N];
int f[N][22];
int m, sa[N], rk[N], cnt[N], id[N], p;

void Build() {
	lg[0] = -1;
	for(int i = 1; i <= n; i++) f[i][0] = pre[len] >= 0? pre[i] : suf[i], lg[i] = lg[i >> 1] + 1;
	for(int j = 1; j <= 21; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	int len = lg[r - l + 1];
	return min(f[l][len], f[r - (1 << len) + 1][len]);
}

void GetSA() {
    m = 300;
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
}

int main() {
	scanf("%s", s + 1), len = n = strlen(s + 1);
	for(int i = 1; i <= n; i++) s[i + n] = s[i];
	n *= 2;
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (s[i] == '('? 1 : -1);
	for(int i = n; i >= 1; i--) suf[i] = suf[i + 1] + (s[i] == '('? -1 : 1);
	Build(); 
	int lft = 0, rht = 0;
	if(pre[len] > 0) rht = pre[len];
	if(pre[len] < 0) lft = -pre[len];
	GetSA();
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int pos = sa[i];
		if(pos > len) continue;
		int l = pos, r = pos + len - 1;
		int mn = query(l, r);
		if(pre[len] > 0 && mn - pre[l - 1] >= 0) { ans = l; break; }
		if(pre[len] < 0 && mn - suf[r + 1] >= 0) { ans = l; break; }
		if(pre[len] == 0 && mn - pre[l - 1] >= 0) { ans = l; break; }
	}
	for(int i = 1; i <= lft; i++) printf("(");
	for(int i = ans; i <= ans + len - 1; i++) printf("%c", s[i]);
	for(int i = 1; i <= rht; i++) printf(")");
	return 0;
}