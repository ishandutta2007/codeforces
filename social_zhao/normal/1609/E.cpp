#include<bits/stdc++.h>
#define lc (u << 1)
#define rc (u << 1 | 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, m;
char s[N];

struct Matrix {
	int m[3][3];
	
	Matrix() { memset(m, 0x3f, sizeof(m)); }
	
	Matrix(int id) {
		memset(m, 0x3f, sizeof(m));
		if(id == 0) m[0][1] = m[1][1] = m[2][2] = 0, m[0][0] = 1;
		if(id == 1) m[0][0] = m[1][2] = m[2][2] = 0, m[1][1] = 1;
		if(id == 2) m[0][0] = m[1][1] = 0, m[2][2] = 1;
	}
	
	Matrix operator +(Matrix b) {
		Matrix res;
		for(int i = 0; i <= 2; i++)
			for(int j = i; j <= 2; j++)
				for(int k = i; k <= j; k++)
					res.m[i][j] = min(res.m[i][j], m[i][k] + b.m[k][j]);
		return res; 
	}
} t[N << 2];

void pushup(int u) { t[u] = t[lc] + t[rc]; }

void build(int u, int l, int r) {
	if(l == r) return t[u] = Matrix(s[l] - 'a'), void();
	int mid = (l + r) >> 1;
	build(lc, l, mid), build(rc, mid + 1, r);
	pushup(u);
}

void update(int u, int l, int r, int x) {
	if(l == r) return t[u] = Matrix(s[l] - 'a'), void();
	int mid = (l + r) >> 1;
	if(x <= mid) update(lc, l, mid, x);
	else update(rc, mid + 1, r, x);
	pushup(u);
}

int main() {
	n = get(), m = get();
	scanf("%s", s + 1);
	build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		int x = get(); 
		char c; 
		scanf("%c", &c);
		s[x] = c;
		update(1, 1, n, x);
		int ans = 0x3f3f3f3f;
		for(int i = 0; i <= 2; i++) ans = min(ans, t[1].m[0][i]);
		printf("%d\n", ans);
	}
	return 0;
}