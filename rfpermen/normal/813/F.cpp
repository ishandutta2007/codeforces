#include<bits/stdc++.h>
 
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
#define clz(x) (1<<(31-__builtin_clz(x)))
#define clzll(x) (1LL<<(63-__builtin_clzll(x)))
#define all(x) x.begin(),x.end()
#define rsort(x) sort(x), reverse(x)
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
const int MAX = 2e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 320;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,a[MAX],b[MAX],vis[MAX],p[MAX],fc;
vi v[MAX];
set<pii> fix, nw;
bool st;

bool dfs(int nw){
	p[nw] = fc;
	for(int i:v[nw]){
		if(vis[i]){
			if(vis[i]==vis[nw])return 0;
		}
		else {
			vis[i] = -vis[nw];
			if(!dfs(i))return 0;
		}
	}
	return 1;
}

void init(){
	rep(i,1,n)v[i].clear();
	mems(vis,0);
	for(auto i:fix){
		v[i.fi].pb(i.se);
		v[i.se].pb(i.fi);
	}
	st = 1;
	rep(i,1,n)if(!vis[i]){
		vis[i] = -1;
		fc = i;
		st&= dfs(i);
	}
	return;
}
int id,rb[MAX];
vi v2[MAX];
set<int> o;

bool dfs2(int nw){
	for(int i:v2[nw]){
		if(vis[i]){
			if(vis[i]==vis[nw])return 0;
		}
		else {
			vis[i] = -vis[nw];
			if(!dfs2(i))return 0;
		}
	}
	return 1;
}

bool solve(){
	int a,b;
	id = n;
	o.clear();
	for(auto i:nw){
		a = p[i.fi], b = p[i.se];
		o.insert(a);
		o.insert(b);
		if(vis[i.fi]!=vis[i.se]){
			++id;
			v2[a].pb(id);
			v2[id].pb(a);
			v2[b].pb(id);
			v2[id].pb(b);
		}
		else {
			v2[a].pb(b);
			v2[b].pb(a);
		}
	}
	for(int i:o)rb[i] = vis[i], vis[i] = 0;
	bool ret = 1;
	for(int i:o)if(!vis[i]){
		vis[i] = 1;
		ret&= dfs2(i);
	}
	for(int i:o)vis[i] = rb[i], v2[i].clear();
	rep(i,n+1,id)vis[i] = 0, v2[i].clear();
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,m)cin>>a[i]>>b[i];
	int lp;
	rep(i,1,m){
		if(i%block==1){
			for(auto j:nw)fix.insert(j);
			nw.clear();
			lp = min(m,(i/block+1)*block);
			rep(j,i,lp){
				if(fix.count({a[j],b[j]})){
					nw.insert({a[j],b[j]});
					fix.erase({a[j],b[j]});
				}
			}
			init();
		}
		if(nw.count({a[i],b[i]})){
			nw.erase({a[i],b[i]});
		}
		else{
			nw.insert({a[i],b[i]});
		}
		if(!st){
			cout<<"NO\n";
			continue;
		}
		if(solve())cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}