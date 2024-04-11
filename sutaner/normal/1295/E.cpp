#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 400020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, a[maxn], p[maxn], pos[maxn];
ll c[maxn];
ll add[maxn << 2];
ll mi[maxn << 2];
int qx, qy, qd;
inline void pu(int o){
	mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
}
inline void pd(int o){
	if (add[o]){
		ll& k = add[o];
		add[o << 1] += k, add[o << 1 | 1] += k; 
		mi[o << 1] += k, mi[o << 1 | 1] += k;
		k = 0;
	}
}
void init(int l, int r, int o){
	if (l == r) {mi[o] = c[l]; return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
void Add(int l, int r, int o){
	pd(o);
	if (qx <= l && r <= qy) {mi[o] += qd, add[o] += qd; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Add(l, mid, o << 1);
	if (qy > mid) Add(mid + 1, r, o << 1 | 1);
	pu(o);
}

int main(){
	
		//freopen("in1.txt", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	read(n);
	rep(i, 1, n) read(p[i]), pos[p[i]] = i;
	rep(i, 1, n) read(a[i]);	 
	rep(i, 1, n) c[i] = c[i - 1] + a[pos[i]];
	init(0, n, 1);
	ll ans = 0; bool f = 1;
	srep(i, 1, n){
		qx = 0, qy = p[i] - 1, qd = a[i];
		Add(0, n, 1);
		qx = p[i], qy = n, qd = -a[i];
		Add(0, n, 1);
		if (f) ans = mi[1], f = 0;
		else ans = min(ans, mi[1]);
	}
	write(ans);
	return 0;
}