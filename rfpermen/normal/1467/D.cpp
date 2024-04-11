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
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,k,q,x[MAX],dp[2][MAX],res[MAX],ans,a,b,mem[MAX][MAX];
bool nw,ls;

ll f(int nw,int rem){
	if(!nw||nw>n)return 0;
	if(!rem)return 1;
	if(mem[nw][rem]!=-1)return mem[nw][rem];
	return mem[nw][rem] = (f(nw-1,rem-1)+f(nw+1,rem-1))%MOD;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>q;
    mems(mem,-1);
    rep(i,1,n)cin>>x[i], res[i] = f(i,k), dp[0][i] = 1;
    nw = 1;
    rep(lp,1,k){
    	mems(dp[nw],0);
    	rep(i,1,n){
    		dp[nw][i] = dp[ls][i-1]+dp[ls][i+1];
    		if(dp[nw][i]>=MOD)dp[nw][i]-= MOD;
    		res[i]+= dp[nw][i]*f(i,k-lp)%MOD;
		}
		nw^=1, ls^=1;
	}
	rep(i,1,n)res[i]%= MOD, ans+= res[i]*x[i]%MOD;
//	rep(i,1,n)cout<<res[i]<<' '; cout<<endl;
	while(q--){
		cin>>a>>b;
		k = b-x[a];
		x[a] = b;
		ans+= k*res[a]%MOD;
		ans%= MOD;
		if(ans<0)ans+= MOD;
		cout<<ans<<endl;
	}
    return 0;
}