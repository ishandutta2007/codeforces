#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,m,k,a,lk[MAX*5],ans,val,id;
int tree[1<<19],lz[1<<19];
pii x[MAX],y[MAX];
piii z[MAX];

inline void f(int id,int le,int ri){
	tree[id]+= lz[id];
	if(le!=ri)lz[lc]+= lz[id], lz[rc]+= lz[id];
	lz[id] = 0;
	return;
}

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = y[le].se; return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(ri<a)return;
	if(le>=a){lz[id] = val; f(id,le,ri); return;}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)cin>>x[i].fi>>x[i].se;
    rep(i,1,m)cin>>y[i].fi>>y[i].se, y[i].se = -y[i].se;
    rep(i,1,k)cin>>z[i].fi>>z[i].sf>>z[i].ss;
    sort(x+1,x+1+n), sort(y+1,y+1+m), sort(z+1,z+1+k);
    //cari semua yang def > z
    rap(i,m-1,1)y[i].se = max(y[i].se,y[i+1].se);
    rep(i,1,m)lk[y[i].fi-1] = i; lk[1000001] = m+1;
    rap(i,1000000,1)if(!lk[i])lk[i] = lk[i+1];
    
    build(1,1,m);
    ans = -2e9, id = 1;
    rep(i,1,n){
    	while(id<=k&&z[id].fi<x[i].fi){
    		a = lk[z[id].sf], val = z[id].ss, ++id;
    		if(a==m+1)continue;
    		upd(1,1,m);
		}
		ans = max(ans,tree[1]-x[i].se);
	}
	cout<<ans<<endl;
    return 0;
}