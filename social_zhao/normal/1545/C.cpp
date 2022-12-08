#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 505, P = 998244353;
int n, a[N * 2][N], ans[N * 2], vis[N * 2], occ[N][N], pos[N][N];

void PushTag(int u, int c) {
	if(vis[u]) return;
	vis[u] = 1, ans[u] = c;
	for(int i = 1; i <= n; i++) {
		int v = pos[i][a[u][i]] ^ u;
		PushTag(v, c ^ 1);
	}
}

void clear() {
	memset(ans, 0, sizeof(ans));
	memset(vis, 0, sizeof(vis)), memset(occ, 0, sizeof(occ)), memset(pos, 0, sizeof(pos));
}

void solve() {
	clear();
	n = get();
	for(int i = 1; i <= n * 2; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = get(), ++occ[j][a[i][j]], pos[j][a[i][j]] ^= i;
	for(int i = 1; i <= n; i++) {
		int nw = 0;
		for(int j = 1; j <= n && !nw; j++) 
			for(int k = 1; k <= n && !nw; k++)
				if(occ[k][j] == 1) 
					nw = pos[k][j];
		if(!nw) break;
		vis[nw] = 1, ans[nw] = 1;
		for(int j = 1; j <= n; j++) --occ[j][a[nw][j]], pos[j][a[nw][j]] ^= nw;
		for(int j = 1; j <= 2 * n; j++) {
			if(vis[j]) continue;
			if(j == nw) continue;
			int flag = 0;
			for(int k = 1; k <= n && !flag; k++) if(a[nw][k] == a[j][k]) flag = 1;
			if(!flag) continue;
			vis[j] = 1, ans[j] = 0;
			for(int k = 1; k <= n; k++) --occ[k][a[j][k]], pos[k][a[j][k]] ^= j;
		}
	}
	int tot = 1;
	for(int i = 1; i <= 2 * n; i++) {
		if(vis[i]) continue;
		tot = tot * 2 % P;
		PushTag(i, 1);
	}
	printf("%d\n", tot);
	for(int i = 1; i <= 2 * n; i++) if(ans[i]) printf("%d ", i); printf("\n");
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
7
1 2 3 4 5 6 7
2 3 4 5 6 7 1
3 4 5 6 7 1 2
4 5 6 7 1 2 3
5 6 7 1 2 3 4
6 7 1 2 3 4 5
7 1 2 3 4 5 6
1 2 3 4 5 7 6
1 3 4 5 6 7 2
1 4 5 6 7 3 2
1 5 6 7 4 2 3
1 6 7 5 2 3 4
1 7 6 2 3 4 5
1 7 2 3 4 5 6
*/