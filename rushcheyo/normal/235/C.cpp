#include <bits/stdc++.h>
using namespace std;

const int L = 1000005;
int tot = 1, st = 1, lst = 1, ch[2*L][26], nxt[2*L], ma[2*L], cnt[2*L], b[L], q[2*L], vis[2*L];
char s[L], x[L];

void extend(int c) {
	int u = ++tot, v = lst;
	ma[u] = ma[lst] + 1, cnt[u] = 1;
	for (; v && !ch[v][c]; v = nxt[v]) ch[v][c] = u;
	if (!v) nxt[u] = st;
	else if (ma[ch[v][c]] == ma[v] + 1) nxt[u] = ch[v][c];
	else {
		int n = ++tot, o = ch[v][c];
		ma[n] = ma[v] + 1;
		for (int i = 0; i < 26; i++) ch[n][i] = ch[o][i];
		nxt[n] = nxt[o];
		nxt[o] = nxt[u] = n;
		for (; v && ch[v][c] == o; v = nxt[v]) ch[v][c] = n;
	}
	lst = u;
}

void getcnt() {
	for (int i = 1; i <= tot; i++) b[ma[i]]++;
	for (int i = 1; i <= ma[lst]; i++) b[i] += b[i - 1];
	for (int i = 1; i <= tot; i++) q[--b[ma[i]]] = i;
	for (int i = tot - 1; i; i--) cnt[nxt[q[i]]] += cnt[q[i]];
}

int main() {
	scanf("%s", s + 1);
	for (int i = 1; s[i]; i++) extend(s[i] - 'a');
	getcnt();
	int nq;
	scanf("%d", &nq);
	while (nq--) {
		scanf("%s", x + 1);
		int l = strlen(x + 1);
		for (int i = 1; i <= l; i++) x[i + l] = x[i];
		int u = st, ans = 0, m = 0;
		for (int i = 1; i <= 2 * l; i++) {
			if (ch[u][x[i] - 'a']) m++, u = ch[u][x[i] - 'a'];
			else {
				while (u && !ch[u][x[i] - 'a']) u = nxt[u];
				if (!u) u = st, m = 0;
				else m = ma[u] + 1, u = ch[u][x[i] - 'a'];
			}
			if (i > l && m >= l) {
				int v = u;
				while (v && !(l >= ma[nxt[v]] + 1 && l <= ma[v])) v = nxt[v];
				if (!v) v = st;
				if (vis[v] != nq + 1) ans += cnt[v], vis[v] = nq + 1;
			}
		}
		printf("%d\n", ans);
	}
}