#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n;
vector<int>vec[200010];
bool lef[200010];
int ans=0;
void dfs(int x,int f){
	lef[x]=1;
	for(int v:vec[x]){
		if(v==f) continue ;dfs(v,x);
		if(lef[v]==1) lef[x]=0;
	}
}
int main(){
	T=read();
	while(T--){
		ans=0;
		n=read();for(int i=1;i<=n;++i) vec[i].clear(),lef[i]=0;
		for(int i=1;i<n;++i){
			int u=read(),v=read();vec[u].pb(v);vec[v].pb(u);
		}
		dfs(1,0);
		// for(int i=1;i<=n;++i) printf("lef[%d]:%d\n",i,lef[i]);
		for(int i=1;i<=n;++i) ans+=lef[i]-(!lef[i]);
		printf("%d\n",ans+(!lef[1]));
	}
}