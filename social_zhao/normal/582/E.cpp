#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 505, P = 1e9 + 7, S = 1 << 16;
char s[N];
int n, m, in[N][4], out[N], tot, lim, f[N][S];

void AND(int *A, int type) {
	for(int mid = 1; mid < lim; mid <<= 1) 
		for(int i = 0; i < lim; i += mid << 1)
			for(int j = 0; j < mid; j++)
				(A[i + j] += (P + A[i + mid + j] * type)) %= P;
}

void OR(int *A, int type) {
	for(int mid = 1; mid < lim; mid <<= 1)
		for(int i = 0; i < lim; i += mid << 1)
			for(int j = 0; j < mid; j++)
				(A[i + mid + j] += (P + A[i + j] * type)) %= P;
}

int tmp[S];
void AND(int *A, int *B, int *C) { // add A AND B to C
	AND(A, 1), AND(B, 1);
	for(int i = 0; i < lim; i++) tmp[i] = A[i] * B[i] % P;
	AND(A, -1), AND(B, -1), AND(tmp, -1);
	for(int i = 0; i < lim; i++) (C[i] += tmp[i]) %= P;
}

void OR(int *A, int *B, int *C) { // add A OR B to C
	OR(A, 1), OR(B, 1);
	for(int i = 0; i < lim; i++) tmp[i] = A[i] * B[i] % P;
	OR(A, -1), OR(B, -1), OR(tmp, -1);
	for(int i = 0; i < lim; i++) (C[i] += tmp[i]) %= P;
}

void solve(int u, int l, int r) {
	if(l > r) return;
	if(l == r) {
		int val;
		if('A' <= s[l] && s[l] <= 'D') {
			val = 0; 
			for(int i = 1; i <= m; i++) val |= in[i][s[l] - 'A'] << (i - 1);
			f[u][val]++;
		}
		else if('a' <= s[l] && s[l] <= 'd') {
			val = 0;
			for(int i = 1; i <= m; i++) val |= (!in[i][s[l] - 'a']) << (i - 1);
			f[u][val]++;
		}
		else {
			for(int i = 0; i < 4; i++) {
				val = 0;
				for(int j = 1; j <= m; j++) val |= in[j][i] << (j - 1);
				f[u][val]++, val = 0;
				for(int j = 1; j <= m; j++) val |= (!in[j][i]) << (j - 1);
				f[u][val]++;
			}
		}
		return;
	}
	int tp = 0, mid = 0;
	for(int i = l; i <= r; i++) {
		if(s[i] == '(') tp++;
		else if(s[i] == ')') tp--;
		else if(tp == 0) { mid = i; break; }
	}
	int lc = ++tot, rc = ++tot;
	solve(lc, l + 1, mid - 2), solve(rc, mid + 2, r - 1);
	if(s[mid] == '|' || s[mid] == '?') OR(f[lc], f[rc], f[u]);
	if(s[mid] == '&' || s[mid] == '?') AND(f[lc], f[rc], f[u]);
}

signed main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	m = get(), lim = 1 << m;
	int end = 0;
	for(int i = 1; i <= m; i++) 
		in[i][0] = get(), in[i][1] = get(), in[i][2] = get(), in[i][3] = get(), out[i] = get(), end |= out[i] << (i - 1);
	tot = 1, solve(1, 1, n);
	printf("%lld\n", f[1][end]);
	return 0;
}