#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 200001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

int a[N];
struct Seg {
	int cnt, lc[N << 1], rc[N << 1], c[N << 1];
	
	void bt(int l, int r) {
		int now = ++cnt;
		lc[now] = rc[now] = -1;
		c[now] = 0;
		if(l == r) c[now] = a[l];
		else {
			int mid = (l + r) / 2;
			lc[now] = cnt + 1; bt(l, mid);
			rc[now] = cnt + 1; bt(mid + 1, r);
		}
	}
	
	void pushdown(int now) {
		if(c[now]) {
			c[lc[now]] = _max(c[lc[now]], c[now]);
			c[rc[now]] = _max(c[rc[now]], c[now]);
			c[now] = 0;
		}
	}
	
	void change(int now, int l, int r, int p, int C) {
		if(l == r) {c[now] = C; return ;}
		pushdown(now);
		int mid = (l + r) / 2;
		if(p <= mid) change(lc[now], l, mid, p, C);
		else change(rc[now], mid + 1, r, p, C);
	}
	
	void gao(int now, int l, int r) {
		if(l == r) {put(c[now]), putchar(' '); return ;}
		pushdown(now);
		int mid = (l + r) / 2;
		gao(lc[now], l, mid), gao(rc[now], mid + 1, r);
	}
} t;

int main() {
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	t.bt(1, n); int q = read();
	while(q--) {
		int o = read();
		if(o == 2) t.c[1] = _max(t.c[1], read());
		else {
			int p = read(), c = read();
			t.change(1, 1, n, p, c);
		}
	} t.gao(1, 1, n);
	return 0;
}