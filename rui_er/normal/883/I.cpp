//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 3e5+5, inf = 0x3f3f3f3f;

int n, m, a[N], dp[N]; // dp[i] : 1~i  
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool check(int M) {
	memset(dp, 0, sizeof(dp));
	int j = 0;
	rep(i, m, n) {
		if(a[i] - a[dp[i-m]+1] <= M) j = i;
		dp[i] = j;
	}
	return dp[n] == n;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	int L = 0, R = a[n] - a[1] + 1;
	while(L < R) {
		int M = (L + R) >> 1;
		if(check(M)) R = M;
		else L = M + 1;
	}
	printf("%d\n", L);
	return 0;
}