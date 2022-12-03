#include <bits/stdc++.h>
#define int long long
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


typedef pair<int,int> P;
struct edge {int to,cap,cost,rev;};
const int MAX_V=4402,INF=1e16;
int V;			//!!
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
void add_edge(int from, int to, int cap, int cost){
	edge e1={to,cap,cost,G[to].size()},e2={from,0,-cost,G[from].size()};
	G[from].push_back(e1);
	G[to].push_back(e2);
}
int min_cost_flow(int s, int t, int f){
	int res=0;
	fill(h,h+V,0);
	while(f>0){
		priority_queue< P,vector<P>,greater<P> > que;
		fill(dist,dist+V,INF);
		dist[s]=0;
		que.push(P(0,s));
		while(!que.empty()){
			P p=que.top();
			que.pop();
			int v=p.second;
			if(dist[v]<p.first) continue;
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					que.push(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==INF) return -1;
		for(int v=0;v<V;v++) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}


signed main(){
	int N,K;
	cin>>N>>K;
	V = 2*N+2;
	int S = 2*N, T = 2*N+1;
	rep(i,N) add_edge(S,i,1,0);
	rep(i,N-1) add_edge(i,i+1,N,0);
	rep(i,N){
		int x;
		cin>>x;
		add_edge(i,i+N,1,x);
	}
	rep(i,N-1) add_edge(i+N,i+1+N,N,0);
	rep(i,N){
		int x;
		cin>>x;
		add_edge(i+N,T,1,x);
	}
	cout<<min_cost_flow(S,T,K)<<endl;
}