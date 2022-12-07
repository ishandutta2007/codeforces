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

int n;
ll a[maxn];

int main(){
	int n; scanf("%d", &n);
	rep(i, 1, n) scanf("%lld", a + i);
	if (n == 1) {
		printf("1 1\n0\n1 1\n0\n1 1\n%d\n", -a[1]);
		return 0;
	}
	printf("%d %d\n", 1, n - 1);
	rep(i, 1, n - 1) {
		int k = a[i] % n;
		if (k < 0) k += n;
		printf("%lld ", 1ll * k * (n - 1));
		a[i] += 1ll * k * (n - 1);
	}printf("\n");
	printf("%d %d\n", n, n);
	rep(i, n, n) {
		int k = a[i] % n;
		if (k < 0) k += n;
		printf("%lld ", 1ll * k * (n - 1));
		a[i] += 1ll * k * (n - 1);
	}printf("\n");
	printf("%d %d\n", 1, n); 
	rep(i, 1, n) printf("%lld ", -a[i]); printf("\n");
	return 0;
}