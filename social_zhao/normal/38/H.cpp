#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 55;
int n, m, g1, g2, s1, s2, dis[N][N], isG[N], isS[N], isB[N], mn[N], mx[N], l1, l2;
ll f[N][N][N];

ll solve(int lb, int rb, int ls, int rs) {
	for(int i = 1; i <= n; i++) {
		isG[i] = isS[i] = isB[i] = 0;
		for(int j = 1; j <= n; j++) {
			if(i == j || dis[i][j] == 0x3f3f3f3f) continue;
			if(dis[i][j] <= lb) isG[i] = 1;
			if(dis[i][j] > ls && dis[i][j] < rs) isS[i] = 1;
			if(dis[i][j] >= rb) isB[i] = 1;
		}
	}
	memset(f, 0, sizeof(f));
	f[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			for(int k = 0; j + k < i; k++) {
				if(isG[i]) f[i][j + 1][k] += f[i - 1][j][k];
				if(isS[i]) f[i][j][k + 1] += f[i - 1][j][k];
				if(isB[i]) f[i][j][k] += f[i - 1][j][k];
			}
	ll res = 0;
	for(int i = g1; i <= g2; i++)
		for(int j = s1; j <= s2; j++)
			res += f[n][i][j];
	return res;
}

ll calc(int l, int r) {
	return solve(l, r, l, r) - solve(l - 1, r, l, r) - solve(l, r + 1, l, r) + solve(l - 1, r + 1, l, r);
}

main() {
	n = get(), m = get();
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= m; i++) {
		int u = get(), v = get(), c = get();
		dis[u][v] = dis[v][u] = min(dis[u][v], c);
	}
	g1 = get(), g2 = get(), s1 = get(), s2 = get();
//	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(dis[i][j] != 0x3f3f3f3f) dis[i][j] = dis[i][j] * n + i;
	for(int i = 1; i <= n; i++) {
		mn[i] = 0x3f3f3f3f, mx[i] = 0;
		for(int j = 1; j <= n; j++) if(j != i) mn[i] = min(mn[i], dis[i][j]), mx[i] = max(mx[i], dis[i][j]);
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans += calc(mn[i], mx[j]);
	cout << ans;
	return 0;
}

//