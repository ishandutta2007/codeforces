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
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll n,a,b,val,x[MAX],z[MAX],pf[MAX],tree[1<<19],lz[1<<19],ans;

inline void f(int &id,int &le,int &ri){
	tree[id]+= lz[id];
	if(le!=ri)lz[lc]+= lz[id], lz[rc]+= lz[id];
	lz[id] = 0; return;
}

void build(int id,int le,int ri){
	if(le==ri){tree[id] = pf[le]; return;}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = min(tree[lc],tree[rc]);
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){lz[id] = val, f(id,le,ri); return;}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = min(tree[lc],tree[rc]);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)cin>>z[x[i]];
    rep(i,1,n)pf[i] = z[i]+pf[i-1];
    build(1,0,n);
    ans = MOD;
    rep(i,1,n-1){
    	val = z[x[i]];
    	a = 0, b = x[i]-1;
    	upd(1,0,n);
    	val = -z[x[i]];
    	a = x[i], b = n;
    	upd(1,0,n);
    	ans = min(ans,tree[1]);
	}
	cout<<ans<<endl;
    return 0;
}