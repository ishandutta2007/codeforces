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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int dr[]={-1,0,1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}

int tc,n,m,a,b,val,y[MAX],bit[MAX],tree[1<<21],lz[1<<21];
pii x[MAX];
ll ans;

inline void upd_bit(int i){
	for(; i<=n; i+=i&-i)++bit[i];
	return;
}
int ret;
inline int que_bit(int i){
	ret = 0;
	for(; i>0; i-=i&-i)ret+= bit[i];
	return ret;
}

void build(int id,int le,int ri){
	lz[id] = 0, tree[id] = le;
	if(le==ri)return;
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	return;
}

inline void f(int id,int le,int ri){
	tree[id]+= lz[id];
	if(le!=ri){
		lz[lc]+= lz[id];
		lz[rc]+= lz[id];
	}
	lz[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b || ri<a)return;
	if(le>=a && ri<=b){
		lz[id] = val;
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = min(tree[lc], tree[rc]);
	return;
}

int nw;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n>>m;
		rep(i,1,n)cin>>x[i].fi, x[i].se = i, bit[i] = 0;
		rep(i,1,m)cin>>y[i];
		sort(x+1,x+1+n);
		sort(y+1,y+1+m);
		ans = 0;
		rap(i,n,1){
			ans+= que_bit(x[i].se);
			upd_bit(x[i].se);
		}
		build(1,0,n);
		
		int id = 1, cnt;
		ll hit = 0;
		nw = 0;
		y[m+1] = -1;
		rep(i,1,m){
			++hit;
			if(y[i]==y[i+1])continue;
			while(id<=n && x[id].fi<y[i]){
				++nw;
				a = x[id].se, b = n, val = -2;
				upd(1,0,n);
				++id;
			}
			cnt = 0;
			while(id<=n && x[id].fi==y[i]){
				a = x[id].se, b = n, val = -1;
				upd(1,0,n);
				++id, ++cnt;
			}
			ans+= (nw + tree[1]) * hit;
			id-= cnt;
			while(id<=n && x[id].fi==y[i]){
				++nw;
				a = x[id].se, b = n, val = -1;
				upd(1,0,n);
				++id;
			}
			hit = 0;
		}
		cout<<ans<<endl;
	}
	return 0;
}