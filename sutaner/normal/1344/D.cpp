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
#define eps 1e-8
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
	if (!x) {putchar('0'), putchar(' '); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(' ');
}

int n;
ll a[maxn], k;
ll ans[maxn];

inline ll cal(ll x){
	return -(3 * x * x + 2 * x + 1);
}

inline ll cal2(ll x){
	return 3 * x * x + 3 * x + 1;
}

inline ll cal3(ll x, ll a){
	return a - 3 * x * x - 3 * x - 1;
}

int solve(int l, int r, ll x){
	while (l < r){
		int mid = ((r - l + 1) >> 1) + l;
		if ((cal2(mid)) > x) r = mid - 1;
		else l = mid;
	}
	return l;
}

bool judge(ll x){
	ll sum = 0;
	rep(i, 1, n){
		//ll v = a[i] - x;
		//double res = (-3 + sqrt(12.0 * v - 3)) / 6.0; 
		//ans[i] = (ll)res;
		//if (ans[i] + 1 - res < eps) ans[i]++;
		ans[i] = solve(0, a[i], a[i] - x);
		sum += ans[i];
	}
	return sum >= k;
}

ll solve(ll l, ll r){
	while (l < r){
		ll mid = ((r - l + 1) >> 1) + l;
		if (judge(mid)) l = mid; //full k
		else r = mid - 1;
	}
	//printf("%lld\n", l);
	judge(l);
	return l;
	//printf("%lld\n", l);
}


int main(){ 
	read(n), read(k);
	rep(i, 1, n) read(a[i]);
	ll mi = a[1];
	rep(i, 2, n) mi = min(mi, a[i]);
	ll mi2 = cal(a[1]);
	rep(i, 2, n) mi2 = min(mi2, cal(a[i]));
	ll tag = solve(mi2 - 1, mi), _k = 0;
	rep(i, 1, n) _k += ans[i];
	rep(i, 1, n){
		if (_k == k) break;
		else {
			if (cal3(ans[i], a[i]) == tag) ans[i]--, _k--;
		}
	}
	rep(i, 1, n) write(ans[i]);
	return 0;
}