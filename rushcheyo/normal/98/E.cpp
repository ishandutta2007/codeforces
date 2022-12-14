#include<cstdio>
int n,m;
double dp[1005][1005];
double f(int n,int m){
	if(!n)return 1.0/(m+1);
	if(!m)return 1;
	if(dp[n][m])return dp[n][m];
	double A=(1-f(m-1,n))*m/(m+1);
	double B=A+1.0/(m+1);
	double C=1.0;
	double D=1-f(m,n-1);
	double p=(D-C)/(A-B-C+D);
	return dp[n][m]=p*A+(1-p)*C;
}
int main(){
	scanf("%d%d",&n,&m);
	double ans=f(n,m);
	printf("%.10f %.10f\n",ans,1-ans);
}