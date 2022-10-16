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
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

#define N 100020
vector<int> v[N];
bool vis[N], ins[N];
int disc[N], low[N], gr[N];
stack<int> st;
int id,grid;
void scc(int cur, int par){
  disc[cur]=low[cur]=++id;
  vis[cur]=ins[cur]=1;
  st.push(cur);
  for(int to : v[cur]){
    if (to==par) continue; // ini untuk SO(scc undirected)
    if (!vis[to]) scc(to,cur);
    if (ins[to]) low[cur]=min(low[cur],low[to]);	
  }	
  if (low[cur]==disc[cur]){
    grid++; // group id		
    while(ins[cur]){ 		
      gr[st.top()]=grid; ins[st.top()]=0; st.pop();
    }	
  }
}
inline void init(int size){
	id = grid = 0;
	rep(i,0,size){
		v[i].clear();
		vis[i] = 0;
	}
	return;
}

int n,m,a,b,hs[MAX],cnt[MAX],hit[18][MAX],sp[18][MAX],dep[MAX],q,pre[MAX];
vector<pii> e;

void dfs(int nw,int par){
	hit[0][nw] = cnt[nw]>1;
	for(int i:v[nw])if(i!=par){
		sp[0][i] = nw;
		dep[i] = dep[nw]+1;
		dfs(i,nw);
	}
	return;
}

inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int ret = 0;
	rap(i,16,0)if(dep[x]-(1<<i)>=dep[y]){
		ret+= hit[i][x];
		x = sp[i][x];
	}
	if(x==y)return ret + hit[0][x];
	rap(i,16,0){
		if(sp[i][x]!=sp[i][y]){
			ret+= hit[i][x] + hit[i][y];
			x = sp[i][x];
			y = sp[i][y];
		}
	}
	return ret + hit[0][x] + hit[1][y];
}

inline int f(int a,int b){
	if(a==b)return 2;
	return pre[lca(a,b)];
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("asd.csv", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	init(n);
	while(m--){
		cin>>a>>b;
		e.pb({a,b});
		v[a].pb(b);
		v[b].pb(a);
	}
	rep(i,1,n)if(!vis[i])scc(i,0);
	rep(i,1,n){
		v[i].clear();
		hs[i] = gr[i];
		++cnt[gr[i]];
	}
	for(pii i:e){
		a = gr[i.fi], b = gr[i.se];
		if(a!=b){
			v[a].pb(b);
			v[b].pb(a);
		}
	}
//	rep(i,1,n)cout<<i<<" = "<<hs[i]<<endl;
	n = grid;
	dep[1] = 1;
	dfs(1,0);
	rep(i,1,16)rep(j,1,n)sp[i][j] = sp[i-1][sp[i-1][j]], hit[i][j] = hit[i-1][j] + hit[i-1][sp[i-1][j]];
	pre[0] = 1;
	rep(i,1,n)pre[i] = (pre[i-1]<<1)%MOD;
//	rep(i,1,n)cout<<i<<": "<<cnt[i]<<endl;
//	cout<<"___\n";
//	rep(i,1,n)for(int j:v[i])if(i<j)cout<<i<<" "<<j<<endl;
	cin>>q;
	while(q--){
		cin>>a>>b;
		a = hs[a], b = hs[b];
//		out(a,b);
		cout<<f(a,b)<<endl;
	}
	return 0;
}