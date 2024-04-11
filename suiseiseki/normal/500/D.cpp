#include <cstdio>
#include <cstring>
#define Maxn 100000
struct Data{
	int v;
	int value;
	int nxt;
}edge[Maxn<<1|5];
int alist[Maxn+5];
int cnt;
void add_edge(int u,int v,int value){
	edge[++cnt].nxt=alist[u];
	edge[cnt].v=v;
	edge[cnt].value=value;
	alist[u]=cnt;
}
int len[Maxn+5];
int num[Maxn+5];
int n,m;
int in[Maxn+5];
int out[Maxn+5];
double ans,tmp;
void dfs(int x,int f){
	num[x]=1;
	for(int i=alist[x];i;i=edge[i].nxt){
		int v=edge[i].v;
		if(v==f){
			continue;
		}
		dfs(v,x);
		num[x]+=num[v];
		ans+=(double)edge[i].value*num[v]*(n-num[v])/tmp;
	}
}
int u,v,value;
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&u,&v,&value);
		in[i]=u;
		out[i]=v;
		len[i]=value;
		add_edge(u,v,value);
		add_edge(v,u,value);
	}
	tmp=(double)n*(n-1)/6.0;
	dfs(1,-1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		value=mn(num[in[u]],num[out[u]]);
		ans-=(double)(len[u]-v)*value*(n-value)/tmp;
		len[u]=v;
		printf("%.7lf\n",ans);
	}
	return 0;
}