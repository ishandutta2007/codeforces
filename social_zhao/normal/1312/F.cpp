#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 205, M = 3e5 + 5;
int vis[5], sg[6][6][6][3][N], nxt[N], T[6][6][6][3], s[N];
int n, x, y, z, a[M], tmp[M];

void clear() { memset(vis, 0, sizeof(vis)); }
void push(int x) { vis[x]++; }
void GetMex(int &x) { while(vis[x]) ++x; }

void InitSG(int sg[3][N]) {
}

int GetT(int *sg) {
	memset(s, 0, sizeof(s)), memset(nxt, 0, sizeof(nxt));
	for(int i = 1; i <= 100; i++) s[i] = sg[i + 100];
	nxt[1] = 0;
	for(int i = 2; i <= 100; i++) {
		nxt[i] = nxt[i - 1];
		while(nxt[i] && s[i] != s[nxt[i] + 1]) nxt[i] = nxt[nxt[i]];
		if(s[i] == s[nxt[i] + 1]) ++nxt[i];
	}
	return 100 - nxt[100];
}

void init() {
	for(int x = 1; x <= 5; x++)
		for(int y = 1; y <= 5; y++)
			for(int z = 1; z <= 5; z++) {
				sg[x][y][z][0][0] = sg[x][y][z][1][0] = sg[x][y][z][2][0] = 0;
				for(int i = 1; i <= 200; i++) {
					clear(), push(sg[x][y][z][0][max(0ll, i - x)]), push(sg[x][y][z][1][max(0ll, i - y)]), push(sg[x][y][z][2][max(0ll, i - z)]), GetMex(sg[x][y][z][0][i]);
					clear(), push(sg[x][y][z][0][max(0ll, i - x)]), push(sg[x][y][z][2][max(0ll, i - z)]), GetMex(sg[x][y][z][1][i]);
					clear(), push(sg[x][y][z][0][max(0ll, i - x)]), push(sg[x][y][z][1][max(0ll, i - y)]), GetMex(sg[x][y][z][2][i]);
				}
				for(int i = 0; i < 3; i++) T[x][y][z][i] = GetT(sg[x][y][z][i]);
			}
}

int GetSG(int x, int y, int z, int lst, int p) {
	if(p <= 100) return sg[x][y][z][lst][p];
	else return sg[x][y][z][lst][101 + (p - 101) % T[x][y][z][lst]];
}

void solve() {
	n = get(), x = get(), y = get(), z = get();
	for(int i = 1; i <= n; i++) a[i] = get();
	int sum = 0;
	for(int i = 1; i <= n; i++) tmp[i] = GetSG(x, y, z, 0, a[i]), sum ^= tmp[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if((sum ^ tmp[i] ^ GetSG(x, y, z, 0, max(0ll, a[i] - x))) == 0) ++ans;
		if((sum ^ tmp[i] ^ GetSG(x, y, z, 1, max(0ll, a[i] - y))) == 0) ++ans;
		if((sum ^ tmp[i] ^ GetSG(x, y, z, 2, max(0ll, a[i] - z))) == 0) ++ans;
	}
	printf("%lld\n", ans);
}

main() {
	init();
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
2 3 1 4
1 10
*/