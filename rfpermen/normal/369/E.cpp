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
//#define ff fi.fi
//#define fs fi.se
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,q,k,z[MAX],ans[MAX],bit[MAX],id,ret;
pii x[MAX];
vector<piii> qq[MAX];

inline void upd(int i){
	for(; i<=1000000; i+=(i&-i))++bit[i];
}
inline int que(int i){
	ret = 0;
	for(; i>0; i-=(i&-i))ret+=bit[i];
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>x[i].fi>>x[i].se;
    sort(x+1,x+1+n);
    rep(i,1,q){
    	cin>>k;
    	rep(j,1,k)cin>>z[j];
    	rep(j,2,k)qq[z[j]-1].pb({z[j]-1,{i,-1}}), qq[z[j-1]].pb({z[j]-1,{i,1}});
    	qq[z[1]-1].pb({z[1]-1,{i,-1}});
		qq[1000001].pb({1000000,{i,-1}});
		qq[z[k]].pb({1000000,{i,1}});
    	ans[i] = n;
	}
	id = 1;
	rep(i,1,1000001){
		while(x[id].fi==i)upd(x[id].se), ++id;
		for(auto j:qq[i])ans[j.sf]+= j.ss*que(j.fi);
	}
	rep(i,1,q)cout<<ans[i]<<endl;
    return 0;
}