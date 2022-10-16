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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,N,f[MAX],pre[MAX],x[MAX],y[MAX],ans,z;
bool st;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

inline ll cb(int n,int k){
	return f[n] * pre[k] % MOD * pre[n-k] % MOD;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f[0] = 1;
    rep(i,1,200000)f[i] = f[i-1]*i%MOD;
    pre[200000] = pw(f[200000],MOD-2);
    rap(i,199999,0)pre[i] = pre[i+1]*(i+1)%MOD;
    cin>>n;
    N = n;
    n = (n-1)/4*4+1;
    rep(i,1,n){
    	if(i&1)x[i] = cb(n/2,i/2);
	}
//	db(n);
	while(n!=N){
		y[1] = 1;
		st = 0;
		rep(i,1,n){
			if(n&1){
				if(st)y[i+1] = x[i]+x[i+1];
				else y[i+1] = x[i]-x[i+1];
			}
			else {
				if(st)y[i+1] = x[i+1]-x[i];
				else y[i+1] = x[i]+x[i+1];
			}
			st^=1;
		}
		++n;
		rep(i,1,n)x[i] = y[i];
	}
//	rep(i,1,n)cout<<x[i]<<' '; cout<<endl;
//	return 0;
	
    rep(i,1,n){
    	cin>>z;
    	ans+= z*(x[i]%MOD)%MOD;
	}
	ans%= MOD;
	if(ans<0)ans+= MOD;
	cout<<ans<<endl;
    return 0;
}