#include<bits/stdc++.h>
const int N=100005,M=500005;
using namespace std;
int n,m,de[N],to[M],hd[M],lk[N],cnt=1;
bool del[M],t;
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}int u,v;
inline void Add(int u,int v){add(u,v),add(v,u);}
void dfs(int x,int y){
	for(int&i=lk[x];i;i=hd[i])
	if(!del[i])
	del[i]=del[i^1]=1,dfs(to[i],x);
	if(y)printf("\n%d %d",t?x:y,t?y:x),t^=1;
}
int main(){
	//freopen("dat.txt","r",stdin);
	for(scanf("%d%d",&n,&m);m--;)
	scanf("%d%d",&u,&v),
	de[u]++,de[v]++,Add(u,v);
	u=0;
	for(int i=1;i<=n;i++)
	if(de[i]&1)u=u?Add(u,i),0:i;
	if((cnt>>1)&1)Add(1,1);
	printf("%d",cnt>>1);
	dfs(1,0);
}