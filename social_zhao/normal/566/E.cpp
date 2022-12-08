#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e3 + 5;
int n, flag = 1, edge[N][N], tot = 0, bel[N], vis[N];
bitset<N> s[N], g[N], nleaf;

int main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		int sz = get(); flag &= (sz == n); edge[i][i] = 1;
		for(int j = 1; j <= sz; j++) s[i].set(get());
	}
	if(flag) {
		for(int i = 2; i <= n; i++) printf("1 %d\n", i);
		return 0;
	}
	/*
	*/
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++) {
			bitset<N> p = s[i] & s[j];
			if(p.count() == 2) {
				int u = p._Find_first(), v = p._Find_next(u);
				if(edge[u][v]) continue; 
				edge[u][v] = edge[v][u] = nleaf[u] = nleaf[v] = 1;
				printf("%d %d\n", u, v);
			}
		}
	for(int i = 1; i <= n; i++) if(nleaf[i]) tot++;
	for(int i = 1; i <= n; i++) if(!nleaf[i]) {
		int mn = 0x3f3f3f3f;
		for(int j = 1; j <= n; j++) 
			if(s[j][i] && !vis[j] && s[j].count() < mn) bel[i] = j, mn = s[j].count();
		vis[bel[i]] = 1;
	}
	if(tot == 2) {
		int x = nleaf._Find_first(), y = nleaf._Find_next(x);
		for(int i = 1; i <= n; i++) {
			if(!nleaf[i]) {
				for(int j = 1; j <= n; j++) {
					if(s[bel[i]][j] && !nleaf[j]) edge[x][j] = edge[j][x] = 1, printf("%d %d\n", x, j);
				}
				for(int j = 1; j <= n; j++) 
					if(!edge[x][j]) edge[y][j] = edge[j][y] = 1, printf("%d %d\n", y, j);
				return 0;
			}
		}
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(edge[i][j]) g[i].set(j);
			if(!nleaf[i] && !nleaf[j] && s[bel[i]][j]) s[bel[i]][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(nleaf[i]) continue;
		for(int j = 1; j <= n; j++) {
			if(!nleaf[j]) continue;
			if(s[bel[i]] == g[j]) { edge[i][j] = edge[j][i] = 1; printf("%d %d\n", j, i); break; }
		}
	}
	return 0;
}

/*
5
4 1 2 3 4
5 1 2 3 4 5
3 1 2 4
4 1 2 3 5
3 1 3 5
*/