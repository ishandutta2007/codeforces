#include<bits/stdc++.h>
using namespace std;

const int N=100100;
struct edge{
	int nxt,to,id;
}e[N<<1];
int n,m,ft[N],c[N],d[N],idx,idy,ide,fa[N],fe[N];
bool vis[N];
long long b[N],a[N];
bool dfsc(int x){
	for(int i=ft[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(!c[y]){
			c[y]=3-c[x];
			if(!dfsc(y))return 0;
		}else if(c[y]==c[x]){
			idx=x;idy=y;ide=i;
			return 0;
		}
	}
	return 1;
}
long long dfs(int x){
	vis[x]=1;
	long long s=a[x];
	for(int i=ft[x];i;i=e[i].nxt)if(!vis[e[i].to]){
		int y=e[i].to;fa[y]=x;fe[y]=i;
		long long t=dfs(y);
		b[e[i].id]=t;
		s-=t;
	}
	return s;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		e[i<<1]=(edge){ft[x],y,i};ft[x]=i<<1;
		e[i<<1|1]=(edge){ft[y],x,i};ft[y]=i<<1|1;
	}
	c[1]=1;
	bool f=dfsc(1);
	if(f){
		long long s=0;
		for(int i=1;i<=n;i++)if(c[i]==1)s+=a[i];else s-=a[i];
		if(s){
			printf("NO\n");
		}else{
			long long s=dfs(1);
			if(s){printf("NO\n");return 0;}
			printf("YES\n");
			for(int i=1;i<=m;i++)printf("%I64d\n",b[i]);
		}
	}else{
		long long s=dfs(1);
		if(s&1){
			printf("NO\n");
			return 0;
		}
		s/=2;
		if(c[idx]==2)s=-s;
		b[e[ide].id]=s;
		a[idx]-=s;a[idy]-=s;
		memset(vis,0,sizeof(vis));
		s=dfs(1);
		if(s){
			printf("NO\n");
			return 0;
		}
		printf("YES\n");
		for(int i=1;i<=m;i++)printf("%I64d\n",b[i]);
	}
	return 0;
}