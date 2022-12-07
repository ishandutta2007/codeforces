#include <bits/stdc++.h>
#define maxr 100000
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
#define maxn 200019
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') ch = gc(), f = 0;
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}

int n, m;
char s[maxn];

int num[25][25];
bool vis[(1 << 20) + 19];
int dp[(1 << 20) + 19];
int DP(int op){
	if (vis[op]) return dp[op];
	vis[op] = 1;
	int& ans = dp[op]; ans = -1;
	int s = 1;
	rep(i, 1, 20) if (op & (1 << (i - 1))) s++;
	if (s == 21) return ans = 0;
	rep(i, 1, 20){
		if (op & (1 << (i - 1))) continue;
		int nnum = 0;
		rep(j, 1, 20){
			if (i == j) continue;
			if (op & (1 << (j - 1))) nnum += num[min(i, j)][max(i, j)];
			else nnum -= num[min(i, j)][max(i, j)];
		}
		ans = (ans == -1) ? (DP(op | (1 << (i - 1))) + nnum * s) : min(ans, (DP(op | (1 << (i - 1))) + nnum * s));
	}
	return ans;
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	srep(i, 1, n){
		int x = s[i - 1] - 'a' + 1, y = s[i] - 'a' + 1;
		if (x > y) swap(x, y);
		num[x][y]++;
	}
	printf("%d", DP(0));
	return 0;
}