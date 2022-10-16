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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() (rand()<<16)|rand()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

struct segtree{
	bool l,r;
	int rvmx, rvle, rvri;
	int mx, cle, cri;
}tree[1<<20],ret;

int n,q,a,b;
bool x[MAX],lz[1<<20];
char c;

inline segtree merge(ll szle,ll szri,segtree le,segtree ri){
	ret.l = le.l, ret.r = ri.r;
	//kita coba solve untuk yang standar dulu
	if(le.r||!ri.l){
		ret.mx = max(le.cri+ri.cle, max(le.mx,ri.mx));
		ret.cle = (le.cle==szle ? szle+ri.cle : le.cle);
		ret.cri = (ri.cri==szri ? szri+le.cri : ri.cri);
	}
	else {
		ret.mx = max(le.mx,ri.mx);
		ret.cle = le.cle;
		ret.cri = ri.cri;
	}
	//sekarang yang reverse
	if(!le.r||ri.l){
		ret.rvmx = max(le.rvri+ri.rvle, max(le.rvmx,ri.rvmx));
		ret.rvle = (le.rvle==szle ? szle+ri.rvle : le.rvle);
		ret.rvri = (ri.rvri==szri ? szri+le.rvri : ri.rvri);
	}
	else {
		ret.rvmx = max(le.rvmx,ri.rvmx);
		ret.rvle = le.rvle;
		ret.rvri = ri.rvri;
	}
	return ret;
}

inline void f(int &id,int &le,int &ri){
	tree[id].l^=1, tree[id].r^=1;
	tree[id].mx^=tree[id].rvmx^=tree[id].mx^=tree[id].rvmx;
	tree[id].cle^=tree[id].rvle^=tree[id].cle^=tree[id].rvle;
	tree[id].cri^=tree[id].rvri^=tree[id].cri^=tree[id].rvri;
	if(le!=ri)lz[lc]^=1, lz[rc]^=1;
	lz[id] = 0;
	return;
}

void build(int id,int le,int ri){
	if(le==ri){
		tree[id].l = tree[id].r = x[le];
		tree[id].mx = tree[id].rvmx = tree[id].cle = tree[id].rvle = tree[id].cri = tree[id].rvri = 1;
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = merge(mid-le+1,ri-mid,tree[lc],tree[rc]);
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){f(id,le,ri); return;}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = merge(mid-le+1,ri-mid,tree[lc],tree[rc]);
	return;
}

segtree que(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	if(a<=mid&&b>mid)return merge(mid-max(a,le)+1,min(b,ri)-mid,que(lc,le,mid),que(rc,mid+1,ri));
	else if(a<=mid)return que(lc,le,mid);
	return que(rc,mid+1,ri);
}


int main(){
// cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>c, x[i] = c=='>';
    build(1,1,n);
    while(q--){
    	cin>>a>>b;
    	upd(1,1,n);
    	cout<<que(1,1,n).mx<<endl;
	}
    return 0;
}