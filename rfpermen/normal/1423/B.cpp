#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

struct graph {
	int L, R;  vector< vector<int> > adj;

	graph(int _L, int _R) : L(_L), R(_R), adj(_L+_R) {}
	void addEdge(int u, int v) { adj[u].pb(v+L);  adj[v+L].pb(u); }
	int maximum_matching() {
		vector<int> level(L), mate(L+R,-1);

		function<bool(void)> levelize = [&]() { // BFS
			queue<int> Q;
			for (int u=0; u<L; u++) {
				level[u] = -1;
				if (mate[u] < 0) level[u] = 0, Q.push(u);
			}
			while (!Q.empty()) {
				int u = Q.front();  Q.pop();
				for (int w: adj[u]) {
					int v = mate[w];
					if (v < 0) return true;
					if (level[v] < 0) level[v] = level[u]+1, Q.push(v);
			}	}
			return false;
		};
		function<bool(int)> augment = [&](int u) {
			for (int w: adj[u]) { // DFS
				int v = mate[w];
				if (v < 0 || (level[v] > level[u] && augment(v))) {
					mate[u] = w;  mate[w] = u;  return true;
			}	}
			return false;
		};
		int match = 0;
		while (levelize()) for (int u=0; u<L; u++) {
			if (mate[u] < 0 && augment(u)) match += 1;
		}
		return match;
}	};

int n,m,le,ri,mid,ans;
piii e[MAX];

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,m)cin>>e[i].sf>>e[i].ss>>e[i].fi;
    e[0].fi = -1;
    sort(e+1,e+1+m);
    le = 1, ri = m;
    while(le<=ri){
    	mid = le+ri>>1;
    	graph g(n+2,n+2);
    	rep(i,1,mid)g.addEdge(e[i].sf,e[i].ss);
    	if(g.maximum_matching()==n)ans = mid, ri = mid-1;
    	else le = mid+1;
	}
	cout<<e[ans].fi<<endl;
    return 0;
}