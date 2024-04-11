#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e2+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

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

int n,m,ans,a,b,res,e;
vector<int> v[MAX];
 
int main(){
//	cout<<fixed<<setprecision(9);
// freopen("output.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	while(m--){
		cin>>a>>b;
		v[a].pb(b);
	}
	ans = MOD;
	rep(cen,1,n){
		res = (n<<1)-1, e = 0;
		graph g(n+1,n+1);
		rep(i,1,n){
			if(i==cen){res-= v[i].size(); continue;}
			for(int j:v[i]){
				if(j==cen)--res;
				else ++e, g.addEdge(i,j);
			}
		}
		a = g.maximum_matching();
		ans = min(ans,res+(e-a)+(n-1-a));
	}
	cout<<ans<<endl;
	return 0;
}