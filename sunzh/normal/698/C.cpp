#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,k;
int cnt;
double p[25];
const double eps=1e-15;
double dp[1<<21],ans[21];
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) scanf("%lf",&p[i]),cnt+=(p[i]>eps);
	if(cnt<=k){
		for(int i=1;i<=n;++i){
			if(p[i]<=eps) printf("0 ");
			else printf("1 ");
		}
		return 0;
	}
	dp[0]=1.0;
	for(int S=0;S<(1<<n);++S){
//		printf("S:%d,dp:%.5lf\n",S,dp[S]);
		int c=0;
		for(int i=1;i<=n;++i) if(S&(1<<i-1)) ++c;
		if(c==k){
			for(int i=1;i<=n;++i) if(S&(1<<i-1)) ans[i]+=dp[S];
			continue ;
		}
		if(dp[S]<=eps) continue ;
		double tmp=0.0;
		for(int i=1;i<=n;++i) if(S&(1<<i-1)) tmp+=p[i];
//		printf("%.5lf\n",tmp);
		dp[S]=dp[S]/(1.0-tmp);
//		for(int i=1;i<=n;++i) if(!(S&(1<<i-1))) printf("t:%d,d:%.5lf\n",i,dp[S]*p[i]);
		for(int i=1;i<=n;++i) if(!(S&(1<<i-1))) dp[S|(1<<i-1)]+=dp[S]*p[i];
	}
	for(int i=1;i<=n;++i) printf("%.8lf ",ans[i]);
	return 0;
}