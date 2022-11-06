// Problem: CF66E Petya and Post
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF66E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, inf = 0x3f3f3f3f;

int n, a[N], b[N], dp[N], ok[N], now, mn;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) scanf("%d", &b[i]);
	auto inc = [n](int i) {return i % n + 1;};
	auto dec = [n](int i) {return i == 1 ? n : i - 1;};
	memset(dp, 0, sizeof(dp));
	now = 0; mn = inf;
	rep(i, 1, n) {
		now += a[i] - b[i];
		chkmin(mn, now);
	}
	dp[n+1] = mn;
	per(i, n, 1) {
		dp[i] = dp[i+1] + a[i] - b[i];
		ok[i] |= dp[i] >= 0;
	}
	memset(dp, 0, sizeof(dp));
	now = 0; mn = inf;
	per(i, n, 1) {
		now += a[i] - b[dec(i)];
		chkmin(mn, now);
	}
	dp[0] = mn;
	rep(i, 1, n) {
		dp[i] = dp[i-1] + a[i] - b[dec(i)];
		ok[i] |= dp[i] >= 0;
	}
	printf("%d\n", accumulate(ok+1, ok+1+n, 0));
	rep(i, 1, n) if(ok[i]) printf("%d ", i);
	return 0;
}