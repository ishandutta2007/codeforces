#include <bits/stdc++.h>

using namespace std;

#define mod 777777777
#define N 77977
#define MD int md = (L + R) >> 1
#define ls id << 1
#define rs id << 1 | 1
#define Ls L, md, ls
#define Rs md + 1, R, rs

int n, m;
int f[3][3][N << 2], a[3][3];

inline void add(int &a, int b) { a += b; if(a >= mod) a -= mod; }

void up(int id) {
	for(int i = 0; i < 3; i ++) for(int j = 0; j < 3; j ++) f[i][j][id] = 0;
	for(int i = 0; i < 3; i ++) for(int j = 0; j < 3; j ++) if(a[i][j]) {
		for(int ii = 0; ii < 3; ii ++) if(f[ii][i][ls]) {
			for(int jj = 0; jj < 3; jj ++) add(f[ii][jj][id], 1LL * f[ii][i][ls] * f[j][jj][rs] % mod);
		}
	}
}

void build(int L, int R, int id) {
	if(L == R) {
		for(int i = 0; i < 3; i ++) f[i][i][id] = 1;
		return ;
	}
	MD; build(Ls); build(Rs);
	up(id);
}

void update(int L, int R, int id, int x, int v) {
	if(L == R) {
		for(int i = 0; i < 3; i ++) for(int j = 0; j < 3; j ++) f[i][j][id] = 0;
		if(v) f[v - 1][v - 1][id] = 1;
		else for(int i = 0; i < 3; i ++) f[i][i][id] = 1;
		return ;
	}
	MD;
	if(x <= md) update(Ls, x, v); else update(Rs, x, v);
	up(id);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	build(1, n, 1);
	while(m --) {
		int x, y;
		scanf("%d%d", &x, &y);
		update(1, n, 1, x, y);
		int rt = 0;
		for(int i = 0; i < 3; i ++) for(int j = 0; j < 3;j ++) add(rt, f[i][j][1]);
		printf("%d\n", rt);
	}
	return 0;
}