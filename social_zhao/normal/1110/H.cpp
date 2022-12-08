#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e3 + 5, S = 2e4 + 5;
char digL[N], digR[N];
int lenL, lenR, n;
int ch[S][10], fail[S], tot, g[S][N], f[S][N], ans, vis[S][N];

void qmax(int &x, int y) { x = max(x, y); }

void BuildACAM() {
	if(lenL == lenR) {
		int uL = 0, uR = 0;
		for(int i = 1; i <= lenL; i++) {
			int cL = digL[i] - '0', cR = digR[i] - '0';
			if(uL == uR) {
				for(int t = cL + 1; t < cR; t++) {
					if(!ch[uL][t]) ch[uL][t] = ++tot;
					++g[ch[uL][t]][lenL - i];
				}
				if(!ch[uL][cL]) ch[uL][cL] = ++tot;
				if(!ch[uR][cR]) ch[uR][cR] = ++tot;
				uL = ch[uL][cL], uR = ch[uR][cR];
			}
			else {
				for(int t = cL + 1; t <= 9; t++) {
					if(!ch[uL][t]) ch[uL][t] = ++tot;
					++g[ch[uL][t]][lenL - i];
				}
				for(int t = 0; t < cR; t++) {
					if(!ch[uR][t]) ch[uR][t] = ++tot;
					++g[ch[uR][t]][lenR - i];
				}
				if(!ch[uL][cL]) ch[uL][cL] = ++tot;
				if(!ch[uR][cR]) ch[uR][cR] = ++tot;
				uL = ch[uL][cL], uR = ch[uR][cR];
			}
		} 
		++g[uL][0]; if(uL != uR) ++g[uR][0];
//		cerr << tot << endl;
//		cerr << uL << " " << uR << endl;
	} 
	else {
		int uL = 0, uR = 0;
		for(int i = 1; i <= lenL; i++) {
			int cL = digL[i] - '0';
			for(int t = cL + 1; t <= 9; t++) {
				if(!ch[uL][t]) ch[uL][t] = ++tot;
				++g[ch[uL][t]][lenL - i];
			}
			if(!ch[uL][cL]) ch[uL][cL] = ++tot;
			uL = ch[uL][cL];
		}
		++g[uL][0];
		for(int i = 1; i <= lenR; i++) {
			int cR = digR[i] - '0';
			for(int t = 0; t < cR; t++) {
				if(!ch[uR][t]) ch[uR][t] = ++tot;
				++g[ch[uR][t]][lenR - i];
			}
			if(!ch[uR][cR]) ch[uR][cR] = ++tot;
			uR = ch[uR][cR];
		}
		++g[uR][0];
		for(int i = lenL + 1; i < lenR; i++) {
			for(int t = 1; t <= 9; t++) {
				if(!ch[0][t]) ch[0][t] = ++tot;
				++g[ch[0][t]][i - 1];
			}
		}
	}
	ch[0][0] = 0;
	queue<int> q;
	for(int t = 0; t <= 9; t++) if(ch[0][t]) q.push(ch[0][t]);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int c = 0; c <= 9; c++) {
			if(ch[u][c]) {
				fail[ch[u][c]] = ch[fail[u]][c];
				for(int i = 0; i <= n; i++) g[ch[u][c]][i] += g[fail[ch[u][c]]][i];
				q.push(ch[u][c]);
			}
			else ch[u][c] = ch[fail[u]][c];
		}
	}
	for(int i = 0; i <= tot; i++)
		for(int j = 1; j <= n; j++)
			g[i][j] += g[i][j - 1];
}

int main() {
	scanf("%s", digL + 1), lenL = strlen(digL + 1);
	scanf("%s", digR + 1), lenR = strlen(digR + 1);
	n = get();
	BuildACAM();
	memset(f, -0x3f, sizeof(f));
	f[0][0] = 0;
	for(int j = 0; j <= n; j++) {
		for(int i = 0; i <= tot; i++) {
			if(f[i][j] < 0) continue;
			f[i][j] += g[i][n - j];
			for(int c = 0; c <= 9; c++) 
				qmax(f[ch[i][c]][j + 1], f[i][j]); 
		}
	}
	for(int i = 0; i <= tot; i++) ans = max(ans, f[i][n]);
	for(int i = 0; i <= tot; i++) if(f[i][n] == ans) vis[i][n] = 1;
	for(int j = n - 1; j >= 0; j--)
		for(int i = 0; i <= tot; i++)
			for(int c = 0; c <= 9; c++)
				if(vis[ch[i][c]][j + 1] && f[ch[i][c]][j + 1] == f[i][j] + g[ch[i][c]][n - j - 1]) 
					vis[i][j] = 1;
	int now = 0;
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++) {
		for(int c = 0; c <= 9; c++) {
			if(vis[ch[now][c]][i] && f[ch[now][c]][i] == f[now][i - 1] + g[ch[now][c]][n - i]) {
				printf("%c", c + '0');
				now = ch[now][c];
				break;
			}
		}
	}
	return 0;
}