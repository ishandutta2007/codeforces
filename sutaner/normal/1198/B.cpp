#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define maxr 100000
#define pb push_back
#define maxn 300015
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, q;
int a[maxn];

pii op[maxn];
int op2[maxn], c2 = 0;

int c[maxn];
void add(int x, int v){
	while (x){
		c[x] = max(c[x], v);
		x -= lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x <= c2){
		ans = max(ans, c[x]);
		x += lowbit(x);
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	int x, y;
	read(n);
	rep(i, 1, n) read(a[i]), op[i] = pii(-1, -1);
	read(q);
	rep(i, 1, q) {
		read(x);
		if (x == 1) read(x), read(y), op[x] = pii(y, c2); 
		else if (x == 2) read(x), op2[++c2] = x;  
	}
	rep(i, 1, c2) add(i, op2[i]);
	rep(i, 1, n){
		if (op[i].se == -1){
			printf("%d ", max(a[i], get(1)));
		}
		else {
			printf("%d ", max(op[i].fi, get(op[i].se + 1)));
		}
	}
	return 0;
}