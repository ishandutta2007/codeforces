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
#define maxn 500020
#define maxv 20000020
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
int a[maxn];
int cnt[maxv];


int main(){

	//freopen("b.in", "r", stdin);
	
	scanf("%d", &n);
	int now = 0, tot = 0;
	rep(i, 1, n) scanf("%d", a + i), tot ^= ((a[i] & 1) & ((n - 1) & 1)); 
	rep(j, 1, 24) {
		bool ans = 0;
		now |= (1 << (j - 1));
		rep(i, 1, n) cnt[a[i] & now]++, ans ^= (((a[i] >> j) & 1) & ((n - 1) & 1)); 
		ll sum = 0, sav = 0;
		srep(i, 0, (1 << j)){
			sum += sav * cnt[i];
			if ((i << 1) >= (1 << j)) sum -= cnt[i];
			sav += cnt[(1 << j) - i - 1];
		}
		ans ^= ((sum >> 1) & 1);
		rep(i, 1, n) cnt[a[i] & now]--;
		if (ans) tot ^= (1 << j);
	} 
	write(tot);
	return 0;
}