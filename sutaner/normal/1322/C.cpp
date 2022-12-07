#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll unsigned long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 600020
#define maxm
#define maxs
#define maxb
#define M 
#define hash HASH
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

ll gcd(ll x, ll y){
	if (!y) return x;
	return gcd(y, x % y);
}

int n, m;
ll hash[maxn], hash2[maxn], v[maxn], v2[maxn], a[maxn];
map<pll, ll> sum; 

int main(){
	
		//freopen("c.in", "r", stdin);
		
	//printf("%d %d %lld %d\n", rand(), rand(), (ll)rand(), rand());
	
	srand(122314243);
		 
	int T, x, y;
	read(T);
	while (T--){
		read(n), read(m);	
		rep(i, 1, n) v[i] = v2[i] = 0, hash[i] = (ll)rand() * rand() * rand() * rand(), hash2[i] = (ll)rand() * rand() * rand() * rand();
		rep(i, 1, n) read(a[i]);
		rep(i, 1, m) read(x), read(y), v[y] ^= hash[x], v2[y] ^= hash2[x];
		rep(i, 1, n) sum[pll(v[i], v2[i])] += a[i]; 
		ll ans = 0;
		bool f = 1;
		rep(i, 1, n) {
			if (!v[i] && !v2[i]) continue;
			if (f) ans = sum[pll(v[i], v2[i])], f = 0;
			else ans = gcd(ans, sum[pll(v[i], v2[i])]); 
		}
		write(ans); sum.clear();
	} 
	return 0;
}