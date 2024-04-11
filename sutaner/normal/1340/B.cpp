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
#define maxn 2020
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

int bc[128];
int masks[] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
int a[maxn], res[maxn];
int n, k;
bool vis[maxn][maxn], dp[maxn][maxn];
bool DP(int pos, int rest){
	if (pos > n) return rest == 0;
	if (vis[pos][rest]) return dp[pos][rest];
	vis[pos][rest] = 1;
	bool& ans = dp[pos][rest];
	ans = false;
	per(i, 9, 0){
		if ((a[pos] | masks[i]) != masks[i]) continue;
		if (rest < bc[masks[i] ^ a[pos]]) continue;
		if (DP(pos + 1, rest - bc[masks[i] ^ a[pos]])) {res[pos] = i; return ans = true;}
	}
	return ans;
}

int main(){
	
		//freopen(".in", "r", stdin);
		
	//ios :: sync_with_stdio(false), cin.tie(0);
	//IMPOSSIBLE, POSSIBLE
	bc[0] = 0; rep(i, 1, 127) bc[i] = bc[i >> 1] + (i & 1);
	read(n), read(k);
	rep(i, 1, n){
		char ch = gc();
		while (ch != '0' && ch != '1') ch = gc();
		while (ch == '0' || ch == '1') a[i] = (a[i] << 1) + ch - '0', ch = gc();
	}
	if (!DP(1, k)) printf("-1");
	else rep(i, 1, n) printf("%d", res[i]); 
	return 0;
}