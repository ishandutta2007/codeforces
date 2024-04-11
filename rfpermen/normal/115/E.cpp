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
#define rng() ((rand()<<16)|rand())
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
const int block = 312;

int n,m,a,b,c,x[MAX];
ll tree[1<<19], lz[1<<19], ans, val;
vector<pii> v[MAX];

inline void f(int id,int le,int ri){
	tree[id]+= lz[id];
	if(le!=ri)lz[lc]+= lz[id], lz[rc]+= lz[id];
	lz[id] = 0;
	return;
}

void upd(int id,int le,int ri){
	if(lz[id])f(id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){lz[id] = val; f(id,le,ri); return;}
	int mid = le+ri>>1;
	upd(lc,le,mid), upd(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x[i];
    rep(i,1,m){
    	cin>>a>>b>>c;
    	v[b].pb({a,c});
	}
	rep(i,1,n){
		a = b = i, val = ans;
		upd(1,1,n);
		a = 1, b = i, val = -x[i];
		upd(1,1,n);
		for(pii j:v[i])b = j.fi, val = j.se, upd(1,1,n);
		ans = max(ans,tree[1]);
	}
	cout<<ans<<endl;
    return 0;
}