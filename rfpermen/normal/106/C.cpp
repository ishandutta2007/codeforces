#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll k,n,a,b,x[11],c[11],d[11],dp[11][1005];

ll f(int pos,int rem){
	if(rem<0)return -1e18;
	if(pos==0)return rem/c[0]*d[0];
	if(dp[pos][rem]!=-1)return dp[pos][rem];
	ll ret = 0;
	rep(i,0,x[pos])ret = max(ret,f(pos-1,rem-c[pos]*i)+i*d[pos]);
	return dp[pos][rem] = ret;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k>>n>>c[0]>>d[0];
    rep(i,1,n)cin>>a>>b>>c[i]>>d[i], x[i] = a/b;
    memset(dp,-1,sizeof dp);
    cout<<f(n,k)<<endl;
	return 0;
}