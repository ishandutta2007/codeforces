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
#define maxn 3020
#define maxm
#define maxs
#define maxb
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
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

int n, m;
char s[maxn], t[maxn];
int two[maxn];
bool vis[maxn][maxn];
int dp[maxn][maxn];
int DP(int l, int r){ 
	//if (l > m) return two[r - l + 1];
	if (l > r) return 1; 
	if (vis[l][r]) return dp[l][r];
	int& ans = dp[l][r];
	//ans = (l > m) ? 1 : 0;
	vis[l][r] = 1; 
	if (r <= m){
		ans = ((s[1 + r - l] == t[l]) ? DP(l + 1, r) : 0) + ((s[1 + r - l] == t[r]) ? DP(l, r - 1) : 0);
		mo(ans);
	}
	else {
		ans = DP(l, r - 1) + ((l > m || s[1 + r - l] == t[l]) ? DP(l + 1, r) : 0);
		mo(ans);
	}
	return ans;
	//if (s[ps] == t[pt]) {ans = DP(ps - 1, pt + 1) + DP(ps - 1, pt), mo(ans); return ans;}
	//else return ans = DP(ps - 1, pt);
}

int main(){
	
		//freopen("in1.txt", "r", stdin);
		
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	two[0] = 1; rep(i, 1, n) two[i] = two[i - 1] << 1, mo(two[i]);
	int ans = 0;
	rep(i, m, n) ans += DP(1, i), mo(ans); 
	write(ans);
	return 0;
}