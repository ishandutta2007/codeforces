#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200005
using namespace std;
int n,m,k,deg[N],uu[N],vv[N],ans[N],
to[N<<1],hd[N<<1],lk[N],cnt=1,ss;
bool lit[N],del[N];
void dfs(int x){
	lit[x]=1,ss--;
	for(int s,i=lk[x];i;i=hd[i])
	if(!del[i>>1]){
		del[i>>1]=1;
		if(!lit[s=to[i]]&&--deg[s]<k)
		dfs(s);
	}
}
void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt,deg[u]++;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);ss=n;
	for(int i=1;i<=m;i++)
	scanf("%d%d",uu+i,vv+i),
	add(uu[i],vv[i]),add(vv[i],uu[i]);
	for(int i=1;i<=n;i++)
	if(deg[i]<k&&!lit[i])dfs(i);
	for(int i=m;i;i--){
		ans[i]=ss;
		if(!del[i]){
			if(--deg[uu[i]]<k)
			dfs(uu[i]);
			else{
				del[i]=1;
				if(--deg[vv[i]]<k)
				dfs(vv[i]);
			}
			del[i]=1;
		}
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}