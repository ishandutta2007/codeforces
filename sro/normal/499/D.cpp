#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007
//Original code by: dreamoon

double dp[5005][5005];
int p[5005],t[5005];

double ksmii(double a,int b){
	double ans=1;
	while(b){
		if(b&1){
			ans*=a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}

int main(){
	int n,T;
	scanf("%d%d",&n,&T);
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		scanf("%d%d",p+i,t+i);
	}
	double ans=0;
	for(int i=0;i<n;i++){
		double pp=p[i]/100.0;
		double now=0;
		double r=ksmii(1-pp,t[i]-1)*pp;
		double rr=ksmii(1-pp,t[i]-1);
		for(int j=0;j<T;j++){
			now*=1-pp;
			now+=dp[i][j]*pp;
			if(j+1>=t[i]){
				now-=dp[i][j+1-t[i]]*r;
				dp[i+1][j+1]=now+dp[i][j+1-t[i]]*rr;
			}else{
				dp[i+1][j+1]=now;
			}
		}
		for(int j=0;j<=T;j++){
			ans+=dp[i+1][j];
		}
	}
	printf("%.16f\n",ans);
	return 0;
}
//Code with KSMII