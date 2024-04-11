#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005, S = 13800;
char s[N];
int n, x, a[N];
int ch[S][10], fail[S], vis[S], tot;
int f[N][S];

void insert(int len) {
	int u = 0;
	for(int i = 1; i <= len; i++) {
		int c = a[i];
		if(!ch[u][c]) ch[u][c] = ++tot;
		u = ch[u][c];
	}
	vis[u] = 1;
}

void GetFail() {
	queue<int> q;
	for(int i = 1; i <= 9; i++) if(ch[0][i]) q.push(ch[0][i]);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = 1; i <= 9; i++) {
			if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
			else ch[u][i] = ch[fail[u]][i];
		}
	}
}

int chk(int n) {
	for(int l = 1; l <= n; l++) {
		int now = 0;
		for(int r = l; r <= n; r++) {
			now += a[r];
			if(now != x && x % now == 0) return 0;
		}
	}
	return 1;
}

void GetStr(int dep, int sum) {
	if(sum >= x) {
		if(sum > x) return;
		if(chk(dep - 1)) insert(dep - 1);
	}
	for(int i = 1; i <= 9; i++) a[dep] = i, GetStr(dep + 1, sum + i);
}

int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	x = get();
	GetStr(1, 0);
	GetFail();
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= tot; j++) {
			if(vis[j]) continue;
			f[i][j] = min(f[i][j], f[i - 1][j] + 1);
			f[i][ch[j][s[i] - '0']] = min(f[i][ch[j][s[i] - '0']], f[i - 1][j]);
		}
	}
	int ans = 0x3f3f3f3f;
	for(int i = 0; i <= tot; i++) 
		if(!vis[i]) ans = min(ans, f[n][i]);
	cout << ans;
	return 0;
}