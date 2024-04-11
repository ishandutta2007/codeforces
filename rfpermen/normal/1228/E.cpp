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
//#define sf se.fi
//#define ss se.se
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
const int MAX = 255;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,c[MAX][MAX],k,kp[MAX],k1p[MAX],dp[MAX][MAX],ans;

ll f(int r,int rem){
	if(r>n)return rem==0;
	if(dp[r][rem]!=-1)return dp[r][rem];
	ll ret = 0;
	rep(i,1,rem){
		ret = (ret+c[rem][i]*kp[n-rem]%MOD*k1p[rem-i]%MOD*f(r+1,rem-i))%MOD;
	}
	if(rem!=n)ret = (ret+k1p[rem]*(kp[n-rem]-k1p[n-rem])%MOD*f(r+1,rem))%MOD;
	return dp[r][rem] = ret;
}

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    c[0][0] = 1;
    rep(i,1,250){
    	c[i][0] = 1;
    	rep(j,1,i)c[i][j] = (c[i-1][j] + c[i-1][j-1])%MOD;
	}
	cin>>n>>k;
	kp[0] = k1p[0] = 1;
	rep(i,1,n)kp[i] = (kp[i-1]*k)%MOD, k1p[i] = (k1p[i-1]*(k-1))%MOD;
	memset(dp,-1,sizeof dp);
	ans = f(1,n);
	if(ans<0)ans+=MOD;
	cout<<ans<<endl;
    return 0;
}