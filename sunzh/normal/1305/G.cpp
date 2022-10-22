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
#include<random>
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
int n;
int a[200010];
int fa[300010];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct nd{
	PII bst,sec;
}dp[1<<19];
nd merge(nd x,nd y){
	nd res;
	if(x.bst.fi<y.bst.fi) res.bst=y.bst,y.bst=y.sec;else res.bst=x.bst,x.bst=x.sec;
	PII vx=mp(-1,0),vy=mp(-1,0);
	if(find(x.bst.second)!=find(res.bst.second)) vx=x.bst;
	else if(find(x.sec.second)!=find(res.bst.second)) vx=x.sec;
	if(find(y.bst.second)!=find(res.bst.second)) vy=y.bst;
	else if(find(y.sec.se)!=find(res.bst.se)) vy=y.sec;
	if(vx>vy) res.sec=vx;else res.sec=vy;
	return res;
}
int val[300010],to[300010];
const int N=(1<<18);
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n+1;++i) fa[i]=i;
	long long ans=0;
	for(int i=1;i<=n;++i) ans-=a[i];
	int cnt=n+1;
	while(cnt>1){
		for(int i=0;i<N;++i){
			dp[i]=nd{mp(-1,0),mp(-1,0)};
		}
		dp[0]=nd{mp(0,n+1),mp(-1,0)};
		for(int i=1;i<=n;++i){
			val[i]=-1;to[i]=0;
			dp[a[i]]=merge(dp[a[i]],nd{mp(a[i],i),mp(-1,0)});
		}val[n+1]=-1,to[n+1]=0;
		for(int j=0;j<N;++j){
			for(int i=0;i<18;++i) if(j&(1<<i)) dp[j]=merge(dp[j],dp[j^(1<<i)]);
		}
		for(int i=1;i<=n+1;++i){
			int S=(N-1)^a[i];//printf("S:%d\n",S);
			if(dp[S].bst.se&&find(i)!=find(dp[S].bst.se)){
				if(a[i]+dp[S].bst.fi>=val[find(i)]) val[find(i)]=a[i]+dp[S].bst.fi,to[find(i)]=find(dp[S].bst.se);
			}
			else if(dp[S].sec.se&&find(i)!=find(dp[S].sec.se)){
				if(a[i]+dp[S].sec.fi>=val[find(i)]) val[find(i)]=a[i]+dp[S].sec.fi,to[find(i)]=find(dp[S].sec.se);
			}
		}
		for(int i=1;i<=n+1;++i) if(fa[i]==i){
			if(to[i]==0) continue ;
			if(find(to[i])!=find(i)){
				// printf("i:%d,%d %d\n",i,val[i],to[i]);
				ans+=val[i];fa[find(i)]=find(to[i]);--cnt;
			}
		}
	}
	printf("%lld\n",ans);
}