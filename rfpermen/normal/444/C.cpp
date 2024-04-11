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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000009;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,q,ty,a,b,val;
pll tree[1<<18],lz[1<<18];

void build(int id,int le,int ri){
	if(le==ri){
		tree[id].fi = le;
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	return;
}

inline void f(int id,int le,int ri){
	tree[id].se+= lz[id].se*(ri-le+1);
	tree[id].fi = lz[id].fi;
	if(le!=ri)lz[lc].fi = lz[rc].fi = lz[id].fi, lz[lc].se+= lz[id].se, lz[rc].se+= lz[id].se;
	lz[id] = {0,0};
	return;
}

void upd(int id,int le,int ri){
	if(lz[id].fi)f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a && ri<=b && tree[id].fi){
		lz[id] = {val,abs(tree[id].fi-val)};
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id].fi = tree[lc].fi==tree[rc].fi ? tree[rc].fi : 0;
	tree[id].se = tree[lc].se + tree[rc].se;
	return;
}

ll que(int id,int le,int ri){
	if(lz[id].fi)f(id,le,ri);
	if(le>b||ri<a)return 0;
	if(le>=a && ri<=b)return tree[id].se;
	int mid = le+ri>>1;
	return que(lc,le,mid) + que(rc,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    build(1,1,n);
    while(q--){
    	cin>>ty>>a>>b;
    	if(ty==1)cin>>val, upd(1,1,n);
    	else cout<<que(1,1,n)<<endl;
	}
    return 0;
}