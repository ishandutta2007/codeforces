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
#define maxn 200020
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

int n, d, m;
int a[maxn];
ll pre[maxn];

int main(){
	read(n), read(d), read(m);
	rep(i, 1, n) read(a[i]);
	sort(a + 1, a + 1 + n);
	ll ans = 0;
	int f = n + 1;
	rep(i, 1, n) if (a[i] > m) {f = i; break;} 
	reverse(a + 1, a + f);
	srep(i, 1, f) pre[i] = pre[i - 1] + a[i];
	
	int rest = n;
	bool first = 1;
	ll res = 0;
	per(i, n, 0){
	    ans = max(ans, res + pre[max(0, min(rest, f - 1))]);
	    if (a[i] <= m) break;
	    if (first) rest--, first = 0;
	    else rest -= d + 1;
	    res += a[i];
	    if (rest < 0) break;
	}
    printf("%lld\n", ans);
	return 0;
}