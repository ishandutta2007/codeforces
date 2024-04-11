#include<bits/stdc++.h>
using namespace std;

struct fe{
	int nxt,w;
}a[500005];
struct edge{
	int nxt,to;
}e[500005],E[1000005];
int Rt,n,dep[1000005],ft[500005],Ft[1000005],cnt,m=1;
long long f[1000005];
void dfs0(int x){
	for(int i=ft[x];i;i=e[i].nxt){
		int y=e[i].to;
		dep[y]=dep[x]+1;
		dfs0(y);
	}
}
void dfs(int x){
	for(int i=ft[x];i;i=e[i].nxt){
		int y=e[i].to;dfs(y);
		if(!a[x].nxt){a[x].nxt=y;continue;}
		int z=a[x].nxt;
		for(;y;y=a[y].nxt,z=a[z].nxt){
			E[m]=(edge){Ft[cnt],a[z].w},Ft[cnt]=m++;
			E[m]=(edge){Ft[cnt],a[y].w},Ft[cnt]=m++;
			f[cnt]=f[a[y].w]+f[a[z].w];
			dep[cnt]=dep[x];
			a[z].w=cnt++;
			if(!a[z].nxt){
				a[z].nxt=a[y].nxt;
				break;
			}
		}
	}
}
void dfs1(int x){
	for(int i=Ft[x];i;i=E[i].nxt){
		int y=E[i].to;f[y]=f[x]+1ll*(dep[y]-dep[x])*f[y];
		dfs1(y);
	}
}
void dfs2(int x){
	for(int i=ft[x];i;i=e[i].nxt){
		int y=e[i].to;f[y]+=f[x];
		dfs2(y);
	}
}
int main(){
	scanf("%d",&n);cnt=n+1;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		e[i]=(edge){ft[x],i};ft[x]=i;
		if(!x)Rt=i;
	}
	dep[Rt]=1;dfs0(Rt);
	for(int i=1;i<=n;i++)a[i]=(fe){0,i},f[i]=1;
	dfs(Rt);
	for(int i=Rt;i;i=a[i].nxt){
		int x=a[i].w;
		f[x]=1ll*dep[x]*f[x];
		dfs1(x);
	}
	dfs2(Rt);
	for(int i=1;i<=n;i++)printf("%I64d ",f[i]-dep[i]);printf("\n");
	return 0;
}