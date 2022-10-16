#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll n,ans,tree[2][1<<20],lz[2][1<<20],y,z;
int a,b;
pll x[MAX];

inline void f(int i,int id,int le,int ri){
	tree[i][id]+=lz[i][id]*(ri-le+1);
	if(le!=ri)lz[i][lc]+=lz[i][id], lz[i][rc]+=lz[i][id];
	lz[i][id] = 0;
	return;
}

void upd(int i,int id,int le,int ri){
	if(lz[i][id])f(i,id,le,ri);
	if(le>b||ri<a)return;
	if(le>=a&&ri<=b){lz[i][id] = 1; f(i,id,le,ri); return;}
	int mid = le+ri>>1;
	upd(i,lc,le,mid), upd(i,rc,mid+1,ri);
	tree[i][id] = tree[i][lc] + tree[i][rc];
	return;
}

ll que(int i,int id,int le,int ri){
	if(lz[i][id])f(i,id,le,ri);
	if(le>b||ri<a)return 0;
	if(le>=a&&ri<=b)return tree[i][id];
	int mid = le+ri>>1;
	return que(i,lc,le,mid) + que(i,rc,mid+1,ri);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi, x[i].se = i;
    sort(x+1,x+1+n);
//    upd(0,1,1,n);
//    upd(1,1,1,n);
    ll id;
    rep(i,1,n){
    	id = x[i].se;
    	
    	a = 1, b = id;
    	upd(0,1,1,n);
    	y = que(0,1,1,n);
    	a = b = id;
    	y-= (que(0,1,1,n))*id;
    	
    	a = id, b = n;
    	upd(1,1,1,n);
    	z = que(1,1,1,n);
    	a = b = id;
    	z-= (que(1,1,1,n)-1)*(n-id+1);
    	
//    	cout<<x[i].fi<<' '<<y<<' '<<z<<endl;
    	
    	ans = (ans+x[i].fi*((id*z + y*(n-id+1))%MOD))%MOD;
	}
	cout<<ans<<endl;
	return 0;
}