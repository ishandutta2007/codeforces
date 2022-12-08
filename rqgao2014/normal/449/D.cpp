#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod=1e9+7;
int n,m,dp[2][1200005],f[1200005];

inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}

int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&n);
	int k=0;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		dp[k][x]++;m=max(m,x);
		f[x]++;
	}
	n=2;
	while(n<=m) n<<=1;
	for(int i=1;i<20;i++){
		k^=1;
		for(int j=0;j<n;j++){
			dp[k][j]=0;
			for(int l=0;l<20;l++)
				if(!(j&(1<<l))) dp[k][j]+=dp[k^1][j^(1<<l)];
			dp[k][j]/=i;
			f[j]=f[j]+dp[k][j];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(f[i]<0) return 0;
		int num=0,t=exp(2,f[i]);
		for(int j=0;j<20;j++) if(i&(1<<j)) num++;
		if(num&1) ans=(ans-t+mod)%mod; else ans=(ans+t)%mod;
	}
	printf("%d\n",ans);
}

/*
3
0 0 0
*/