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
#define maxn 2020
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

pii ans[maxn * maxn], lis[maxn];
int cs = 0;
int pos[maxn], a[maxn], n;

inline void swap2(int i, int j){
	swap(a[i], a[j]);
	swap(pos[a[i]], pos[a[j]]);
}

void work(int id){
	if (id == 1) return;
	if (pos[id - 1] < pos[id]) {work(id - 1); return;}
	ans[++cs] = pii(pos[id - 1], pos[id]), swap2(pos[id - 1], pos[id]);
	if (id < n && pos[id] > pos[id + 1]) {work(id + 1); return;}
	work(id - 1);
}

int main(){	 
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i), lis[i] = pii(a[i], i);
	sort(lis + 1, lis + 1 + n);
	rep(i, 1, n) a[i] = lower_bound(lis + 1, lis + 1 + n, pii(a[i], i)) - lis, pos[a[i]] = i; 
	work(n); 
	printf("%d\n", cs);
	rep(i, 1, cs) printf("%d %d\n", min(ans[i].fi, ans[i].se), max(ans[i].fi, ans[i].se));
	return 0;
}