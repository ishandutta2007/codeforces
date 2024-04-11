#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long INT;
#define NN 1000010
#define MM 20
int p[NN],mn[NN],np;
int dp[NN][MM],Dp[NN][MM];

void prepare(){
	for(int i=2;i<NN;i++){
		if(!mn[i]){
			p[np++]=i;
			mn[i]=i;
		}
		for(int j=0;j<np&&p[j]*i<NN;j++){
			mn[i*p[j]]=p[j];
			if(mn[i]==p[j]) break;
		}
	}
	for(int i=0;i<NN;i++){
		for(int j=0;j<MM;j++){
			if(i==0){
				if(j) dp[i][j]=2;
				else dp[i][j]=1;
			}
			else dp[i][j]=Dp[i-1][j];
			if(j) Dp[i][j]=Dp[i][j-1]+dp[i][j];
			else Dp[i][j]=dp[i][j];
			if(Dp[i][j]>=mod) Dp[i][j]-=mod;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	prepare();
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int r,n;
		scanf("%d%d",&r,&n);
		int ans=1;
		while(n>1){
			int q=mn[n];
			int ct=0;
			while(n%q==0){
				n/=q;
				ct++;
			}
			ans=(INT)ans*dp[r][ct]%mod;
		}
		printf("%d\n",ans);
	}
    return 0;
}