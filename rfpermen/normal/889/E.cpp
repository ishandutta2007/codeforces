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
//#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1100000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 1000;

ll n,x[MAX],nr,nx;
map<ll,ll> dp[MAX];
vector<pair<ll,int>> v;

ll f(int nw,ll r){
	if(!r)return 0;
	if(nw==n)return n*r;
	if(dp[nw].count(r))return dp[nw][r];
	if(r<x[nw+1])return dp[nw][r] = f(nw+1,r);
	nr = r%x[nw+1];
	nx = (*upper_bound(all(v),mp(nr,MAX))).se;
	ll ret = f(nx,nr) + nw*(r-r%x[nw+1]);
	nr = x[nw+1]-1;
	nx = (*upper_bound(all(v),mp(nr,MAX))).se;
	return dp[nw][r] = max(ret, f(nx,nr) + nw*(r-r%x[nw+1]-x[nw+1]));
}

int main(){
// cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>x[i];
    	if(i>1)x[i] = min(x[i-1],x[i]);
	}
	rap(i,n,1)if(x[i]!=x[i+1])v.pb({x[i],i});
	cout<<f((*upper_bound(all(v),mp(x[1]-1,MAX))).se,x[1]-1)<<endl;
	return 0;
}