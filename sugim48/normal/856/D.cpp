//https://hoj.hamako-ths.ed.jp/onlinejudge/contest/97/problems/6

// #pragma GCC optimize ("O3")
// #pragma GCC target ("avx")


#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}

int bsr(int x){	//4~7 -> 2
	if(x==0) return -1;
	return 31 ^ __builtin_clz(x);
}
const int MN = 200100;
struct LCA{
	int N,n;
	vector<int> depth;
	vector<vector<int>> par;
	vector<int> revpar[MN][20];	//revpar[v][i] = depth 2^i child

	void dfs(int v,int p,const vector<vector<int>>& G){
		if(p<0) depth[v]=0;
		else depth[v]=depth[p]+1;
		par[v][0]=p;
		for(int u:G[v]){
			if(u!=p) dfs(u,v,G);
		}
	}

	LCA(){}

	LCA(const vector<vector<int>>& G){
		N = G.size();
		n = bsr(N);
		depth = vector<int>(N,0);
		par = vector<vector<int>>(N,vector<int>(n+1,0));

		dfs(0,-1,G);
		rep1(i,n){
			rep(v,N){
				if(par[v][i-1]==-1){
					par[v][i]=-1;
				}else{
					par[v][i]=par[par[v][i-1]][i-1];
				}
			}
		}
		rep(v,N){
			rep(i,n+1){
				int p = par[v][i];
				if(p!=-1) revpar[p][i].pb(v);
			}
		}
	}

	int lca(int u,int v){
		if(depth[u]<depth[v]){
			swap(u,v);
		}
		int d=depth[u]-depth[v];
		rep(i,n+1){
			if((d>>i)&1) u=par[u][i];
		}
		if(u==v) return u;
		for(int i=n;i>=0;i--){
			if(par[u][i]!=par[v][i]){
				u=par[u][i];
				v=par[v][i];
			}
		}
		return par[v][0];
	}

	int distance(int u,int v){
		return depth[u] + depth[v] - 2*depth[lca(u,v)];
	}
};

int N,M;
vector<vector<int>> G;
LCA lca;
typedef pair<int,int> P;
typedef pair<P,int> PP;

typedef long long ll;
ll memo[MN];
ll sum[MN];
ll suma[MN];
ll dbl[MN][20];
vector<vector<PP>> w2ps;


ll solve(int v){
	if(memo[v]!=-1) return memo[v];

	sum[v] = 0;
	for(int u:G[v]) if(u!=lca.par[v][0]) sum[v] += solve(u);

	for(int u:G[v]) if(u!=lca.par[v][0]){
		suma[u] = sum[v] - solve(u);
		dbl[u][0] = suma[u];
	}
	int n = lca.n;
	rep1(i,n){
		for(int x:lca.revpar[v][i]){
			int m = lca.par[x][i-1];
			dbl[x][i] = dbl[x][i-1] + dbl[m][i-1];
		}
	}


	ll& res = memo[v];
	res = 0;
	{	//dont use v
		ll tmp = 0;
		for(int u:G[v]) if(u!=lca.par[v][0]) tmp += solve(u);
		chmax(res,tmp);
	}
	for(PP pp:w2ps[v]){
		P p = pp.fs;
		int x = p.fs, y = p.sc;
		ll tmp = 0;
//		int dist = lca.depth[x]+lca.depth[y]-2*lca.depth[v];
		int dist = pp.sc;
		if(x==y){
			tmp = 1 + sum[v];
		}else{
			if(v==x) swap(x,y);
			if(v==y){
				int z = x;
				int d = lca.depth[z] - lca.depth[v];
				rep(i,n+1) if((d>>i)&1){
					tmp += dbl[z][i];
					z = lca.par[z][i];
					if(d<(1<<i)) break;
				}
				tmp += sum[x];
				tmp += dist;
			}else{
				rep(t,2){
					int z = (t?x:y);
					int d = lca.depth[z]-lca.depth[v];
					rep(i,n+1) if((d>>i)&1){
						tmp += dbl[z][i];
						z = lca.par[z][i];
						if(d<(1<<i)) break;
					}
				}
				tmp += sum[x];
				tmp += sum[y];
				tmp -= sum[v];
				tmp += dist;
			}
		}
		chmax(res,tmp);
	}
//	printf("solve(%d)=%d\n",v,res);
	return res;
}

int main(){
	cin>>N>>M;
	G.resize(N);
	w2ps.resize(N);
	rep(i,N) memo[i] = sum[i] = suma[i] = -1;

	rep(i,N-1){
		int x = i+1;
		int y;
		cin>>y;
		y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	lca = LCA(G);
	rep(i,M){
		int x,y,c;
		cin>>x>>y>>c;
		x--,y--;
		int w = lca.lca(x,y);
		w2ps[w].pb(PP(P(x,y),c));
	}
	cout<<solve(0)<<endl;
}