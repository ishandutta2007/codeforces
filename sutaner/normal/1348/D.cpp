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

int n, res[maxn], cs = 0;

int main(){
	
		//freopen(".in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	
	int T;
	read(T);
	rep(TT, 1, T){
		cs = 0;
		read(n);
		n--;
		int now = 1;
		while (n){
			if (n - (now << 1) >= (now << 1)) now <<= 1, n -= now, res[++cs] = now >> 1;
			else if (n <= (now << 1)) res[++cs] = n - now, n = 0;
			else res[++cs] = n / 2 - now, res[++cs] = n - n / 2 - n / 2, n = 0;
		}
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d ", res[i]);
		printf("\n");
	} 
	return 0;
}