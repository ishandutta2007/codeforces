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

const ll inf = 0x3f3f3f3f3f3f3f3f;

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

int neg[maxn], pos[maxn];
int cn = 0, cp = 0;
int main(){
	int T, x, n; read(T);
	while (T--){
		cn = cp = 0;
		ll ans = -inf, res = 1;
		read(n);
		rep(i, 1, n) {
			read(x);
			if (x < 0) neg[++cn] = -x;
			else if (x > 0) pos[++cp] = x;
			else ans = 0;
		} 
		sort(neg + 1, neg + 1 + cn);
		sort(pos + 1, pos + 1 + cp); 
		for (register int i = 0; i <= 5; i += 2){
			if (i > cn || 5 - i > cp) continue;
			res = 1;
			rep(j, 1, i) res *= neg[cn - j + 1];
			rep(j, 1, 5 - i) res *= pos[cp - j + 1];
			ans = max(ans, res);
		}
		for (register int i = 1; i <= 5; i += 2){
			if (i > cn || 5 - i > cp) continue;
			res = 1;
			rep(j, 1, i) res *= neg[j];
			rep(j, 1, 5 - i) res *= pos[j];
			ans = max(ans, -res);
		}
		printf("%lld\n", ans);
	} 
	return 0;
}