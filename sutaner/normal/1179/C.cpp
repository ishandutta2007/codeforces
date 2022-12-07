#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long int
#define ls ch[x][0]
#define rs ch[x][1]
#define lowbit(x) x & -x
#define maxr 100005
#define maxn 300015
#define maxm
#define maxv 1100015
#define X(x) 
#define Y(x)
#define TAN(x)
#define next NEXT
#define hash HASH
#define M 
#define pb push_back
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define esrep(i, x, NS) for (register int i = NS :: h[x]; i; i = NS :: e[i].next)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); bool f = 1; x = 0;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	if (!f) x = -x;
}

int n, m, q;
int a[maxn], b[maxn];
int mx[maxv << 1];
int mxp[maxv << 1];
int add[maxv << 1];
int qx, qy, qd;
void pu(int o){
	if (mx[o << 1] > mx[o << 1 | 1]) mx[o] = mx[o << 1], mxp[o] = mxp[o << 1];
	else mx[o] = mx[o << 1 | 1], mxp[o] = mxp[o << 1 | 1];
}
void pd(int l, int r, int o){
	if (l == r) return;
	if (add[o]){
		add[o << 1] += add[o], add[o << 1 | 1] += add[o];
		mx[o << 1] += add[o], mx[o << 1 | 1] += add[o];
		add[o] = 0;
	}
}
void init(int l, int r, int o){
	if (l == r) {mxp[o] = l;return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
void ADD(int l, int r, int o){
	pd(l, r, o);
	if (qx <= l && r <= qy) {
		add[o] += qd;
		mx[o] += qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) ADD(l, mid, o << 1);
	if (qy > mid) ADD(mid + 1, r, o << 1 | 1);
	pu(o);
}
int GET(int l, int r, int o){
	if (l == r) return l;
	pd(l, r, o);
	int mid = ((r - l) >> 1) + l;
	if (mx[o << 1 | 1] > 0) return GET(mid + 1, r, o << 1 | 1);
	else return GET(l, mid, o << 1);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("C.in", "r", stdin);
	#endif
	read(n), read(m);
	init(1, 1000000, 1);
	qx = 1;
	rep(i, 1, n) read(a[i]), qy = a[i], qd = 1, ADD(1, 1000000, 1);
	rep(i, 1, m) read(b[i]), qy = b[i], qd = -1, ADD(1, 1000000, 1);
	read(q);
	int x, y, z;
	rep(i, 1, q){
		read(x), read(y), read(z);
		if (x == 1){
			qy = a[y], qd = -1, ADD(1, 1000000, 1);
			a[y] = z;
			qy = a[y], qd = 1, ADD(1, 1000000, 1);
		}
		else if (x == 2){
			qy = b[y], qd = 1, ADD(1, 1000000, 1);
			b[y] = z;
			qy = b[y], qd = -1, ADD(1, 1000000, 1);
		}
		if (mx[1] <= 0) printf("-1\n");
		else printf("%d\n", GET(1, 1000000, 1));
	}
	return 0;
}