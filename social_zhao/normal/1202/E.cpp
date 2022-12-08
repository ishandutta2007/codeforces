#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
char t[N], s[N];
int n, len, pre[N], suf[N];

struct ACAM {
	int ch[N][26], tot = 0, fail[N], vis[N];
	vector<int> son[N];
	
	void insert(char *s) {
		int len = strlen(s + 1), u = 0;
		for(int i = 1; i <= len; i++) {
			int c = s[i] - 'a';
			if(!ch[u][c]) ch[u][c] = ++tot;
			u = ch[u][c];
		}
		vis[u]++;
	}
	
	void dfs(int u) {
		if(u) vis[u] += vis[fail[u]];
		for(auto v : son[u]) dfs(v);
	}
	
	void GetFail() {
		queue<int> q;
		for(int i = 0; i < 26; i++) if(ch[0][i]) q.push(ch[0][i]);
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int i = 0; i < 26; i++) {
				if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
				else ch[u][i] = ch[fail[u]][i];
			}
		}
		for(int i = 1; i <= tot; i++) son[fail[i]].push_back(i);
		dfs(0);
	}
} ber, der;

main() {
	scanf("%s", t + 1), len = strlen(t + 1);
	n = get();
	for(int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		int lens = strlen(s + 1);
		ber.insert(s), reverse(s + 1, s + 1 + lens), der.insert(s);
	}
	ber.GetFail(), der.GetFail();
	int u = 0;
	for(int i = 1; i <= len; i++) {
		int c = t[i] - 'a';
		u = ber.ch[u][c];
		pre[i] = ber.vis[u];
	}
	u = 0;
	for(int i = 1; i <= len; i++) {
		int c = t[len - i + 1] - 'a';
		u = der.ch[u][c];
		suf[len - i + 1] = der.vis[u];
	}
	int ans = 0;
	for(int i = 1; i < len; i++) ans += pre[i] * suf[i + 1];
	printf("%lld\n", ans);
	return 0;
}