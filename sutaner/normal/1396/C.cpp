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
#define maxr 500020
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

int n;
ll r1, r2, r3, d, a[maxn], mi[maxn], _mi[maxn];

bool vis[maxn][2];
ll dp[maxn][2];
ll DP(int pos, bool f){
	if (!pos) return 0;
	if (vis[pos][f]) return dp[pos][f];
	vis[pos][f] = 1;
	ll& ans = dp[pos][f];
	if (f) {
		ll zero = DP(pos - 1, 0);
		ans = zero + r2 + r1;
		ans = min(ans, zero + (a[pos] + 2) * r1);
		ans = min(ans, zero + a[pos] * r1 + r3); 
		
		ll one = DP(pos - 1, 1);
		ans = min(ans, one + r2 + r1 + 2 * d);
		ans = min(ans, one + (a[pos] + 2) * r1 + 2 * d); 
	}
	else {
		ll one = DP(pos - 1, 1);
		ans = one + r2 + r1 + 2 * d;
		ans = min(ans, one + (a[pos] + 2) * r1 + 2 * d); 
		
		ll zero = DP(pos - 1, 0);
		ans = min(ans, zero + a[pos] * r1 + r3); 
	}
	return ans;
}
int main(){
	ll ans = 0, _ans = 0, res = 0;
	scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d); 
	rep(i, 1, n) scanf("%lld", a + i);
	
	ans = DP(n, 0) + (n - 1) * d, res = ans;
	
	ll suf = 0;
	rep(i, n, n) {
		//ll _ans = ans; 
		mi[i] = r2 + 2 * d + r1;
		mi[i] = min(mi[i], (a[i] + 2) * r1 + 2 * d);
		mi[i] = min(mi[i], a[i] * r1 + r3); 
		suf += mi[i];
		//ans += res;
		//if (i < n) ans += d;
		//cout << i << ':' << ans - _ans << endl;
	} 
	
	per(i, n - 1, 1) {
		mi[i] = r2 + r1;
		mi[i] = min(mi[i], (a[i] + 2) * r1);
		mi[i] = min(mi[i], a[i] * r1 + r3); 
		suf += mi[i];
		ans = DP(i - 1, 0) + (n - 1 + n - i) * d + suf; 
		res = min(res, ans); 
	}
	printf("%lld\n", res);
	return 0;
}