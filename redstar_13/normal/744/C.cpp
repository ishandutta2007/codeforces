#include<bits/stdc++.h>

using namespace std;

typedef long long INT;


#define NN 16
#define MM 222
#define inf 0x3f3f3f3f

int col[NN];
int cnt_r[NN], cnt_b[NN];
int n;
int dp[(1<<NN)][MM];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	cin>>n;
	int tot = 0;
	for(int i=0; i<n; i++) scanf(" %c %d %d", col+i, cnt_r+i, cnt_b+i), tot += cnt_r[i];
	memset(dp, inf, sizeof dp);
	
	dp[0][0] = 0;
	
	for(int i=0; i<(1<<n); i++) {
		int cur_r = 0, cur_b = 0;
		
		for(int j=i; j; j-=j&-j) {
			if(col[__builtin_ctz(j)] == 'R') cur_r++;
			else cur_b++;
		}
		
		for(int j=0; j<MM; j++) if(dp[i][j] != inf) {
			for(int k=0; k<n; k++) if(!((i>>k) & 1)) {
				int p = min(cur_r, cnt_r[k]);
				int q = max(0, cnt_b[k] - cur_b);
				dp[i+(1<<k)][j+p] = min(dp[i+(1<<k)][j+p], dp[i][j]+q);
			}
		}
	}
	
	int ans = inf;
	
	for(int i=0; i<MM; i++) ans = min(ans, max(dp[(1<<n)-1][i], tot-i));
	
	cout<<ans+n<<endl;
}