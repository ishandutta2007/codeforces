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
double dp[110][10010];
int n;
int c[110];
int x;
int main(){
	n=read(),x=read();
	double sum=0.0;
	dp[0][0]=1;
	for(int i=1;i<=n;++i) c[i]=read(),sum+=c[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j>=1;--j){
			for(int k=10000;k>=c[i];--k){
				dp[j][k]+=dp[j-1][k-c[i]]*j/(n-j+1);
			}
		}
	}
	double ans=0.0;
	for(int i=0;i<n;++i){
		for(int j=0;j<=10000;++j){
			(ans+=dp[i][j]*min((x/2.0)*(n*1.0/(n-i)+1),(sum-j)*1.0/(n-i)));
		}
	}
	printf("%.9lf\n",ans);
}