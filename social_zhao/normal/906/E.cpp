#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5;
char tmps[N], tmpt[N], s[N];
int n, tmpn, f[N], pre[N], g[N], h[N];
vector<pair<int, int>> ans;

struct Node { int ch[26], len, fa, dif, trs; } st[N];
int tot, lst;

void init() {
	st[0].len = 0, st[0].fa = 1;
	st[1].len = -1, st[1].fa = 1;
	tot = 1, lst = 0;
}

int GetFail(int u, int n) {
	while(s[n] != s[n - st[u].len - 1]) 
		u = st[u].fa;
	return u;
}

void insert(int c, int n) {
	int p = GetFail(lst, n);
	if(!st[p].ch[c]) {
		++tot;
		st[tot].fa = st[GetFail(st[p].fa, n)].ch[c], st[tot].len = st[p].len + 2;
		st[tot].dif = st[tot].len - st[st[tot].fa].len;
		if(st[tot].dif == st[st[tot].fa].dif) st[tot].trs = st[st[tot].fa].trs;
		else st[tot].trs = st[tot].fa;
		st[p].ch[c] = tot, lst = tot;
	}
	else lst = st[p].ch[c];
}

int main() {
	scanf("%s", tmps + 1);
	scanf("%s", tmpt + 1);
	tmpn = strlen(tmps + 1);
	for(int i = 1; i <= tmpn; i++) s[++n] = tmps[i], s[++n] = tmpt[i];
	init();
	memset(f, 0x3f, sizeof(f)), memset(g, 0x3f, sizeof(g));
	f[0] = 0;
	for(int i = 1; i <= n; i++) {
		insert(s[i] - 'a', i);
		for(int x = lst; x > 1; x = st[x].trs) {
			g[x] = f[i - st[st[x].trs].len - st[x].dif], h[x] = i - st[st[x].trs].len - st[x].dif;
			if(st[x].dif == st[st[x].fa].dif) {
				if(g[st[x].fa] < g[x]) 
					g[x] = g[st[x].fa], h[x] = h[st[x].fa];
			}
			if(i % 2 == 0) {
				if(g[x] + 1 < f[i]) 
					f[i] = g[x] + 1, pre[i] = h[x];
			}
		}
		if(i % 2 == 0) { 
			if(f[i - 2] < f[i] && s[i - 1] == s[i]) f[i] = f[i - 2], pre[i] = i - 2;
		} 
	}
	if(f[n] > n) {
		cout << -1 << endl;
		return 0;
	}
	int now = n;
	while(now) {
		if(pre[now] != now - 2) ans.emplace_back(pre[now] / 2 + 1, now / 2);
		now = pre[now];
	}
	cout << ans.size() << endl;
	for(auto v : ans) cout << v.first << " " << v.second << endl;
	return 0;
}

/*
baabbababbbaabbbabbaaabbbbbbbaabbbabaabbbbbbaaabba
abbaabbabbbabbbabaaabbabbbbbaabbbbabbbbaabbbaaabba
*/