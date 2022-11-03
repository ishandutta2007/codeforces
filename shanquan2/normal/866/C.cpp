#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;

int n,r,f[55],s[55];
double p[55],dp[55][6005];
double calc(double t){
	for(int i=n-1;i>=0;i--)for(int j=0;j<=r;j++){
		dp[i][j]=(f[i]+dp[i+1][j+f[i]])*p[i]+(s[i]+min(t,dp[i+1][j+s[i]]))*(1-p[i]);
	}
	return dp[0][0];
}
int main(){
	scanf("%d%d",&n,&r);
	for(int i=0;i<n;i++)scanf("%d%d%lf",&f[i],&s[i],&p[i]),p[i]/=100;
	for(int i=0;i<=n;i++)for(int j=r+1;j<=r+105;j++)dp[i][j]=1e100;
	double h=0,t=1e8;
	while(h<t-eps&&t>(1+eps)*h){
		double x=(h+t)/2.0;
//		printf("%lf %lf %lf\n",h,t,h*(1+eps));
		if(calc(x)<=x)t=x;else h=x;
	}
	printf("%.9lf\n",h);
	return 0;
}