#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
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

int n, m, a[maxn], f[maxn];

int qx, sum[maxn << 2];
void add(int l, int r, int o){
	sum[o]++;
	if (l == r) return;
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) add(l, mid, o << 1);
	else add(mid + 1, r, o << 1 | 1);
}
int qd;
int get(int l, int r, int o) {
	if (l == r) return l;
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1 | 1] >= qd) return get(mid + 1, r, o << 1 | 1);
	else {qd -= sum[o << 1 | 1]; return get(l, mid, o << 1);}
}
struct ele{
	int x, y, id;
	ele(int x, int y, int id) : x(x), y(y), id(id){}
	ele(){}
	bool operator < (const ele b) const{
		return x == b.x ? y < b.y : x < b.x;
	}
}q[maxn];

int c[maxn];
void add(int x){
	while (x){
		c[x]++;
		x -= lowbit(x);
	}
}
int get(int x){
	int ans = 0;
	while (x <= n){
		ans += c[x];
		x += lowbit(x); 
	}
	return ans;
}

vector<int> g[maxn];
int res[maxn];
int main(){
	int x, y;
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) {
		int k = i - a[i];
		if (k < 0) f[i] = -1;
		else if (k == 0) f[i] = i;
		else {	
			if (sum[1] < k) f[i] = -1;
			else qd = k, f[i] = get(1, n, 1); 
		}
		if (f[i] != -1) qx = f[i], add(1, n, 1);
	}
	//rep(i, 1, n) cout << f[i] << ' '; cout << endl;
	rep(i, 1, n) {if (f[i] == -1) continue; else g[f[i]].pb(i);}
	rep(i, 1, m) {
		scanf("%d%d", &x, &y);
		q[i] = ele(x + 1, n - y, i); 
	} 
	sort(q + 1, q + 1 + m);
	int ptr = n;
	per(i, m, 1){
		while (ptr >= q[i].x) {
			int si = g[ptr].size();
			srep(j, 0, si) add(g[ptr][j]); 
			ptr--;
		}
		res[q[i].id] = get(q[i].x) - get(q[i].y + 1);
	}
	rep(i, 1, m) printf("%d\n", res[i]);
	return 0;
}