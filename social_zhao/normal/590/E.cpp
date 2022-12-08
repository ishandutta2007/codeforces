#include<bits/stdc++.h>
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int M = 1e7 + 5, N = 1005;
int n, lst[M], pos[M], ch[M][2], fail[M], tot = 1, vis[N], ed[M];
char opt[M];
int f[N][N], st[M], top, bel[N], tim, bin[N], cnt;

void insert(char *s, int id) {
    int len = strlen(s + 1), u = 1;
    for(int i = 1; i <= len; i++) {
        int c = s[i] - 'a';
        if(!ch[u][c]) ch[u][c] = ++tot;
        lst[ch[u][c]] = u, u = ch[u][c];
    }
    pos[id] = u, ed[u] = id;
}

void GetFail() {
    queue<int> q;
    for(int i = 0; i < 2; i++) 
		if(ch[1][i]) fail[ch[1][i]] = 1, q.push(ch[1][i]);
		else ch[1][i] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < 2; i++) {
            if(!ch[u][i]) ch[u][i] = ch[fail[u]][i];
            else fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
        }
    }
}

int dfs(int u) {
	for(int v = 1; v <= n; v++) {
		if(f[u][v] && vis[v] != tim) {
			vis[v] = tim;
			if(!bel[v] || dfs(bel[v])) { bel[v] = u; return 1; }
		}
	}
	return 0;
}

int main() {
    n = get();
    for(int i = 1; i <= n; i++) scanf("%s", opt + 1), insert(opt, i);
    GetFail();
    ed[1] = -1;
    for(int i = 1; i <= n; i++) {
    	for(int j = pos[i]; j != 1; j = lst[j]) {
    		int now = fail[j];
    		while(!ed[now]) st[++top] = now, now = fail[now];
    		while(top) fail[st[top]] = now, top--;
    		fail[j] = now;
    		if(j != pos[i] && ed[j]) now = j;
    		if(now != 1) f[i][ed[now]] = 1;
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] |= f[i][k] & f[k][j];
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	int ans = n;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) 
		tim = i, ans -= dfs(i);
	printf("%d\n", ans);
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) vis[bel[i]] = 1;
	for(int i = 1; i <= n; i++) if(!vis[i]) bin[++cnt] = i;
	memset(vis, 0, sizeof(vis));
	while(1) {
		for(int i = 1; i <= cnt; i++)
			for(int j = 1; j <= n; j++)
				vis[j] |= f[bin[i]][j];
		int flag = 1;
		for(int i = 1; i <= cnt; i++) 
			while(vis[bin[i]]) flag = 0, bin[i] = bel[bin[i]];
		if(flag) break;
	}
	for(int i = 1; i <= cnt; i++) printf("%d ", bin[i]);
    return 0;
}