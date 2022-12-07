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
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define maxk 20
#define maxn 500020
#define maxm
#define maxs
#define maxb
#define M 998244353
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

ll fac[maxn], ifac[maxn], inv[maxn];
void init(){
	fac[0] = ifac[0] = inv[1] = 1;
	srep(i, 1, maxn) fac[i] = fac[i - 1] * i % M;
	srep(i, 2, maxn) inv[i] = M - M / i * inv[M % i] % M;
	srep(i, 1, maxn) ifac[i] = ifac[i - 1] * inv[i] % M;
}
ll cal(int m, int n){
	if (m < n) return 0;
	return fac[m] * ifac[m - n] % M * ifac[n] % M;
}

int n, k;

/*
int n, k;
bool vis[maxk][maxn];
int dp[maxk][maxn];
ll DP(int pos, int nowd){
	if (pos > k) return 1;
	if (vis[pos][nowd]) return dp[pos][nowd];
	vis[pos][nowd] = 1;
	int& ans = dp[pos][nowd];
	rep(i, 1, n){
		if (nowd * i > n) break;
		ans += DP(pos + 1, nowd * i);
		mo(ans);
	}
	return ans;
}
*/

int main(){
	init();
	scanf("%d%d", &n, &k);
	int ans = 0;
	rep(i, 1, n){
		int num = n / i - 1;
		if (num < k - 1) break;
		ans += cal(num, k - 1);
		mo(ans);
	}
	printf("%d", ans);
	/*
	int x = 1;
	bool f = 1;
	srep(i, 1, k){
		x <<= 1;
		if (x > n) {f = 0; break;}
	}
	if (!f) {printf("0"); return 0;}
	int ans = 0;
	rep(i, 1, n){
		ans += DP(2, i); 
		mo(ans);
	}
	printf("%d", ans);
	*/
	return 0;
}