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
int n,L,R;
int a[10010],b[10010];
int dp[10010];
int id[100010];
int main(){
	n=read(),L=read(),R=read();
	int sum=0;
	for(int i=1;i<=n;++i) a[i]=read(),sum+=a[i],id[i]=i;
	for(int i=1;i<=n;++i) b[i]=read();
	int tl=sum-R,tr=sum-L,ans=0;memset(dp,-0x3f,sizeof(dp));dp[0]=0;
	sort(id+1,id+n+1,[&](int x,int y){return b[x]==b[y]?a[x]>a[y]:b[x]<b[y];});
	for(int i=1;i<=n;++i){
		for(int j=sum;j>=a[id[i]];--j){
			dp[j]=max(dp[j],dp[j-a[id[i]]]+(b[id[i]]&&j>=tl&&j<=tr));ans=max(ans,dp[j]);
		}
	}
	printf("%d\n",ans);
}