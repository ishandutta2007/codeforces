#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
double dp[1010][1010];
int n,m;
int a[1010];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) dp[i][j]=(a[i]>a[j]);
	}
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		for(int j=1;j<=n;++j) if(j!=x&&j!=y){
			dp[j][x]=dp[j][y]=(dp[j][x]+dp[j][y])/2.0;
			dp[x][j]=dp[y][j]=1-dp[j][x];
		}
		dp[x][y]=dp[y][x]=0.5;
	}
	double ans=0.0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j) ans+=dp[i][j];
	}
	printf("%.6lf\n",ans);
}