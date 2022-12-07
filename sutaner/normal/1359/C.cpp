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
#define maxn
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

int h, c, t;
double cal(ll k){
	return ((double)(k + 1) * h + (double)k * c) / (2 * k + 1);
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &h, &c, &t); 
		if ((t << 1) <= (h + c)) {printf("2\n"); continue;} 
		else {
			double k = (double)(t - h) / (h + c - (t << 1));
			ll l = (ll)k, r = l + 1;
			double ansl = cal(l), ansr = cal(r), ansm = (double)(h + c) / 2.0;
			if (fabs(ansl - t) <= fabs(ansr - t) && fabs(ansl - t) <= fabs(ansm - t)) {printf("%lld\n", l << 1 | 1); continue;}
			if (fabs(ansr - t) <= fabs(ansl - t) && fabs(ansr - t) <= fabs(ansm - t)) {printf("%lld\n", r << 1 | 1); continue;}
			if (fabs(ansm - t) <= fabs(ansr - t) && fabs(ansm - t) <= fabs(ansl - t)) {printf("%d\n", 2); continue;}
		}
	} 
	return 0;
}