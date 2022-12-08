#define cxy  
#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 25, S = 1 << 8;
int n, m, f[N][N][S], val[N], sum[S], ins[N][N][S], pre[N][N][S];
char mp[N][N];
int px[N], py[N], tot, mx, sx, sy;
queue<tuple<int, int, int>> q;

void bfs() {
	q.emplace(sx, sy, 0);
	while(q.size()) {
		tuple<int, int, int> now = q.front(); q.pop();
		int x = get<0>(now), y = get<1>(now), s = get<2>(now), res = f[x][y][s];
		if(mp[x][y + 1] == '.' || mp[x][y + 1] == 'S') {
			if(f[x][y + 1][s] == -1) f[x][y + 1][s] = res + 1, q.emplace(x, y + 1, s);
		}
		if(mp[x][y - 1] == '.' || mp[x][y - 1] == 'S') {
			if(f[x][y - 1][s] == -1) f[x][y - 1][s] = res + 1, q.emplace(x, y - 1, s);
		}
		if(mp[x - 1][y] == '.' || mp[x - 1][y] == 'S') {
			int ns = s;
			for(int i = 1; i <= tot; i++) if(py[i] < y && px[i] == x) ns ^= (1 << (i - 1));
			if(f[x - 1][y][ns] == -1) f[x - 1][y][ns] = res + 1, q.emplace(x - 1, y, ns);
		}
		if(mp[x + 1][y] == '.' || mp[x + 1][y] == 'S') {
			int ns = s;
			for(int i = 1; i <= tot; i++) if(py[i] < y && px[i] == x + 1) ns ^= (1 << (i - 1));
			if(f[x + 1][y][ns] == -1) f[x + 1][y][ns] = res + 1, q.emplace(x + 1, y, ns);
		}
	}
}

int main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) 
		scanf("%s", mp[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(isdigit(mp[i][j])) ++tot, px[mp[i][j] - '0'] = i, py[mp[i][j] - '0'] = j;
			else if(mp[i][j] == 'S') sx = i, sy = j;
	mx = tot;
	for(int i = 1; i <= mx; i++) val[i] = get();
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++)
			if(mp[i][j] == 'B') ++tot, px[tot] = i, py[tot] = j;
	for(int i = 1; i < 1 << mx; i++)
		for(int j = 1; j <= mx; j++)
			if(i >> (j - 1) & 1) sum[i] += val[j];
	memset(f, -1, sizeof(f));
	f[sx][sy][0] = 0;
	bfs();
	int ans = 0;
	for(int i = 1; i < 1 << mx; i++) 
		if(f[sx][sy][i] != -1)
			ans = max(ans, sum[i] - f[sx][sy][i]);
	cout << ans;
	return 0;
} 

/*
3 5
.....
S1...
...2B
10 10
*/