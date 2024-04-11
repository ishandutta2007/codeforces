#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll n,x[MAX],t,f[MAX],pre[MAX],ans,tmp,inv,dv;

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

inline void que(ll a,ll b,ll k){
	a = max(0ll,a), b = min(k,b);
	if(a>b)return;
	rep(i,a,b)tmp = (tmp + f[k] * pre[i] % MOD * pre[k-i])%MOD;
	return;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>t;
    f[0] = pre[0] = 1;
    rep(i,1,n)cin>>x[i], x[i]+= x[i-1], f[i] = f[i-1]*i%MOD, pre[i] = pw(f[i],MOD-2);
    inv = pw(2,MOD-2), dv = inv, x[n+1] = INF;
    
    rep(i,1,n){
    	tmp = 0;
    	if(t-x[i+1]>=0&&t-x[i+1]<=i)tmp = f[i] * pre[t-x[i+1]] % MOD * pre[i-t+x[i+1]] % MOD * inv % MOD;
		que(t-x[i+1]+1,t-x[i],i);
    	ans = (ans + i*tmp % MOD * dv)%MOD;
    	dv = dv*inv % MOD;
	}
	cout<<ans<<endl;
    return 0;
}