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
const int MAX = 1e6+500;
const ll MAX2 = 11;
const ll MOD = 1000003;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,k,dp[65][65][2],x,y,z,nw;

ll f(int pos,int cnt,bool st){
	if(pos<0)return cnt;
	ll &ret = dp[pos][cnt][st];
	if(ret!=-1)return ret;
	if(st)ret = f(pos-1,cnt+1,1) + f(pos-1,0,1);
	else {
		if(k&(1ll<<pos))ret = f(pos-1,0,1) + f(pos-1,cnt+1,0);
		else ret = f(pos-1,0,0);
	}
	if(ret>=MOD-1)ret-= MOD-1;
	return ret;
}

inline ll pw(ll x,ll y){
	ll ret = 1;
	y%= MOD-1;
	while(y){
		if(y&1)ret = ret*x%MOD;
		x = x*x%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
//  cout<<fixed<<setprecision(10);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if(n<=60 && (1ll<<n)<k)return cout<<"1 1\n",0;
    
    --k;
    x = 1;
    y = nw = pw(2,n);
    y = pw(y,k);
    rep(i,1,k){
    	--nw;
    	x = x*nw%MOD;
    	if(!x)break;
	}
	
    mems(dp,-1); --k;
    z = pw(pw(2,f(60,0,0)),MOD-2);
    x = x*z%MOD, y = y*z%MOD;
    x = y-x;
    if(x<0)x+= MOD;
    cout<<x<<' '<<y<<endl;
    return 0;
}