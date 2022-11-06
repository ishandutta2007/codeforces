//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, a[N], tp[N], dp[2][N], b[N], c[N], tB, tC, len, s[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void dpLIS() {
	memset(b, 0, sizeof(b));
	b[tB=1] = a[1];
	dp[0][1] = 1;
	rep(i, 2, n) {
		if(b[tB] < a[i]) {
			b[++tB] = a[i];
			dp[0][i] = tB;
		}
		else {
			auto p = lower_bound(b+1, b+1+tB, a[i]);
			dp[0][i] = p - b;
			*p = a[i];
		}
	}
	len = tB;
}
void dpLDS() {
	memset(c, 0, sizeof(c));
	c[tC=1] = a[1];
	dp[1][1] = 1;
	rep(i, 2, n) {
		if(c[tC] > a[i]) {
			c[++tC] = a[i];
			dp[1][i] = tC;
		}
		else {
			auto p = lower_bound(c+1, c+1+tC, a[i], greater<int>());
			dp[1][i] = p - c;
			*p = a[i];
		}
	}
	len = tC;
}
void genLIS() {
	per(i, n, 1) {
		if(!tB) break;
		if(dp[0][i] == tB) b[tB--] = i;
	}
}
void genLDS() {
	per(i, n, 1) {
		if(!tC) break;
		if(dp[1][i] == tC) c[tC--] = n - i + 1;
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		tp[i] = 1;
	}
	dpLIS();
	genLIS();
	reverse(a+1, a+1+n);
	dpLDS();
	genLDS();
	reverse(a+1, a+1+n);
	reverse(dp[1]+1, dp[1]+1+n);
//	rep(i, 1, n) printf("%d %d\n", dp[0][i], dp[1][i]);
//	rep(i, 1, len) printf("%d%c", b[i], " \n"[i==len]); puts("");
//	rep(i, 1, len) printf("%d%c", c[i], " \n"[i==len]); puts(""); 
	rep(i, 1, n) if(dp[0][i] + dp[1][i] - 1 == len) tp[i] = 2;
	rep(i, 1, len) ++s[b[i]];
	rep(i, 1, len) if(s[c[i]]) tp[c[i]] = 3;
	rep(i, 1, n) printf("%d", tp[i]); puts("");
	return 0;
}