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
#define size(n) ((int)(n).size())
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
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,q,x[MAX],nw,k,res;
ll ans;
vector<int> v[MAX];
vector<ll> pf[MAX];

void build(int id){
	v[id].pb(0);
	if(lc>n){
		pf[id].pb(0);
		return;
	}
	build(lc);
	if(rc<=n){
		build(rc);
		int a = 0, b = 0;
		while(a<size(v[lc]) && b<size(v[rc])){
			if(v[lc][a]+x[lc] < v[rc][b]+x[rc])v[id].pb(v[lc][a]+x[lc]), ++a;
			else v[id].pb(v[rc][b]+x[rc]), ++b;
		}
		while(a<size(v[lc]))v[id].pb(v[lc][a]+x[lc]), ++a;
		while(b<size(v[rc]))v[id].pb(v[rc][b]+x[rc]), ++b;
	}
	else {
		for(int i:v[lc])v[id].pb(i+x[lc]);
	}
	ll ls = 0;
	for(int i:v[id]){
		ls+= i;
		pf[id].pb(ls);
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,2,n)cin>>x[i];
    build(1);
    while(q--){
    	cin>>nw>>k;
    	ans = 0;
    	res = lower_bound(all(v[nw]),k) - v[nw].begin();
    	if(res)ans+= (ll)k*res - pf[nw][res-1];
    	while(nw!=1){
    		k-= x[nw];
    		if(k<1)break;
    		nw^= 1;
    		if(nw<=n){
    			k-= x[nw];
				res = lower_bound(all(v[nw]),k) - v[nw].begin();
				if(res)ans+= (ll)k*res - pf[nw][res-1];
    			k+= x[nw];
			}
			nw>>=1;
			if(nw)ans+= k;
		}
		cout<<ans<<endl;
	}
    return 0;
}