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
#define maxn 2000020
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
int n;
ll a[maxn], b[maxn], c[maxn << 1];
ll st[maxn << 1];
int head = 0, tail = 0;

inline void add(int i){
	while (head > tail && c[i] >= c[st[head]]) head--;
	st[++head] = i;
}
inline void del(int i){
	if (st[tail + 1] == i) tail++;
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--){ 	
		head = tail = 0;
		scanf("%d", &n);
		ll sa = 0, sb = 0;
		rep(i, 1, n) scanf("%lld", a + i), sa += a[i];
		rep(i, 1, n) scanf("%lld", b + i), sb += b[i];
		if (sa > sb) {printf("NO\n"); continue;}
		rep(i, 1, n) c[i] = a[i] - b[i], c[i + n] = c[i];
		rep(i, 1, 2 * n) c[i] += c[i - 1];
		ll mx = 0;
		rep(i, 2, n) add(i);
		rep(i, 1, n){
			mx = max(mx, c[st[tail + 1]] - c[i] - b[i]);
			add(n + i), del(i + 1);
		}
		if (mx == 0) printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}