#include <bits/stdc++.h>
using namespace std;
#define N 4005

int s[N], n;
int dp[2050][190][95][2];
const int inf = -1e9;

int solve(int a, int d, int k, int w){
	int lft = n - a - a + d;
	if(lft < k) return 0;
	int &ans = dp[a][d][k][w];
	if(ans != inf) return ans;
	if(w == 0){
		ans = solve(a + k, d + k, k, 1) + s[a + k] - s[a];
		if(lft >= k + 1) ans = max(ans, solve(a + k + 1, d + k + 1, k + 1, 1) + s[a + k + 1] - s[a]);
	}
	else{
		ans = solve(a, d - k, k, 0) - s[n - a + d] + s[n - a + d - k];
		if(lft >= k + 1) ans = min(ans, solve(a, d - k - 1, k + 1, 0) - s[n - a + d] + s[n - a + d - k - 1]);
	}
	return ans;
}

int main(){
	int i, j, k, l;
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d", &l);
		s[i] += s[i - 1] + l;
	}
	for(i = 0; i < 2050; i++)
	for(j = 0; j < 190; j++)
	for(k = 0; k < 95; k++)
	for(l = 0; l < 2; l++) dp[i][j][k][l] = inf;
	int ans = solve(0, 0, 1, 0);
	printf("%d", ans);
}