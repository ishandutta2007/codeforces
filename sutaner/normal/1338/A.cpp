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

int main(){

	int T, n;
	read(T);
	while (T--){
		read(n);
		int mx = 0;
		int ans = 0;
		int x, _x, s;
		rep(i, 1, n){
			read(x);
			if (i != 1 && x < mx){
				_x = mx - x;
				s = 0;
				while (_x) s++, _x >>= 1;
				ans = max(ans, s);
			}
			else mx = x;
		}
		write(ans);
	}
		//freopen(".in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	/*
	int T;
	scanf("%d", &T);
	rep(TT, 1, T){
		printf("Case #%d: ", TT);
		
		
		
		printf("\n");
	}
	*/
	return 0;
}