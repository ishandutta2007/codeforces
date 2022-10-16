#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int n,m,p[MAX],k,ans,x[3],a,b;
bool vis[MAX];
vector<int> v;

int par(int z){
	if(p[z]==z)return z;
	return p[z] = par(p[z]);
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,m)p[i] = i;
    rep(i,1,n){
    	cin>>k;
    	rep(j,1,k)cin>>x[j];
    	if(k==1){
    		a = par(x[1]);
    		if(!vis[a]){
    			vis[a] = 1;
    			v.pb(i);
			}
		}
		else {
			a = par(x[1]), b = par(x[2]);
			if(a!=b){
				if(vis[a] && vis[b])continue;
				if(vis[a])p[b] = a;
				else p[a] = b;
				v.pb(i);
			}
		}
	}
	ans = 1;
	rep(i,1,v.size())ans = ans*2%MOD;
	cout<<ans<<' '<<v.size()<<endl;
	for(auto i:v)cout<<i<<' '; cout<<endl;
    return 0;
}