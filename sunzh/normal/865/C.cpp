#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
long double dp[60][5110];
const int MAXN=5100;
int a[60],b[60],p[60];
const long double eps=1e-11;
long double check(long double x){
	memset(dp,0,sizeof(dp));
	for(int i=n;i>=1;--i){
		for(int j=0;j<=m;++j){
			long double t1,t2;
			if(j+a[i]<=m) t1=p[i]*(a[i]+dp[i+1][j+a[i]])*1.0L/100.0L;
			else t1=p[i]*(a[i]+x)*1.0L/100.0L;
			if(j+b[i]<=m) t2=(100-p[i])*(b[i]+dp[i+1][j+b[i]])*1.0L/100.0L;
			else t2=(100-p[i])*(b[i]+x)/100.0L;
			dp[i][j]=min(t1+t2,x);
		}
	}
//	printf("%.10Lf\n",dp[1][0]);
	return dp[1][0];
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=read(),p[i]=read();
	long double l=0,r=1e10;
	while((r-l)>eps){
		long double mid=(l+r)/2.0L;
		long double c=check(mid);
		if(c>=mid) l=mid+eps;
		else r=mid-eps;
	}
	printf("%.10Lf\n",l);
	return 0;
}