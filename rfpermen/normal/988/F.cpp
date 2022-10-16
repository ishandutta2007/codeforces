#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int a,n,m,le,ri,z,x[MAX],dp[MAX][MAX];
bool st[MAX];

int f(int nw,int ls){
	if(nw==a)return 0;
	int &ret = dp[nw][ls];
	if(ret!=-1)return ret;
	ret = MOD;
	if(x[nw]!=MOD&&ls!=nw)ret = f(nw,nw);
	if(ls!=a)ret = min(ret,f(nw+1,ls)+x[ls]);
	if(!st[nw+1])ret = min(ret,f(nw+1,a));
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>n>>m;
    rep(i,1,n){
    	cin>>le>>ri;
    	rep(j,le+1,ri)st[j] = 1;
	}
	rep(i,0,a)x[i] = MOD;
	rep(i,1,m)cin>>le>>z, x[le] = min(x[le],z);
	x[a] = 0;
	memset(dp,-1,sizeof dp);
	cout<<(f(0,a)<MOD ? f(0,a) : -1)<<endl;
    return 0;
}