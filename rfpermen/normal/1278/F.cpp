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
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

ll n,m,k,dp[MAX],ls,nw[MAX];

inline ll pw(ll x,ll y){
	ll ret = 1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //E(x) = sigma x = 0->n (x * nCx * p^x * (1-p)^(n-x)) = np (coret x nya di kombin-nya)
    //E(x^2) = n*(n-1)*p^2 + E(x)
    //E(x^3) = n*(n-1)*(n-2)*p^3 + 3*E(x^2) - 2*E(x)
    cin>>n>>m>>k;
    m = pw(m,MOD-2);
    ls = 1;
    rep(i,1,k){
    	ls = ls*(n-i+1) % MOD * m % MOD;
    	nw[i] = 1;
    	dp[i] = ls;
    	rap(j,i-1,1){
    		nw[j] = (nw[j-1]-nw[j]*(i-1))%MOD;
    		dp[i] = (dp[i] - nw[j]*dp[j])%MOD;
		}
	}
	if(dp[k]<0)dp[k]+=MOD;
	cout<<dp[k]<<endl;
    return 0;
}