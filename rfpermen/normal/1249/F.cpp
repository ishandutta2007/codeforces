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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 200+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int n,k,x[MAX],dp[MAX][MAX],z[MAX][MAX],a,b;
vector<int> v[MAX],tmp[MAX];
bool vis[MAX];
 
void tf(int nw,int par){
	for(int i:tmp[nw])if(i!=par){
		v[nw].pb(i);
		tf(i,nw);
	}
	return;
}
 
int f(int nw,int rem){
	if(dp[nw][rem]!=-1)return dp[nw][rem];
	int &ret = dp[nw][rem], o = max(k>>1,rem-1);
	ret = 0;
	if(!vis[nw]){
		for(int i:v[nw])rep(j,0,k)z[nw][j]+= f(i,j);
		vis[nw] = 1;
	}
	if(!rem)ret = x[nw] + z[nw][k], rem = 1;
	for(int i:v[nw]){
		rep(j,rem,k)ret = max(ret,z[nw][max(o,k-j)] - f(i,max(o,k-j)) + f(i,j-1));
	}
	return ret;
}
 
int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i];
    rep(i,2,n){
    	cin>>a>>b;
    	tmp[a].pb(b);
    	tmp[b].pb(a);
	}
	tf(1,0);
	memset(dp,-1,sizeof dp);
	cout<<f(1,0)<<endl;
    return 0;
}