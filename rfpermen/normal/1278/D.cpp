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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,p[MAX],a,b,cnt,hs[MAX<<1],tf[MAX],rt[MAX],hit,id;
pii x[MAX];
vector<int> ver;

struct tr{
	int le,ri,cnt;
}tree[MAX*20];

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

void upd(int ls,int nw,int le,int ri,int tgt){
	tree[nw] = tree[ls];
	if(le==ri){tree[nw].cnt = 1; return;}
	int mid = le+ri>>1;
	if(tgt<=mid)tree[nw].le = ++id, upd(tree[ls].le,id,le,mid,tgt);
	else tree[nw].ri = ++id, upd(tree[ls].ri,id,mid+1,ri,tgt);
	tree[nw].cnt = tree[tree[nw].le].cnt + tree[tree[nw].ri].cnt;
	return;
}

void dfs(int ls,int nw,int le,int ri,int tgt){
	if(ri<=tgt)return;
	if(le==ri){
		b = par(tf[le]);
		if(a==b){cout<<"NO\n"; exit(0);}
		p[b] = a;
		++cnt;
		return;
	}
	int mid = le+ri>>1;
	int i = tree[ls].le, j = tree[nw].le;
	if(tree[j].cnt-tree[i].cnt)dfs(i,j,le,mid,tgt);
	i = tree[ls].ri, j = tree[nw].ri;
	if(tree[j].cnt-tree[i].cnt)dfs(i,j,mid+1,ri,tgt);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi>>x[i].se, p[i] = i, hs[x[i].se] = 1;
    rep(i,1,1000000)if(hs[i])hs[i] = ++hit;
    sort(x+1,x+1+n);
    rep(i,1,n){
    	tf[hs[x[i].se]] = i;
    	ver.pb(x[i].fi);
    	rt[i] = ++id;
    	upd(rt[i-1],rt[i],1,n,hs[x[i].se]);
	}
	auto it = ver.begin();
	rep(i,1,n){
		it = lower_bound(all(ver),x[i].se);
		a = par(i);
		dfs(rt[i],rt[it-ver.begin()],1,n,hs[x[i].se]);
	}
	cout<<(cnt==n-1 ? "YES\n" : "NO\n");
    return 0;
}