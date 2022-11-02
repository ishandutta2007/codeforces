#include <bits/stdc++.h>
using namespace std;
#define N 2500
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, d[N][N], ans;
char s[N][N];
bool vis[N][N];
queue<pii> q;
char rlt[N][N];

void input() {
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (s[i][j] == '*') continue;
			if (!d[i][j]) {ans = 0; return;}
			if (d[i][j] == 1) q.push(mp(i, j));
		}
	}
}

pii mov(pii a, int i) {
	if (i == 0) return mp(a.first - 1, a.second);
	if (i == 1) return mp(a.first + 1, a.second);
	if (i == 2) return mp(a.first, a.second - 1);
	return mp(a.first, a.second + 1);
}

bool ins(pii a) {
	if (a.first && a.second && a.first <= n && a.second <= m) return true;
	return false;
}

void func() {
	while (!q.empty()) {
		pii u = q.front();

		q.pop();
		if (vis[u.first][u.second]) continue;
		pii v;
		int i;
		for (i = 0; i < 4; i ++) {
			v = mov(u, i);
			if (ins(v) && !vis[v.first][v.second] && s[v.first][v.second] == '.') break;
		}
		if (i == 0) rlt[u.first][u.second] = 'v', rlt[v.first][v.second] = '^';
		if (i == 1) rlt[u.first][u.second] = '^', rlt[v.first][v.second] = 'v';
		if (i == 2) rlt[u.first][u.second] = '>', rlt[v.first][v.second] = '<';
		if (i == 3) rlt[u.first][u.second] = '<', rlt[v.first][v.second] = '>';
		vis[u.first][u.second] = vis[v.first][v.second] = 1;
		pii p;
		for (int j = 0; j < 4; j ++) {
			p = mov(v, j);
			if (ins(p) && !vis[p.first][p.second] && s[p.first][p.second]) {
				d[p.first][p.second] --;
				if (!d[p.first][p.second]) {ans = 0; return;}
				if (d[p.first][p.second] == 1) q.push(p);
			}
		}
	}
}

void last() {
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			if (s[i][j] == '*') continue;
			if (!vis[i][j]) {
				ans = 0;
				return;
			}
		}
}

int main() {
	scanf("%d%d ", &n, &m);
	for (int i = 1; i <= n; i ++) gets(s[i] + 1);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j < m; j ++) {
			if (s[i][j] == '.' && s[i][j+1] == '.') {
				d[i][j] ++; d[i][j+1] ++;
			}
		}
	for (int j = 1; j <= m; j ++)
		for (int i = 1; i < n; i ++) {
			if (s[i][j] == '.' && s[i+1][j] == '.') {
				d[i][j] ++; d[i+1][j] ++;
			}
		}
	ans = 1;
	input();
	if (ans) func();
	last();
	if (!ans) puts("Not unique");
	else {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				if (!rlt[i][j]) putchar('*');
				else putchar(rlt[i][j]);
			}
			puts("");
		}
	}
    return 0;
}