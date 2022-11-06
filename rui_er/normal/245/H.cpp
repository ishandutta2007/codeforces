//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e3+5;

int n, m, palin[N][N], dp[N][N];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	rep(i, 1, n) palin[i][i] = 1;
	rep(i, 1, n-1) palin[i][i+1] = (s[i] == s[i+1]);
	rep(dt, 2, n-1) {
		rep(L, 1, n-dt) {
			int R = L + dt;
			palin[L][R] = (palin[L+1][R-1] && s[L] == s[R]);
		}
	}
	rep(i, 1, n) dp[i][i] = 1;
	rep(i, 1, n-1) dp[i][i+1] = 2 + palin[i][i+1];
	rep(dt, 2, n-1) {
		rep(L, 1, n-dt) {
			int R = L + dt;
			dp[L][R] = dp[L+1][R] + dp[L][R-1] - dp[L+1][R-1] + palin[L][R];
		}
	}
	for(scanf("%d", &m);m;m--) {
		int L, R;
		scanf("%d%d", &L, &R);
		printf("%d\n", dp[L][R]);
	}
	return 0;
}