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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define out(x,y) cout << ">> " << x << " " << y << endl
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
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,s,k,y[MAX],nw,tree[1<<18],a,b,val;
pii x[MAX];
set<int> v;

void upd(int id,int le,int ri){
	if(le==ri){
		tree[id] = val;
		return;
	}
	int mid = le+ri>>1;
	if(a<=mid)upd(lc,le,mid);
	else upd(rc,mid+1,ri);
	tree[id] = min(tree[lc],tree[rc]);
	return;
}

int que(int id,int le,int ri){
	if(le>b||ri<a)return MOD;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return min(que(lc,le,mid),que(rc,mid+1,ri));
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s>>k;
    rep(i,1,n)cin>>x[i].fi, x[i].se = i;
    sort(x+1,x+1+n);
    nw = 1;
    auto it = v.begin();
    rep(i,1,n){
    	while(x[nw].fi<x[i].fi-s)v.insert(x[nw].se), ++nw;
    	it = v.lower_bound(x[i].se);
    	y[x[i].se] = it==v.end() ? n+1 : (*it);
	}
	v.clear();
	nw = n;
	rap(i,n,1){
    	while(x[nw].fi>x[i].fi+s)v.insert(x[nw].se), --nw;
    	it = v.lower_bound(x[i].se);
    	y[x[i].se] = min(y[x[i].se], it==v.end() ? n+1 : (*it));
	}
	rap(i,n-1,1)y[i] = min(y[i],y[i+1]);
	val = MOD;
	rep(i,1,n)a = i, upd(1,1,n+1);
	++n;
	rap(i,n-1,1){
		if(i+k<=y[i]){
			a = i+k, b = y[i];
			val = que(1,1,n)+1;
			a = i;
			upd(1,1,n);
		}
		else val = MOD;
	}
	if(val>n)val = -1;
	cout<<val<<endl;
    return 0;
}