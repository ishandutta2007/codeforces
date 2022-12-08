#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1005, M = N * 51, P = 1e9 + 7;
char s[N], x[N], y[N];
int n, d, ch[M][10], tag[M], tot = 1, fail[M];
int f[55][M][2], g[55][2];

void insert(char *st, char *ed) {
	int u = 1;
	for(char* p = st; p != ed; p++) {
		int c = *p - '0';
		if(!ch[u][c]) ch[u][c] = ++tot;
		u = ch[u][c];
	}
	tag[u] = 1;
}

void build() {
	queue<int> q;
	for(int i = 0; i < 10; i++) 
		if(ch[1][i]) q.push(ch[1][i]), fail[ch[1][i]] = 1; else ch[1][i] = 1;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < 10; i++) 
			if(ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
			else ch[u][i] = ch[fail[u]][i];
	}
}

int solve(char *t) {
	g[d + 1][0] = g[d + 1][1] = 1;
	for(int i = d; i; i--) 
		g[i][0] = g[i + 1][0] * 10 % P, g[i][1] = (g[i + 1][0] * (t[i] - '0') + g[i + 1][1]) % P;
	for(int i = 1; i <= d; i++)
		for(int j = 1; j <= tot; j++)
			f[i][j][0] = f[i][j][1] = 0;
	f[0][1][1] = 1;
	for(int i = 0; i < d; i++)
		for(int j = 1; j <= tot; j++)
			if(!tag[j]) {
				for(int k = 0; k < 10; k++) {
					f[i + 1][ch[j][k]][0] = (f[i + 1][ch[j][k]][0] + f[i][j][0]) % P;
					if(k < t[i + 1] - '0') f[i + 1][ch[j][k]][0] = (f[i + 1][ch[j][k]][0] + f[i][j][1]) % P;
					if(k == t[i + 1] - '0') f[i + 1][ch[j][k]][1] = (f[i + 1][ch[j][k]][1] + f[i][j][1]) % P;
				}
			}
	int res = 0;
	for(int i = 1; i <= d; i++) 
		for(int j = 1; j <= tot; j++)
			if(tag[j]) res += (f[i][j][0] * g[i + 1][0] + f[i][j][1] * g[i + 1][1]) % P, res %= P;
	//printf("%d\n", res);
	return res;
}

signed main() {
	scanf("%s", s + 1), scanf("%s", x + 1), scanf("%s", y + 1);
	n = strlen(s + 1), d = strlen(x + 1);
	for(int i = 1; i + d / 2 - 1 <= n; i++) insert(s + i, s + i + d / 2);
	build();
	int now = d;
	while(x[now] == '0') x[now] = '9', now--;
	x[now]--;
	printf("%lld\n", (solve(y) - solve(x) + P) % P);
	return 0;
}