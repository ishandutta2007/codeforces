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
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MOD = 1000000009;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,a,b,q,ty;
ll x[MAX],y[MAX],px[MAX],py[MAX],lzx[1<<20],lzy[1<<20],tree[1<<20],dat[MAX];

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = dat[le];
		return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = (tree[lc] + tree[rc])%MOD;
	return;
}

inline void f(int id,int le,int ri){
	lzx[id]%= MOD, lzy[id]%= MOD;
	tree[id] = (tree[id] + lzx[id]*px[ri-le+1] + lzy[id]*py[ri-le+1])%MOD;
	if(le!=ri){
		lzx[lc]+= lzx[id];
		lzy[lc]+= lzy[id];
		int mid = (le+ri>>1)-le+2;
		lzx[rc]+= (lzx[id]*x[mid] + lzy[id]*y[mid])%MOD;
		lzy[rc]+= (lzx[id]*x[mid+1] + lzy[id]*y[mid+1])%MOD;
	}
	lzx[id] = lzy[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(lzx[id] || lzy[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){
		lzx[id] = x[le-a+1]+y[le-a+1], lzy[id] = x[le-a+2]+y[le-a+2];
		f(id,le,ri);
		return;
	}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = (tree[lc] + tree[rc])%MOD;
	return;
}

ll que(int id,int le,int ri){
	if(le>b||ri<a)return 0;
	if(lzx[id] || lzy[id])f(id,le,ri);
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return (que(lc,le,mid) + que(rc,mid+1,ri))%MOD;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    x[1] = y[2] = px[1] = px[2] = py[2] = 1;
    rep(i,3,n){
    	x[i] = (x[i-2] + x[i-1])%MOD;
    	y[i] = (y[i-2] + y[i-1])%MOD;
    	px[i] = (px[i-1] + x[i])%MOD;
    	py[i] = (py[i-1] + y[i])%MOD;
	}
    rep(i,1,n)cin>>dat[i];
    build(1,1,n);
    while(q--){
    	cin>>ty>>a>>b;
    	if(ty==1)upd(1,1,n);
		else cout<<que(1,1,n)<<endl;
	}
    return 0;
}