// LUOGU_RID: 92682616
//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, dp[2][N];
char s[2][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d%s%s", &n, s[0]+1, s[1]+1);
		int L = 1, R = n;
		while(L <= n && s[0][L] == '.' && s[1][L] == '.') ++L;
		while(R >= 1 && s[0][R] == '.' && s[1][R] == '.') --R;
		rep(i, L, R) dp[0][i] = dp[1][i] = 0;
		dp[0][L] = (s[1][L] == '*');
		dp[1][L] = (s[0][L] == '*');
		rep(i, L+1, R) {
			dp[0][i] = min(dp[0][i-1] + 1 + (s[1][i] == '*'), dp[1][i-1] + 2);
			dp[1][i] = min(dp[1][i-1] + 1 + (s[0][i] == '*'), dp[0][i-1] + 2);
		}
		printf("%d\n", min(dp[0][R], dp[1][R]));
	}
	return 0;
}