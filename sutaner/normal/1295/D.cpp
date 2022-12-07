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

ll a, b;
ll gcd(ll x, ll y){
	ll t;
	while (y) t = y, y = x % y, x = t;
	return x;
}
int p[maxn], cnt = 0;
bool vis[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cnt] = i;
		rep(j, 1, cnt){
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
ll getphi(ll x){
	ll ans = x;
	rep(i, 1, cnt){
		int y = p[i];
		if (!(x % y)){
			ans = ans / y * (y - 1);
			while (!(x % y)) x /= y;
		}
	}
	if (x > 1) ans = ans / x * (x - 1);
	return ans;
}

int main(){
	
		//freopen("in1.txt", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	
	init();
	int T;
	read(T);
	while (T--){	
		read(a), read(b);
		ll d = gcd(a, b);
		write(getphi(b / d));
	}	
	return 0;
}