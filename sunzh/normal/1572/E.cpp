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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,k;
struct node{
	int x,y;
}a[210];
PII dp[210][210];
node operator -(node x,node y){
	return node{x.x-y.x,x.y-y.y};
}
int operator *(node x,node y){
	return x.x*y.y-x.y*y.x;
}
int get(int i,int j,int k){
	return (a[j]-a[i])*(a[k]-a[i]);
}
int check(int mid){
	for(int i=1;i<=n;++i){
		for(int j=i+2;j<=n;++j) dp[i][j]=mp(-1e8,-1e8);
	}
	for(int l=3;l<=n;++l){
		for(int i=1;i+l-1<=n;++i){
			int j=i+l-1;
			for(int k=i;k<=j;++k){
				PII nw=mp(dp[i][k].fi+dp[k][j].fi,dp[i][k].se+dp[k][j].se+get(i,k,j));
				if(nw.se>=mid) ++nw.fi,nw.se=0;
				dp[i][j]=max(dp[i][j],nw);
			}
			// printf("i:%d,j:%d,%lld %lld\n",i,j,dp[i][j].fi,dp[i][j].se);
		}
	}
	return dp[1][n].fi>=k+1;
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	int l=0,r=1e18,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
}