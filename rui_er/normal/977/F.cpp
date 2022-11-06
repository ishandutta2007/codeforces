//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n, a[N], ansDP, ansNum;
map<int, int> dp;

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		dp[a[i]] = max(dp[a[i]], dp[a[i]-1]+1);
		if(dp[a[i]] > ansDP) {ansDP = dp[a[i]]; ansNum = a[i];}
	}
	printf("%d\n", ansDP);
	for(int i=1;i<=n;i++) if(a[i] == ansNum - ansDP + 1) printf("%d ", i), --ansDP;
	return 0;
}