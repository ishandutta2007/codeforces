#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC target("sse4.2") //optimize 
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
//#define lc (id<<1)
//#define rc ((id<<1)|1)
#define lc(id) tree[id].le
#define rc(id) tree[id].ri
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

struct tr{
	int cnt,le,ri;
}tree[MAX*200];

int n,q,nw,z[MAX],a,b,x,y,rt[MAX];
bool st;

void build(int id,int le,int ri){
	if(le==ri){tree[id].cnt = (z[le]==a); return;}
	int mid = le+ri>>1;
	lc(id) = ++nw, rc(id) = ++nw;
	build(lc(id),le,mid), build(rc(id),mid+1,ri);
	tree[id].cnt = tree[lc(id)].cnt + tree[rc(id)].cnt;
	return;
}

void upd(int idx,int idy,int le,int ri){
	if(le>b||ri<a)return;
	if(le==ri){tree[idx].cnt = 0, tree[idy].cnt = 1; return;}
	int mid = le+ri>>1;
	
	if(le>=a&&mid<=b && tree[lc(idx)].cnt>tree[lc(idy)].cnt)swap(lc(idx),lc(idy));
	if(tree[lc(idx)].cnt)upd(lc(idx),lc(idy),le,mid);
	
	if(mid+1>=a&&ri<=b && tree[rc(idx)].cnt>tree[rc(idy)].cnt)swap(rc(idx),rc(idy));
	if(tree[rc(idx)].cnt)upd(rc(idx),rc(idy),mid+1,ri);
	
	tree[idx].cnt = tree[lc(idx)].cnt + tree[rc(idx)].cnt;
	tree[idy].cnt = tree[lc(idy)].cnt + tree[rc(idy)].cnt;
	return;
}

void que(int id,int le,int ri){
	if(le==ri){z[le] = a; return;}
	int mid = le+ri>>1;
	if(tree[lc(id)].cnt)que(lc(id),le,mid);
	if(tree[rc(id)].cnt)que(rc(id),mid+1,ri);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==1){
    	cin>>nw;
    	cin>>q;
    	while(q--){
    		cin>>a>>b>>x>>y;
    		if(nw==x)nw = y;
		}
		cout<<nw<<endl;
		return 0;
	}
    rep(i,1,n)cin>>z[i];
    rep(i,1,100)a = i, rt[i] = ++nw, build(nw,1,n);
    
    cin>>q;
    while(q--){
    	cin>>a>>b>>x>>y;
    	if(x==y)continue;
    	upd(rt[x],rt[y],1,n);
	}
	
	rep(i,1,100)a = i, que(rt[i],1,n);
	rep(i,1,n)cout<<z[i]<<' '; cout<<endl;
    return 0;
}