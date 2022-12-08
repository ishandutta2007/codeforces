#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 205, P = 1e4 + 7;
int n, len;
char s[N];
int f[N][N][N], g[N][N][N];

void inc(int &x, int y) { x = (x + y) % P; }

struct Matrix {
	int m[N * 2][N * 2], x;
	Matrix(int a = 0) { x = a; memset(m, 0, sizeof(m)); }
	Matrix operator *(const Matrix &b) {
		Matrix res(x);
		for(int i = 0; i <= x; i++)
			for(int j = i; j <= x; j++)
				for(int k = i; k <= j; k++)
					inc(res.m[i][j], m[i][k] * b.m[k][j]);
		return res;
	}
	int* operator [](int a) { return m[a]; }
};

int dfs(int l, int r, int i) {
	if(i < 0) return 0;
	if(s[l] == s[r] && r - l <= 1) return i == 0;
	if(~f[l][r][i]) return f[l][r][i];
	int res = 0;
	if(s[l] == s[r]) res = dfs(l + 1, r - 1, i);
	else res = (dfs(l + 1, r, i - 1) + dfs(l, r - 1, i - 1)) % P;
	f[l][r][i] = res;
	return res;
}

int df5(int l, int r, int i) {
	if(i < 0) return 0;
	if(s[l] == s[r] && r - l == 1) return i == 0;
	else if(l == r) return 0;
	if(~g[l][r][i]) return g[l][r][i];
	int res = 0;
	if(s[l] == s[r]) res = df5(l + 1, r - 1, i);
	else res = (df5(l + 1, r, i - 1) + df5(l, r - 1, i - 1)) % P;
	g[l][r][i] = res;
	return res;
}

int Fuck() {
	memset(g, -1, sizeof(g));
	for(int i = 0; i <= len; i++) g[1][len][i] = df5(1, len, i);
	int tot = len + (len + 1) / 2 + 1;
	static Matrix trs(tot), res(tot);
	res[0][1] = 1, res[0][len + 1] = g[1][len][0];
	for(int i = 1; i <= len; i++) trs[i][i] = 24;
	for(int i = 1; i < len; i++) trs[i][i + 1] = 1;
	for(int i = len + 1; i <= tot; i++) trs[i][i] = 25;
	for(int i = len + 1; i < tot; i++) trs[i][i + 1] = 1;
	for(int i = 1; i <= len; i++) trs[i][tot - (len - i + 1) / 2] = g[1][len][i];
	trs[tot][tot] = 0;
//	printf("Matrix:\n");
//	for(int i = 0; i <= tot; i++, printf("\n"))
//		for(int j = 0; j <= tot; j++)
//			printf("%d ", trs[i][j]);
	int y = (n + len + 1) / 2;
	while(y) {
		if(y & 1) res = res * trs;
		trs = trs * trs, y >>= 1;
	}
	int ans = res[0][tot];
	return ans;
}

int main() {
//	freopen("table.out", "w", stdout);
	scanf("%s", s + 1), len = strlen(s + 1);
	n = get();
	memset(f, -1, sizeof(f));
	for(int i = 0; i <= len; i++) f[1][len][i] = dfs(1, len, i);
	int tot = len + (len + 1) / 2 + 1;
//	printf("%d %d\n", mxI, mxII);
	static Matrix trs(tot), res(tot);
	res[0][1] = 1, res[0][len + 1] = f[1][len][0];
	for(int i = 1; i <= len; i++) trs[i][i] = 24;
	for(int i = 1; i < len; i++) trs[i][i + 1] = 1;
	for(int i = len + 1; i <= tot; i++) trs[i][i] = 25;
	for(int i = len + 1; i < tot; i++) trs[i][i + 1] = 1;
	for(int i = 1; i <= len; i++) trs[i][tot - (len - i + 1) / 2] = f[1][len][i];
	trs[tot][tot] = 26;
//	printf("Matrix:\n");
//	for(int i = 0; i <= tot; i++, printf("\n"))
//		for(int j = 0; j <= tot; j++)
//			printf("%d ", trs[i][j]);
	int y = (n + len + 1) / 2;
//	printf("%d\n", y);
	while(y) {
		if(y & 1) res = res * trs;
		trs = trs * trs, y >>= 1;
	}
	int ans = res[0][tot];
//	printf("ans1: %d\n", ans);
	if((n + len) & 1) ans = ans - Fuck();
	printf("%d\n", (ans % P + P) % P);
	return 0;
}

/*
toudairiichishusekizennyuumrtoudaikanojomochitoudaiigakubunotennsaitoudaihougakubunoshuusaitoudaiigakubushusekitoudaiiqkikoushisuugakugorinnkinnkyoudaikeizaigakubushusekichishikimonstertoudainoitannji        
1000000000
*/