#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

struct Edge {
	int v, flow, c, rev;
	Edge(int _v, int _flow, int _c, int _rev) {
		v=_v;  flow=_flow;  c=_c;  rev=_rev;
}	};
class Graph {
public:
	int V, lvl[5005], start[5005];  vector<Edge> adj[5005];
	Graph(int V) { this->V = V; }
	void addEdge(int u, int v, int C) {
		Edge a(v, 0,C, adj[v].size());
		Edge b(u, 0,0, adj[u].size());
		adj[u].push_back(a);  adj[v].push_back(b);
	}
	bool BFS(int s, int t) {
		memset(lvl, -1, sizeof(lvl));  lvl[s] = 0;  queue<int> q;  q.push(s);
		while (!q.empty()) {
			int u = q.front();  q.pop();
			for (auto e: adj[u]) if(lvl[e.v] < 0 && e.flow < e.c) {
				lvl[e.v] = lvl[u]+1;  q.push(e.v);
		}	}
		return lvl[t] != -1;
	}
	int DFS(int u, int flow, int t, int start[]) {
		if (u == t) return flow;
		for (; start[u] < adj[u].size(); start[u]++) {
			Edge& e = adj[u][start[u]];
			if (lvl[e.v] == lvl[u] + 1 && e.flow < e.c) {
				int curr = min(flow, e.c - e.flow);
				int tmp  = DFS(e.v, curr,t, start);
				if (tmp > 0) {
					e.flow += tmp;  adj[e.v][e.rev].flow -= tmp;
					return tmp;
		}	}	}
		return 0;
	}
	int dinic(int s, int t) {
		int total = 0;
		while (BFS(s,t)) {
			memset(start, 0, sizeof(start));
			while (int flow = DFS(s,INT_MAX,t,start)) total += flow;
		} return total;
}	};

int n,cnt[20],y[MAX],x;
map<string,int> hs;
string s,t,ans[] = {"","S","M","L","XL","XXL","XXXL"};

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	hs["S"] = 1;
	hs["M"] = 2;
	hs["L"] = 3;
	hs["XL"] = 4;
	hs["XXL"] = 5;
	hs["XXXL"] = 6;
	Graph g(100);
	rep(i,1,6){
		cin>>x;
		g.addEdge(20+i,30,x);
	}
	cin>>n;
	rep(i,1,n){
		cin>>s;
		if(hs.count(s))y[i] = hs[s];
		else {
			t = "";
			for(char c:s){
				if(c==',')break;
				t+= c;
			}
			y[i] = hs[t]+6;
		}
		++cnt[y[i]];
	}
	rep(i,1,6){
		g.addEdge(0,i,cnt[i]);
		g.addEdge(i,20+i,cnt[i]);
	}
	rep(i,1,5){
		g.addEdge(0,i+6,cnt[i+6]);
		g.addEdge(i+6,20+i,cnt[i+6]);
		g.addEdge(i+6,21+i,cnt[i+6]);
	}
	if(g.dinic(0,30)!=n)return cout<<"NO\n",0;
	cout<<"YES\n";
	rep(i,1,n){
		if(y[i]<=6)cout<<ans[y[i]]<<endl;
		else {
			for(Edge &j:g.adj[y[i]])if(j.v!=0 && j.flow){
				--j.flow;
				cout<<ans[j.v-20]<<endl;
				break;
			}
		}
	}
	return 0;
}