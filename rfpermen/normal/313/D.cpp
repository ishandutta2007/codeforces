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
const int MAX = 3e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,z,mn[MAX][MAX],dp[MAX][MAX],x[MAX][MAX],a,b,c,k;

ll f(int nw,int rem){
	if(rem<=0)return 0;
	if(nw>n)return INF;
	ll &ret = dp[nw][rem];
	if(ret!=-1)return ret;
	ret = f(nw+1,rem);
	rep(i,nw,n)if(x[nw][i])ret = min(ret,f(i+1,rem-(i-nw+1)) + x[nw][i]);
	return ret;
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>z>>k;
    rep(i,1,n)rep(j,1,n)mn[i][j] = MOD;
    while(z--){
    	cin>>a>>b>>c;
    	mn[a][b] = min(mn[a][b],c);
	}
	rep(i,1,n){
		z = MOD;
		rep(j,1,i){
			z = min(z,mn[j][i]);
			if(z!=MOD)x[j][i] = z;
		}
	}
	mems(dp,-1);
	z = f(1,k);
	if(z>=INF)z = -1;
	cout<<z<<endl;
    return 0;
}