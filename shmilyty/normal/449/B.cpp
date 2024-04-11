#include<bits/stdc++.h> 
#define pa pair<int,int>
#define N 1000005
#define M 5000005
using namespace std;

int n,m,k,S=1,m0,ans;
int dis[N],h[N],a[N][3],cnt[N];
bool vis[N];
struct edge{
	int next,to,w;
}e[M];
priority_queue< pa,vector<pa>,greater<pa> > q;

void ins(int u,int v,int w){
	e[++m0]=(edge){h[u],v,w};h[u]=m0;
}

void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0,q.push(make_pair(0,s));
	
	while(!q.empty()){
		int u=q.top().second; q.pop();
		if(vis[u]) continue; vis[u]=1;
		for(int i=h[u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]==dis[u]+e[i].w) cnt[v]++;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				cnt[v]=1;
				q.push(make_pair(dis[v],v));
			}
		} 
	} 
	
}

int main(){
	int i,u,v,w;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++) cin>>u>>v>>w,ins(u,v,w),ins(v,u,w);
	for(i=1;i<=k;i++){
		cin>>a[i][1]>>a[i][2];
		v=a[i][1],w=a[i][2];
		ins(1,v,w),ins(v,1,w);
	}
	
	dijkstra(S);
	for(i=1;i<=k;i++){
		v=a[i][1],w=a[i][2];
		if(dis[v]<w) ans++;
		if(dis[v]==w)
			if(cnt[v]>1) ans++,cnt[v]--;
	}

	cout<<ans<<endl;
	return 0;
}