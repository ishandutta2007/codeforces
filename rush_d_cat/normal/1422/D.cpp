#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,m;
int sx,sy,fx,fy,x[N],y[N];
vector< pair<int,int> > g[3 * N]; int dis[3 * N];
vector<int> e[N * 2]; bool vis[N * 2];
vector<int> vx, vy;

int idx(int x){
	return lower_bound(vx.begin(),vx.end(),x)-vx.begin()+1;
}
int idy(int y){
	return lower_bound(vy.begin(),vy.end(),y)-vy.begin()+1 + vx.size();
}
vector<int> comp;
void dfs(int u){
	vis[u]=1; comp.push_back(u);
	for(auto v:e[u]){
		if(vis[v]==0)dfs(v);
	}
}
struct Nod{
	int dis,u;
	bool operator<(const Nod&o)const{
		return dis>o.dis;
	}
};
int main() {
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
	LL ans=abs(sx-fx) + abs(sy-fy);
	vx.push_back(sx); vx.push_back(fx);
	vy.push_back(sy); vy.push_back(fy);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		vx.push_back(x[i]); vy.push_back(y[i]);
	}
	
	sort(vx.begin(),vx.end()); vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end()); vy.erase(unique(vy.begin(),vy.end()),vy.end());
	
	for(int i=0;i+1<vx.size();i++) {
		g[idx(vx[i])].push_back(make_pair(idx(vx[i+1]), vx[i+1]-vx[i]));
		g[idx(vx[i+1])].push_back(make_pair(idx(vx[i]), vx[i+1]-vx[i]));
	}

	for(int i=0;i+1<vy.size();i++){
		g[idy(vy[i])].push_back(make_pair(idy(vy[i+1]), vy[i+1]-vy[i]));
		g[idy(vy[i+1])].push_back(make_pair(idy(vy[i]), vy[i+1]-vy[i]));
	}

	for(int i=1;i<=m;i++){
		e[idx(x[i])].push_back(idy(y[i]));
		e[idy(y[i])].push_back(idx(x[i]));
	}

	int tot = vx.size() + vy.size();
	for(int i=1;i<=vx.size();i++){
		comp.clear();
		if(vis[i]==0) {
			dfs(i);
			++tot;
			for(auto x:comp) {
				g[tot].push_back(make_pair(x,0));
				g[x].push_back(make_pair(tot,0));
			}
		}
	} 
	priority_queue<Nod> q;
	memset(dis,-1,sizeof(dis));
	q.push((Nod){0, idx(sx)}); dis[idx(sx)] = 0;
	q.push((Nod){0, idy(sy)}); dis[idy(sy)] = 0;
	while(q.size()){
		Nod now = q.top(); q.pop();
		if(dis[now.u]<now.dis)continue;
		for(auto e:g[now.u]){
			if(dis[e.first]==-1 || dis[e.first]>dis[now.u]+e.second){
				dis[e.first]=dis[now.u]+e.second; q.push((Nod){dis[e.first],e.first});
			}
		}
	}
	for(int i=1;i<=m;i++){
		ans=min(ans,1LL*dis[idx(x[i])] + abs(x[i]-fx) + abs(y[i]-fy));
	}
	cout<<ans<<endl;
}