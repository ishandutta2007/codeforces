#include<bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A, B> &p) {
  os << '(' << p.first << ',' << p.second << ')';
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &v) {
  os << '{';
  bool osu = 1;
  for(auto &i : v) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
template<class T,long long unsigned int size>
ostream& operator<<(ostream& os, const array<T,size> &arr) {
  os << '{';
  bool osu = 1;
  for(auto &i : arr) { if(!osu) os << ','; os << i; osu = 0; }
  os << '}';
  return os;
}
 
#define ll long long
#define ull unsigned long long
#define lll __int128
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
#define revsort(a,b) sort(a,b), reverse(a,b)
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define permute(x) while(next_permutation(all(x)))
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vll vector<ll>
#define vvll vector<vll>
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
const int block = 444;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n,q,rt,x[MAX],dep[MAX],a,b,st[MAX],en[MAX],cv[MAX],id,ans,k,N,pos[MAX],qu,nw;
vi v[MAX];
pii z[MAX];

struct segtree{
	int n;
	vi X,tree;
	void build(int id,int le,int ri){
		if(le==ri){
			tree[id] = x[cv[X[le]]];
			return;
		}
		int mid = le+ri>>1;
		build(lc,le,mid), build(rc,mid+1,ri);
		tree[id] = min(tree[lc], tree[rc]);
		return;
	}
	int a,b;
	int que(int id,int le,int ri){
		if(le>b || ri<a)return MOD;
		if(le>=a && ri<=b)return tree[id];
		int mid = le+ri>>1;
		return min(que(lc,le,mid), que(rc,mid+1,ri));
	}
	inline int get(int _a,int _b){
		a = _a, b = _b;
		return que(1,1,n);
	}
}tree[1<<18];

void build(int id,int le,int ri){
	tree[id].X.pb(0);
	tree[id].n = pos[ri]-pos[le-1];
	rep(i,pos[le-1]+1,pos[ri])tree[id].X.pb(z[i].se);
	sort(all(tree[id].X));
	int sz = 1;
	while(sz<tree[id].n)sz<<= 1;
	sz<<=1;
	tree[id].tree.resize(sz);
	tree[id].build(1,1,tree[id].n);
	
	
	if(le==ri)return;
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	return;
}


int que(int id,int le,int ri){
	if(le>b || ri<a)return MOD;
	if(le>=a && ri<=b){
		vi::iterator itl,itr;
		itl = lower_bound(all(tree[id].X), st[qu]);
		itr = upper_bound(all(tree[id].X), en[qu]);
		if(itl!=itr){
			le = itl-tree[id].X.begin();
			ri = itr-tree[id].X.begin()-1;
			return tree[id].get(le, ri);
		}
		return MOD;
	}
	int mid = le+ri>>1;
	return min(que(lc,le,mid), que(rc,mid+1,ri));
}

void dfs(int nw,int par){
	st[nw] = ++id;
	cv[id] = nw;
	N = max(N, dep[nw]);
	z[nw] = {dep[nw], st[nw]};
	
	for(int i:v[nw])if(i!=par){
		dep[i] = dep[nw]+1;
		dfs(i,nw);
	}
	en[nw] = id;
}

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>rt;
	rep(i,1,n){
		cin>>x[i];
	}
	rep(i,2,n){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dep[rt] = 1;
	dfs(rt,0);
	sort(z+1,z+1+n);
	rep(i,1,n)pos[z[i].fi] = i;
	build(1,1,N);
	
	cin>>q;
	while(q--){
		cin>>qu>>k;
		qu = (qu+ans)%n + 1;
		k = (k+ans)%n;
		k = min(k, N-dep[qu]);
		
		a = dep[qu], b = dep[qu]+k;
		ans = que(1,1,N);
		cout<<ans<<endl;
	}
	return 0;
}