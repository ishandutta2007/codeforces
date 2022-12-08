#include<bits/stdc++.h>
#define int long long
#define lc (u << 1)
#define rc (u << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5, inv100 = 828542813, P = 998244353;
int n, x[N], y[N], p[N], top, len;
struct Crash { 
	int x, y, v1, v2, id; // 
	Crash() { x = y = v1 = v2 = id = 0; }
	Crash(int a, int b, int c, int d, int e) { int g = __gcd(a, b); x = a / g, y = b / g, v1 = c, v2 = d, id = e; }
	double GetTime() { return 1.0 * x / y; }
	friend bool operator <(Crash a, Crash b) { return a.GetTime() < b.GetTime(); }
	friend bool operator ==(Crash a, Crash b) { return a.GetTime() == b.GetTime(); }
} bin[N << 4];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void add(int &x, int y) { x = (x + y) % P; }

struct Matrix {
	int m[2][2];
	Matrix() { memset(m, 0, sizeof(m)); }
	Matrix operator *(Matrix b) {
		Matrix res;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					add(res.m[i][j], m[i][k] * b.m[k][j]);
		return res;
	}
	int* operator [](int x) { return m[x]; }
	
	void print() {
		printf("------DEBUG------\n");
		for(int i = 0; i < 2; i++, printf("\n"))
			for(int j = 0; j < 2; j++)
				printf("%lld ", m[i][j]);
	}
} t[N << 2], nw[N];

void pushup(int u) { t[u] = t[lc] * t[rc]; }

void build(int u, int l, int r) {
	if(l == r) {
		for(int i = 0; i < 2; i++) t[u][i][1] = p[l] * inv100 % P, t[u][i][0] = (P + 1 - t[u][i][1]) % P;
		nw[l] = t[u];
		return;
	}
	build(lc, l, mid), build(rc, mid + 1, r), pushup(u);
}

void update(int u, int l, int r, int x, Matrix v) {
	if(l == r) return t[u] = v, void();
	if(x <= mid) update(lc, l, mid, x, v);
	else update(rc, mid + 1, r, x, v);
	pushup(u);
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) x[i] = get(), y[i] = get(), p[i] = get();
	build(1, 1, n);
	for(int i = 2; i <= n; i++) {
		if(y[i - 1] < y[i]) bin[++top] = Crash(x[i] - x[i - 1], y[i] - y[i - 1], 0, 0, i);
		bin[++top] = Crash(x[i] - x[i - 1], y[i] + y[i - 1], 1, 0, i);
		if(y[i] < y[i - 1]) bin[++top] = Crash(x[i] - x[i - 1], y[i - 1] - y[i], 1, 1, i);
	}
	sort(bin + 1, bin + 1 + top);
	int ans = 0;
	for(int i = 1; i <= top; i++) {
		Matrix tmp;
		int tim = bin[i].x * qpow(bin[i].y, P - 2) % P;
		tmp[bin[i].v1][bin[i].v2] = nw[bin[i].id][bin[i].v1][bin[i].v2];
		update(1, 1, n, bin[i].id, tmp);
		add(ans, tim * ((t[1][0][0] + t[1][0][1]) % P) % P);
		nw[bin[i].id][bin[i].v1][bin[i].v2] = 0;
		update(1, 1, n, bin[i].id, nw[bin[i].id]);
//		for(int i = 1; i <= n; i++) nw[i].print();
	}
	printf("%lld\n", ans);
	return 0;
}

/*
2
1 1 100
3 1 0
*/