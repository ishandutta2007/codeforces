//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int n; double p, dp[2];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%lf", &p);
		dp[1] = dp[1] + (dp[0] * 2 + 1) * p;
		dp[0] = (dp[0] + 1) * p;
	}
	printf("%lf\n", dp[1]);
	return 0;
}//