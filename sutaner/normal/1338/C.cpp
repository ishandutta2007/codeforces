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
#define maxn
#define maxm
#define maxs
#define maxb 30
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

ll tab[maxb];
int lis[maxb]; 
int tmp[4] = {0, 2, 3, 1};

int main(){

	//freopen("C.in", "r", stdin);
	
	tab[0] = 3;	srep(i, 1, maxb) tab[i] = tab[i - 1] << 2; 
	srep(i, 1, maxb) tab[i] += tab[i - 1]; //printf("%lld ", tab[i]);
	
	
	int T;
	read(T);
	ll x;
	while (T--){
		read(x);
		int id = lower_bound(tab, tab + maxb, x) - tab;
		if (!id) {printf("%lld\n", x); continue;}
		ll line_id = (x - 1) / 3 + 1;
		ll offset = line_id - tab[id - 1] / 3 - 1; 
		ll step = 1;
		ll mid = ((tab[id] - tab[id - 1]) / 3) << 1;
		ll pre = offset + (tab[id] - tab[id - 1]) / 3;
		rep(i, 1, id){
			lis[i] = offset & 3;
			offset >>= 2;
			step <<= 2;
		}
		step >>= 2;
		per(i, id, 1) mid += tmp[lis[i]] * step, step >>= 2;
		ll suf = pre ^ mid;
		if (x % 3 == 1) write(pre);
		else if (x % 3 == 2) write(mid);
		else write(suf);
	}
	
	return 0;
}