#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=105,P=1000000007;
int n,p,m,sg[M],t[M],cnt[3],dp[N][4];
int mex(int a,int b){
	if(a&&b)return 0;
	return a+b==1?2:1;
}
int sum(int l,int r){return (l+r)*(r-l+1ll)/2%P;}
void inc(int &a,int b){a+=b;if(a>=P)a-=P;}
int main(){
	scanf("%d%d",&n,&p);
	m=1;
	sg[1]=0;
	t[1]=2;
	for(int l=1,r=1;t[m]<p;){
		int x=t[m]+1;
		while(x/3>t[l])l++;
		while(x-x/3>t[r])r++;
		sg[++m]=mex(sg[l],sg[r]);
		t[m]=x+min(t[l]-x/3,t[r]-(x-x/3));
		if(sg[m]==sg[m-1])t[m-1]=t[m],m--;
	}
	t[m]=min(t[m],p);
	for(int i=1;i<=m;i++)
		inc(cnt[sg[i]],sum(p-t[i],p-t[i-1]-1));
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=3;j++)
			for(int k=0;k<=2;k++)
				inc(dp[i+1][j^k],1ll*dp[i][j]*cnt[k]%P);
	int ans=0;
	for(int i=1;i<=3;i++)inc(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}