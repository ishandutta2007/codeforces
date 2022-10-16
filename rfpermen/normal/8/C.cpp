#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,en,x[25],y[25],dp[1<<24],v[25][25],pre[25][25];

int f(int mask){
	if(mask==en)return 0;
	if(dp[mask]!=-1)return dp[mask];
	int ret = MOD, sz;
	vector<int> z;
	rep(j,0,n)if((mask&(1<<j))==0)z.pb(j);
	sz = z.size()-1;
	rep(i,0,sz)ret = min(ret, f(mask|(1<<z[i])|(1<<z[0])) + pre[z[0]][z[i]]);
	return dp[mask] = ret;
}

void bt(int mask){
	if(mask==en)return;
	int sz;
	vector<int> z;
	rep(j,0,n)if((mask&(1<<j))==0)z.pb(j);
	sz = z.size()-1;
	rep(i,0,sz){
		if(dp[mask] == f(mask|(1<<z[i])|(1<<z[0])) + pre[z[0]][z[i]]){
			if(!i)cout<<' '<<z[0]+1<<" 0";
			else cout<<' '<<z[0]+1<<' '<<z[i]+1<<" 0";
			bt(mask|(1<<z[i])|(1<<z[0]));
			break;
		}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(2);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x[0]>>y[0];
    cin>>n;
    rep(i,1,n)cin>>x[i]>>y[i];
    rep(i,0,n)rep(j,0,n)if(i!=j)v[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
    rep(i,1,n)rep(j,1,n){
    	if(i==j)pre[i-1][j-1] = v[0][i]<<1;
    	else pre[i-1][j-1] = v[0][i]+v[i][j]+v[j][0];
	}
	en = (1<<n)-1, --n;
	mems(dp,-1);
	cout<<f(0)<<"\n0";
	bt(0);
	cout<<endl;
	return 0;
}