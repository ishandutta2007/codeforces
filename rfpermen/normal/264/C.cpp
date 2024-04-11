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
#define out(x,y) cout << ">> " << x << " " << y << endl
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
const int MAX = 2e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,q,c[MAX];
ll ans,dp[MAX],x[MAX],a,b,res;
pair<pair<ll,int>,ll> mx;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)cin>>c[i];
    while(q--){
    	cin>>a>>b;
    	mems(dp,0), mx = {{0,0},0}, ans = 0;
    	rap(i,n,1){
    		if(mx.fs!=c[i])res = max(mx.ff,dp[c[i]]);
    		else res = max(mx.se,dp[c[i]]);
    		ans = max(ans,res + x[i]*b);
    		
    		dp[c[i]] = max(dp[c[i]],res + x[i]*a);
    		
    		res+= x[i]*b;
    		if(res>mx.ff){
    			if(c[i]!=mx.fs)mx.se = mx.ff, mx.fs = c[i];
				mx.ff = res;
			}
			else if(res>mx.se && c[i]!=mx.fs)mx.se = res;
		}
		cout<<ans<<endl;
	}
    return 0;
}