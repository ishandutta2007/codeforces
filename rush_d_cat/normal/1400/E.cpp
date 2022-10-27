#include <bits/stdc++.h>
using namespace std;
const int N = 5002;
typedef long long LL;

int n; 
int a[N],b[N],dp[N][N];
vector<int> v;
int id(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin();
}
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
		v.push_back(a[i]);
	}
	v.push_back(0);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());

	for(int i=1;i<=n;i++){
		b[i]=id(a[i]);
	}

	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=1e9;
	dp[0][0]=0;
	
	for(int i=1;i<=n;i++){
		int pre[N]={0},suf[N]={0};
		for(int j=0;j<N;j++)pre[j]=1e9,suf[j]=1e9;
		for(int j=0;j<v.size();j++){
			if(j>=1) pre[j]=min(pre[j-1],dp[i-1][j]-v[j]);
			else pre[j]=dp[i-1][0];
		}
		for(int j=(int)v.size()-1;j>=0;j--){
			suf[j]=min(suf[j+1],dp[i-1][j]);
		}
		for(int j=0;j<=b[i];j++){
			dp[i][j]=min(pre[j]+v[j], suf[b[i]]);
			//printf("# %d %d\n", pre[j]+v[j], suf[b[i]]);
			if(j!=b[i]) dp[i][j]++;

			//printf("dp[%d][%d] = %d\n", i,j,dp[i][j]);
		}
	}
	int ans=1e9;
	for(int i=0;i<v.size();i++)ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
}