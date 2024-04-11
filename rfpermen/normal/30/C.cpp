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
#define rng() (rand()<<16)|rand()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,ans,dp[MAX][MAX];
pair<pll,pll> x[MAX];
double z;

ll f(int nw,int ls){
	if(nw>n)return 0;
	ll &ret = dp[nw][ls];
	if(ret!=-1)return ret;
	if(	(x[nw].sf-x[ls].sf)*(x[nw].sf-x[ls].sf) + (x[nw].ss-x[ls].ss)*(x[nw].ss-x[ls].ss) <= 
		(x[nw].ff-x[ls].ff)*(x[nw].ff-x[ls].ff))ret = f(nw+1,nw) + x[nw].fs;
	return ret = max(ret,f(nw+1,ls));
}

int main(){
  cout<<fixed<<setprecision(10);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i].sf>>x[i].ss>>x[i].ff>>z;
    	x[i].fs = round(z*10000000);
	}
	sort(x+1,x+1+n);
	mems(dp,-1);
	rep(i,1,n)ans = max(ans,f(i,i));
	cout<<ans/10000000.0<<endl;
    return 0;
}