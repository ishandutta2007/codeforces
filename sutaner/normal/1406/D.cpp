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

int n, m, a[maxn];

ll c[maxn];
void add(int x, ll v){
	while (x <= n){
		c[x] += v;
		x += lowbit(x);
	}
}
ll get(int x){
	ll ans = 0;
	while (x){
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
ll now = 0;
int main(){
	int x, y, z;
	read(n);
	rep(i, 1, n) read(a[i]);
	rep(i, 2, n) now += max(0, a[i] - a[i - 1]);
	rep(i, 1, n) add(i, a[i] - a[i - 1]);
	printf("%lld\n", (get(1) + now + 1) >> 1);
	read(m);
	rep(i, 1, m) {
		read(x), read(y), read(z);
		if (x > 1) now -= max(0ll, get(x) - get(x - 1));
		if (y < n) now -= max(0ll, get(y + 1) - get(y)); 
		add(x, z), add(y + 1, -z);
		if (x > 1) now += max(0ll, get(x) - get(x - 1));
		if (y < n) now += max(0ll, get(y + 1) - get(y));
		printf("%lld\n", (get(1) + now + 1) >> 1);
	} 
	return 0;
}