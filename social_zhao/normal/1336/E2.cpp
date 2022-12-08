#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 60, P = 998244353, sgn[] = { 1, -1 };
int a[N], b[N], n, m, rnk;
int C[N][N], bin[N], top, ans[N], tmp[N];

void init(int n) {
	for(int i = 0; i <= n; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}
}

int qpow(int x, int y) {
	if(y < 0) y += P - 1;
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void insert(int x) {
	for(int i = m - 1; i >= 0; i--) {
		if(!(x >> i & 1)) continue;
		if(!a[i]) { ++rnk, a[i] = x; return; }
		x ^= a[i];
	}
}

void dfs(int *A, int dep, int now) {
	if(dep == top + 1) return ++A[__builtin_popcountll(now)], void();
	dfs(A, dep + 1, now), dfs(A, dep + 1, now ^ bin[dep]);
}

void inc(int &x, int y) { x = (x + y) % P;}

main() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) insert(get());
	init(m);

	if(rnk <= 27) {
		for(int i = 0; i <= m; i++) if(a[i]) bin[++top] = a[i];
		dfs(ans, 1, 0);
		for(int i = 0; i <= m; i++) ans[i] = (ans[i] * qpow(2, n - rnk) % P + P) % P;
		for(int i = 0; i <= m; i++) cout << ans[i] << " "; cout << endl;
		return 0;
	}

	for(int i = 0; i < m; i++) {
		if(!a[i]) continue;
		for(int j = i + 1; j < m; j++) 
			if(a[j] >> i & 1) a[j] ^= a[i];
	}


	for(int i = 0; i < m; i++) {
		if(a[i]) continue;
		b[i] = 1ll << i;
		for(int j = 0; j < m; j++) if(a[j] >> i & 1) b[i] |= 1ll << j;
	}
	for(int i = 0; i < m; i++) if(b[i]) bin[++top] = b[i];
	// for(int i = 1; i <= top; i++) cout << bin[i] << " "; cout << endl;

	dfs(tmp, 1, 0);
	// for(int i = 0; i < m; i++) cout << tmp[i] << " "; cout << endl;
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= m; j++) {
			int res = 0;
			for(int k = 0; k <= min(i, j); k++)
				inc(res, sgn[k & 1] * C[j][k] * C[m - j][i - k]);
			inc(ans[i], tmp[j] % P * res);
		}
	}
	for(int i = 0; i <= m; i++) ans[i] = (ans[i] * qpow(2, n - m) % P + P) % P;
	for(int i = 0; i <= m; i++) cout << ans[i] << " ";
	return 0;
}