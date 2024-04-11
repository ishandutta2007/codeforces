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
#define maxn 300020
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

int n, k, m;
int mx[maxn << 3], add[maxn << 3];
int qx, qy, qd;
inline void pu(int o){
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}
inline void pd(int o){
	if (add[o]){
		int& k = add[o];
		add[o << 1] += k, add[o << 1 | 1] += k;
		mx[o << 1] += k, mx[o << 1 | 1] += k;
		k = 0;
	}
}
void init(int l, int r, int o){
	add[o] = 0;
	if (l == r) {mx[o] = l - n - 1; return;}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
void Add(int l, int r, int o){
	pd(o);
	if (qx <= l && r <= qy) {add[o] += qd, mx[o] += qd; return;}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) Add(l, mid, o << 1);
	if (qy > mid) Add(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o){
	pd(o);
	if (qx <= l && r <= qy) return mx[o];
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans = max(ans, get(l, mid, o << 1));
	if (qy > mid) ans = max(ans, get(mid + 1, r, o << 1 | 1));
	return ans;
}

set<pii> s;
multiset<int> ss;

int main(){
	int x, y;
	scanf("%d%d%d", &n, &k, &m);
	init(1, n << 1, 1);
	rep(i, 1, m){
		scanf("%d%d", &x, &y);
		if (s.count(pii(x, y))){	
			qx = 1, qy = abs(x - k) + y, qd = -1;
			Add(1, n << 1, 1);
			s.erase(pii(x, y));
			ss.erase(ss.lower_bound(abs(x - k) + y));
		}
		else { 
			qx = 1, qy = abs(x - k) + y, qd = 1;
			Add(1, n << 1, 1);
			s.insert(pii(x, y));
			ss.insert(abs(x - k) + y);
		}
		if (ss.empty()) printf("0\n");
		else {
			qx = 1, qy = *ss.rbegin();
			printf("%d\n", get(1, n << 1, 1));
		}
	} 
	return 0;
}