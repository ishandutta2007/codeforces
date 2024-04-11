#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vll vector<pll>
#define vvl vector<vector<ll>>
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
const int MAX = 4e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

int n,q,st[MAX],en[MAX],id,x[MAX],y[MAX],a,b;
ll tree[1<<20], lz[1<<20], val;
vi v[MAX];

void dfs(int nw,int par){
	st[nw] = ++id;
	for(int i:v[nw])if(i!=par){
		dfs(i,nw);
	}
	en[nw] = id;
	return;
}
void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = 1ll<<y[le];
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = tree[lc] | tree[rc];
	return;
}
inline void f(int id,int le,int ri){
	tree[id] = lz[id];
	if(le!=ri)lz[lc] = lz[rc] = lz[id];
	lz[id] = 0;
	return;
}
void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){
		lz[id] = val;
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = tree[lc] | tree[rc];
	return;
}
ll que(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return 0;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return que(lc,le,mid) | que(rc,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>q;
	rep(i,1,n)cin>>x[i];
	rep(i,2,n){
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,0);
	rep(i,1,n)y[st[i]] = x[i];
	build(1,1,n);
	int ty;
	while(q--){
		cin>>ty>>a;
		if(ty==2){
			b = en[a], a = st[a];
			cout<<__builtin_popcountll(que(1,1,n))<<endl;
		}
		else {
			b = en[a], a = st[a];
			cin>>val;
			val = 1ll<<val;
			upd(1,1,n);
		}
	}
	return 0;
}