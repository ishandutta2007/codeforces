#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
//#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1100000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;

ll n,q,x[MAX],lz[1<<19],ty,a,val;
plll tree[1<<19];

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = {x[le],{x[le],x[le]}};
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = {tree[lc].fi+tree[rc].fi,{tree[lc].sf,tree[rc].ss}};
	return;
}

inline void f(int id,int le,int ri){
	tree[id] = {lz[id]*(ri-le+1),{lz[id],lz[id]}};
	if(le!=ri)lz[lc] = lz[rc] = lz[id];
	lz[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
//	cout<<le<<" "<<ri<<endl;
	if(le>a || tree[id].ss>=val)return;
	if(ri<=a && tree[id].sf<=val){lz[id] = val; f(id,le,ri); return;}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = {tree[lc].fi+tree[rc].fi,{tree[lc].sf,tree[rc].ss}};
	return;
}

int que(int id,int le,int ri){
	if(lz[id])f(id,le,ri);//<<id<<' '
	if(ri<a || tree[id].ss>val)return 0;
//	cout<<">> "<<le<<' '<<ri<<' '<<val<<' '<<tree[id].fi<<endl;
	if(le>=a && tree[id].fi<=val)return val-=tree[id].fi, ri-le+1;
	int mid = le+ri>>1;
	return que(lc,le,mid) + que(rc,mid+1,ri);
}

void tur(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le==ri){
		cout<<tree[id].ss<<' ';
		if(le==n)cout<<endl;
		return;
	}
	int mid = le+ri>>1;
	tur(lc,le,mid), tur(rc,mid+1,ri);
	return;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>x[i];
    build(1,1,n);
//    db(tree[3].se);
    while(q--){
    	cin>>ty>>a>>val;
    	if(ty==1)upd(1,1,n);
    	else cout<<que(1,1,n)<<endl;
//		tur(1,1,n), ;
	}
	return 0;
}