#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, k;
char s[N];
int sum[N][27];
bool ok[N][27];
int nex[N][27];
int dp[1<<17];
bool chk(int x) {
	memset(ok,0,sizeof(ok));
	memset(nex,-1,sizeof(nex));
	for (int i = n - x + 1; i >= 1; i --) {
		for (int j = 0; j < 26; j ++) {
			ok[i][j] = (sum[i+x-1][j] - sum[i-1][j] + sum[i+x-1][26] - sum[i-1][26] == x);
			if (ok[i][j]) nex[i][j] = i; else nex[i][j] = nex[i+1][j];
		}
	} 
	for (int i = 0; i < 1<<k; i ++) dp[i] = 1e9;
	dp[0] = 0;
	for (int i = 0; i < 1<<k; i ++) {
		if (dp[i] > n) continue;
		for (int j = 0; j < k; j ++) {
			if ((i>>j&1) == 0) {
				int r = nex[dp[i]+1][j] + x - 1; if (nex[dp[i]+1][j] == -1) r = 1e9;
				dp[i|(1<<j)] = min(dp[i|(1<<j)], r);
			}
		}
	} 
	return dp[(1<<k)-1] <= n;
}
int main() {
	scanf("%d%d%s", &n, &k, s+1);
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 27; j ++) sum[i][j] = sum[i-1][j];
		if (s[i] == '?') sum[i][26] ++; else sum[i][s[i]-'a'] ++;
	}

	if(!chk(1)) {
		cout<<0<<endl; return 0;
	}
	int lef=1,rig=n+1;
	while (rig-lef>1){
		int mid=(lef+rig)>>1;
		if(chk(mid)) lef=mid; else rig=mid;
	}
	cout<<lef<<endl;

}