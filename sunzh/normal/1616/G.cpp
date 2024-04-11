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
int T;
int n,m;
vector<int>vec[150010],vec2[150010];
int lnk[1500010];
int L[150010],R[150010];
bool vis[150010][2];
void dfs1(int x,int f){
	// printf("Lx:%d,f:%d\n",x,f);
	if(vis[x][f]) return ;
	vis[x][f]=1;
	for(int v:vec2[x+1]){
		if(v+1>=L[x]) dfs1(v,!f);
	}
}
void dfs2(int x,int f){
	// printf("Rx:%d,f:%d\n",x,f);
	if(vis[x][f]) return ;
	vis[x][f]=1;
	for(int v:vec[x]){
		if(v-1<=R[x+1]) dfs2(v-1,!f);
	}
}
int check(int x,int y){
	return (vis[x][0]&&vis[y-1][0])||(vis[x][1]&&vis[y-1][1]);
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) vector<int>().swap(vec[i]),vector<int>().swap(vec2[i]);
		memset(lnk,0,sizeof(lnk));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;++i){
			int u=read(),v=read();
			if(u+1==v) lnk[u]=1;
			else{
				vec[u].pb(v);vec2[v].pb(u);
			}
		}
		for(int i=1;i<=n;++i){
			if(i>1) vec2[i].pb(0);if(i<n) vec[i].pb(n+1);
		}
		lnk[0]=lnk[n]=1;
		L[0]=0;
		for(int i=1;i<=n+1;++i){
			L[i]=(lnk[i-1]?L[i-1]:i);
			// printf("L[%d]=%d\n",i,L[i]);
		}
		R[n+1]=n+1;
		for(int i=n;i>=0;--i) R[i]=(lnk[i]?R[i+1]:i);
		if(L[n+1]==0){
			printf("%lld\n",1ll*n*(n-1)>>1);continue ;
		}
		int p=-1;
		for(int i=1;i<n;++i) if(!lnk[i]){
			p=i;break ;
		}
		dfs1(p,1);vis[p][1]=0;dfs2(p,1);
		int cnt1=0,cnt2=0;
		for(int i=0;i<=R[0];++i) cnt1+=vis[i][0];
		for(int i=L[n+1]-1;i<=n;++i) cnt2+=vis[i][0];
		long long ans=1ll*cnt1*cnt2;cnt1=0,cnt2=0;
		for(int i=0;i<=R[0];++i) cnt1+=vis[i][1];
		for(int i=L[n+1]-1;i<=n;++i) cnt2+=vis[i][1];
		ans+=1ll*cnt1*cnt2;cnt1=0,cnt2=0;
		for(int i=0;i<=R[0];++i) cnt1+=(vis[i][1]&&vis[i][0]);
		for(int i=L[n+1]-1;i<=n;++i) cnt2+=(vis[i][1]&&vis[i][0]);
		ans-=1ll*cnt1*cnt2;
		// printf("%lld,%lld,%lld\n",ans,R[0],L[n+1]);
		if(R[0]==L[n+1]-1) ans-=check(R[0],R[0])+check(L[n+1],L[n+1])+check(R[0],L[n+1]);
		else if(R[0]==L[n+1]-2) ans-=check(R[0]+1,L[n+1]-1);
		printf("%lld\n",ans);

	}
}