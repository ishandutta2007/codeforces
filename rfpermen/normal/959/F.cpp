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
const int MAX = 2e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
ll n,q,x[MAX],ai,z[MAX],mul,id,ans[MAX];
piii y[MAX];
vector<int> v,br;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>x[i];
    rep(i,1,q)cin>>y[i].fi>>y[i].sf, y[i].ss = i;
    z[0] = mul = 1;
    v.pb(0);
    sort(y+1,y+1+q);
    rep(tc,1,q){
    	while(id!=y[tc].fi){
    		++id;
    		ai = x[id];
    		if(z[ai])mul = (mul<<1)%MOD;
    		else {
    			br.clear();
    			for(auto i:v){
    				z[i^ai]+= z[i];
					br.pb(i^ai); 
				}
				for(auto i:br)v.pb(i);
			}
		}
		ans[y[tc].ss] = z[y[tc].sf]*mul%MOD;
	}
	rep(i,1,q)cout<<ans[i]<<endl;
	return 0;
}