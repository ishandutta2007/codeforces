#include<bits/stdc++.h>
using namespace std;
const int N=400005;
map<int,int>mx,my;
int m,n,deg[N],rb[N],
to[N],hd[N],lk[N],cnt=1,
q[N*2],h,t;
bool del[N],ans[N],typ;
int u,v;
inline void add(int u,int v){
	deg[u]++,to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}
void dfs(int x,int y){
	for(int &i=lk[x];i;i=hd[i])
	if(!del[i])
	del[i]=del[i^1]=1,dfs(to[i],i);
	ans[y]=ans[y^1]=typ,typ^=1;
}
void sol(){
	int x;
	for(;h<t&&!(deg[x=q[h++]]&1););
	if(h<t){
		//cerr<<"should find\n";
		for(int s,now,&i=lk[x];i;i=hd[i])
		if(!del[i]){
			del[i]=del[i^1]=1;
			s=to[i],q[t++]=s,deg[s]--,deg[x]--;
			//cerr<<"find "<<x<<"->"<<s<<endl;
			now=i,sol();
			//cerr<<x<<"->"<<s<<":"<<rb[s]<<"?\n";
			if(rb[s]>0)rb[s]--,rb[x]--;
			else rb[s]++,rb[x]++,ans[now]=ans[now^1]=1;
			return;
		}
	}
	for(int i=1;i<=n;i++)
	//cerr<<"fu.\n",
	dfs(i,0);
}
int main(){
//	freopen("dat.txt","r",stdin);
	for(scanf("%d",&m);m--;){
		scanf("%d%d",&u,&v);
		if(!mx[u])mx[u]=++n;
		if(!my[v])my[v]=++n;
		u=mx[u],v=my[v];
		//cerr<<"init "<<u<<','<<v<<endl;
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++)q[t++]=i;
	sol();
	for(int i=2;i<cnt;i+=2)
	putchar(ans[i]?'r':'b');
}