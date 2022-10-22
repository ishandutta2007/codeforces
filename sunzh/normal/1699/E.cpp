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
int T,n,m;
int a[1000010];
int dp[5000010],used[5000010];
int cnt[5000010];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=m;++i) dp[i]=i,used[i]=0,cnt[i]=0;
		for(int i=1;i<=n;++i){
			a[i]=read();used[a[i]]=cnt[a[i]]=1;
		}
		if(m==1){
			printf("0\n");continue ;
		}
		sort(a+1,a+n+1);
		int ans=m+1,mx=m;
		for(int mi=m;mi>1;--mi){
			for(int j=mi;1ll*mi*j<=m;++j){
				int nw=dp[j];
				if(used[mi*j]&&nw<dp[mi*j]) --cnt[dp[mi*j]],++cnt[nw];
				dp[mi*j]=min(dp[mi*j],nw);
			}
			while(!cnt[mx]) --mx;
			ans=min(ans,mx-min(mi,a[1]));
		}
		printf("%d\n",ans);
	}
}