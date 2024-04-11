#include<bits/stdc++.h>
using namespace std;

const int N=100005;
vector<int> b[N];
int n,m,ecnt,h,a[N],ft[N],cnt,dfn[N],low[N],stk[N],top,bl[N],num,sz[N],d[N];
bool vis[N];
struct edge{
	int nxt,to;
}e[N<<1];
void dfs(int x){
	dfn[x]=low[x]=++cnt;vis[x]=1;
	stk[top++]=x;
	for(int i=ft[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]){
			dfs(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}else if(vis[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]){
		while(1){
			int u=stk[--top];
			vis[u]=0;
			bl[u]=num;
			sz[num]++;
			b[num].push_back(u);
			if(u==x)break;
		}
		num++;
	}
}
void add(int x,int y){
	ecnt++;
	e[ecnt]=(edge){ft[x],y};
	ft[x]=ecnt;
}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++){
		int x,y;scanf("%d%d",&x,&y);x--,y--;
		if((a[x]+1)%h==a[y])add(x,y);
		if((a[y]+1)%h==a[x])add(y,x);
	}
//	for(int i=0;i<n;i++)for(int j=ft[i];j;j=e[i].nxt)printf("%d %d\n",i,e[j].to);
	for(int i=0;i<n;i++)if(!dfn[i])dfs(i);
	for(int i=0;i<n;i++)
		for(int j=ft[i];j;j=e[j].nxt)
			if(bl[i]!=bl[e[j].to])d[bl[i]]++;
	int ans=n,f=0;
	for(int i=0;i<num;i++)if(!d[i]&&sz[i]<ans){
		ans=sz[i];
		f=i;
	}
	printf("%d\n",ans);
	sort(b[f].begin(),b[f].end());
	for(int i=0;i<ans;i++)printf("%d ",b[f][i]+1);printf("\n");
	return 0;
}