#include<bits/stdc++.h>
#define N 400005
using namespace std;
typedef long long ll;
int n,to[N],hd[N],lk[N],sz[N],od[N],ev[N],cnt;
ll ans;
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}
void dfs(int x,int y){
	sz[x]=ev[x]=1;
	for(int s,i=lk[x];i;i=hd[i])
	if((s=to[i])^y)
	dfs(s,x),sz[x]+=sz[s],od[x]+=ev[s],ev[x]+=od[s];
	for(int s,i=lk[x];i;i=hd[i])
	if((s=to[i])^y)ans+=1ll*ev[s]*(ev[x]-od[s]);
	if(y)ans+=1ll*sz[x]*(n-sz[x]);
}
int u,v;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1,0);
	printf("%I64d",ans/2);
}