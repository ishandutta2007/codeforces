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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 2e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,a,b,c,d,dp[MAX],x[MAX],y[MAX],z[MAX],sf[MAX],ans,spe;

ll f(ll nw){
	if(!nw)return -d;
	if(dp[nw]!=-1)return dp[nw];
	ll ret = INF;
	if(nw==1)ret = min(y[nw] + d*2,z[nw]) + d + f(0);
	else ret = min(z[nw] + d + f(nw-1), y[nw]+y[nw-1] + 4*d + f(nw-2));
	return dp[nw] = ret;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("circular_circles_input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b>>c>>d;
    //pas lagi mau double kita perlu cek stage terakhir untung pake laser atau gak
    //ada gun only cuy
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)y[i] = min(a+b,a*(x[i]+2));
    rep(i,1,n)z[i] = a*x[i]+c;
    spe = min(y[n]+d*2, z[n]);
    rap(i,n-1,1)sf[i] = y[i] + sf[i+1];
    mems(dp,-1);
    ans = f(n);
//    db(ans);
    asd(i,1,n)ans = min(ans,sf[i] + (n-i)*d*2 + spe + d + f(i-1));//, db(sf[i] + (n-i)*d*2 + spe + d + f(i-1));
    cout<<ans<<endl;
    return 0;
}