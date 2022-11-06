//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 505<<1;

int n, k;
int dp[N][N] = {1}, ans;
queue<int> q;

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) {
		int _;
		scanf("%d", &_);
		for(int p=k;p>=0;p--) {
			for(int q=k;q>=0;q--) {
				if(dp[p][q]) dp[p+_][q] = dp[p][q+_] = 1;
			}
		}
	}
	for(int i=0;i<=k;i++) {
		if(dp[i][k-i]) {
			++ans;
			q.push(i);
		}
	}
	printf("%d\n", ans);
	while(!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
	puts("");
	return 0;
}