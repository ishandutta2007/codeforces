#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD=998244353;
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}

int n,m;
vector<int> g[N],rg[N];
//---------------------------------
const int B=26;
int dis[N][B];
// flip [0,B) times
LL solve1() {
	memset(dis,-1,sizeof(dis));
	queue< pair<int,int> > q;
	q.push(make_pair(1,0)); dis[1][0]=0;
	while(q.size()) {
		pair<int,int> now=q.front(); q.pop();
		int u=now.first,k=now.second;
		if(k%2==0) {
			for(auto v:g[u]){
				if(dis[v][k]==-1){
					dis[v][k]=dis[u][k]+1; q.push(make_pair(v,k));
				}
			}
			if(k+1<B){
				for(auto v:rg[u]){
					if(dis[v][k+1]==-1){
						dis[v][k+1]=dis[u][k]+1; q.push(make_pair(v,k+1));
					}
				}
			}
		} else {
			for(auto v:rg[u]){
				if(dis[v][k]==-1){
					dis[v][k]=dis[u][k]+1; q.push(make_pair(v,k));
				}
			}
			if(k+1<B){
				for(auto v:g[u]){
					if(dis[v][k+1]==-1){
						dis[v][k+1]=dis[u][k]+1; q.push(make_pair(v,k+1));
					}
				}
			}
		}
	}
	int ans=1e9+7;
	for(int i=0;i<B;i++)
		if(dis[n][i]!=-1) {
			//printf("dis[%d][%d]=%d\n", n,i,dis[n][i]);
			ans=min(ans,((1<<i)-1) + dis[n][i]);
		}
	return ans;
}
//----------------------------------


struct Nod {
	int u,k,x; 
	bool operator<(const Nod&o)const{
		return make_pair(k,x) > make_pair(o.k,o.x);
	}
};
pair<int,int> node_dis[N][2];

LL solve2() {
	priority_queue<Nod> q;
	for(int i=0;i<N;i++)for(int j=0;j<2;j++)
		node_dis[i][j]=make_pair(-1,-1);

	q.push((Nod){1,0,0}); node_dis[1][0]=make_pair(0,0);
	while(q.size()){
		Nod now=q.top(); q.pop();
		int u=now.u,k=now.k,x=now.x,flag=k%2;
		if(node_dis[u][flag] < make_pair(k,x)) continue;
		//printf("u=%d,flag=%d,dis=(%d,%d)\n", u,flag,node_dis[u][flag].first,node_dis[u][flag].second);
		// flip
		if(node_dis[u][flag^1] == make_pair(-1,-1) || node_dis[u][flag^1] > make_pair(k+1,x)) {
			node_dis[u][flag^1] = make_pair(k+1,x);
			q.push((Nod){u,k+1,x});
		}
		// walk
		if(flag%2==0){
			for(auto v:g[u]){
				if(node_dis[v][flag] == make_pair(-1,-1) || node_dis[v][flag] > make_pair(k,x+1)) {
					node_dis[v][flag] = make_pair(k,x+1);
					q.push((Nod){v,k,x+1});
				}
			}
		} else {
			for(auto v:rg[u]){
				if(node_dis[v][flag] == make_pair(-1,-1) || node_dis[v][flag] > make_pair(k,x+1)) {
					node_dis[v][flag] = make_pair(k,x+1);
					q.push((Nod){v,k,x+1});
				}
			}			
		}
	}
	pair<int,int> res=min(node_dis[n][0], node_dis[n][1]);
	LL ans=(mpow(2LL,res.first)-1 + res.second)%MOD;
	return ans;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
		rg[v].push_back(u);
	}	
	//printf("%lld\n", solve2());return 0;
	int ans=solve1();
	if(ans<1e9) printf("%d\n", ans);
	else {
		printf("%lld\n", solve2());
	}
}