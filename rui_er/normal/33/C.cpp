//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5; 

int n, a[N], s, dp[N], t;

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	for(int i=1;i<=n;i++) dp[i] = max(dp[i-1], 0) + a[i], t = max(t, dp[i]);
	printf("%d\n", 2*t-s);
	return 0;
}