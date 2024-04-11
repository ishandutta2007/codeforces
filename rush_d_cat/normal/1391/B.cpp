#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int t;
int n, m;
char s[N][N];
int dp[N][N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n,&m);
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		int ans=0;
		for(int i=1;i<n;i++){
			if(s[i][m]=='R')ans++;
		}
		for(int j=1;j<=m;j++){
			if(s[n][j]=='D')ans++;
		}
		printf("%d\n", ans);
	}
}