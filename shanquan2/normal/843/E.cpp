#include<bits/stdc++.h>
#define inf (1<<30)
using namespace std;

struct edge{
	int nxt,to,w;
}e[4005];
int q[105],ft[105],cur[105],cnt,S,T,n,m,x[1005][3],d[105],id[1005];
bool v[1005];
void addedge(int x,int y,int w){
	e[cnt]=(edge){ft[x],y,w},ft[x]=cnt++;
	e[cnt]=(edge){ft[y],x,0},ft[y]=cnt++;
}
bool bfs(){
	memcpy(cur,ft,sizeof(ft));
	memset(d,0,sizeof(d));d[S]=1;
	int h=0,t=1;q[0]=S;
	while(h<t){
		int u=q[h++];
		for(int i=ft[u];i;i=e[i].nxt)if(!d[e[i].to]&&e[i].w){
			d[e[i].to]=d[u]+1;
			q[t++]=e[i].to;
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T)return a;
	int f=a;
	for(int &i=cur[x];i;i=e[i].nxt)if(e[i].w&&d[e[i].to]==d[x]+1){
		int tmp=dfs(e[i].to,min(f,e[i].w));
		f-=tmp;
		e[i].w-=tmp;
		e[i^1].w+=tmp;
		if(!f)break;
	}
	if(a==f)d[x]=-1;
	return a-f;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	cnt=2;
	for(int i=0;i<m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		x[i][0]=a,x[i][1]=b,x[i][2]=c;
		if(c)addedge(a,b,1),addedge(b,a,inf);
		else addedge(a,b,inf);
	}
	int ans=0;
	while(bfs())ans+=dfs(S,inf);
	printf("%d\n",ans);
	
	for(int i=0;i<m;i++){
		int a=x[i][0],b=x[i][1],c=x[i][2];
		if(c&&(d[a]&&!d[b]||!d[a]&&d[b]))v[i]=1;
	}
	memset(d,0,sizeof(d));
	memset(ft,0,sizeof(ft));
	cnt=2;
	addedge(T,S,inf);
	S=n+1,T=n+2;
	for(int i=0;i<m;i++){
		int a=x[i][0],b=x[i][1],c=x[i][2];
		if(c)id[i]=cnt,d[a]++,d[b]--,addedge(a,b,inf);
	}
	ans=0;
	for(int i=1;i<=n;i++)if(d[i]>0)addedge(i,T,d[i]),ans+=d[i];else addedge(S,i,-d[i]);
	while(bfs())ans-=dfs(S,inf);
//	printf("%d\n",ans);
	for(int i=0;i<m;i++){
		int a=x[i][0],b=x[i][1],c=x[i][2],d=id[i]^1;
		if(!c)printf("0 1\n");
		else if(v[i])printf("%d %d\n",e[d].w+1,e[d].w+1);
		else printf("%d %d\n",e[d].w+1,e[d].w+2);
	}
	return 0;
}