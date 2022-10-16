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
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,m,k,x[MAX],p[MAX][MAX],dp[MAX][MAX][MAX];

ll f(int nw,int rem,int ls){
	if(rem<0)return 1e18;
	if(nw>n)return rem==0 ? 0 : 1e18;
	if(dp[nw][rem][ls]!=-1)return dp[nw][rem][ls];
	if(x[nw])return dp[nw][rem][ls] = f(nw+1,rem-(x[nw]!=ls),x[nw]);
	ll ret = 1e18;
	rep(i,1,m)ret = min(ret,f(nw+1,rem-(i!=ls),i)+p[nw][i]);
	return dp[nw][rem][ls] = ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)rep(j,1,m)cin>>p[i][j];
    memset(dp,-1,sizeof dp);
    cout<<(f(1,k,0)<1e15 ? f(1,k,0) : -1)<<endl;
    return 0;
}