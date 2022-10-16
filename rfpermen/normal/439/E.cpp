#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll tc,n,k,f[MAX],pre[MAX],p[MAX],dp[MAX],ans;
vector<int> fc[MAX];

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
	--n, --k;
	return f[n]*pre[k]%MOD * pre[n-k]%MOD;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,2,316){
    	if(p[i])continue;
    	for(int j = i; j<=100000; j+=i)p[j] = i;
	}
	f[0] = pre[0] = 1;
	rep(i,1,100000){
		f[i] = i*f[i-1]%MOD, pre[i] = pw(f[i],MOD-2);
		if(!p[i])p[i] = i;
	}
	dp[1] = 1;
	fc[1].pb(1);
	rep(i,2,100000){
		n = i/p[i];
		if(dp[n] && p[n]!=p[i])dp[i] = -dp[n];
		n = sqrt(i);
		rep(j,1,n)if(i%j==0){
			if(dp[j])fc[i].pb(j);
			if(dp[i/j])fc[i].pb(i/j);
		}
		if(n*n==i&&dp[n])fc[i].pob();
	}
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>k>>n;
    	ans = 0;
    	for(int j:fc[k])if(n<=k/j)ans+= dp[j]*cb(k/j,n);
    	ans%=MOD;
    	if(ans<0)ans+= MOD;
    	cout<<ans<<endl;
	}
	return 0;
}