#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 4e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,en,x[MAX],pf[20][MAX];
ll cs[20][20],dp[1<<20];


ll f(int mask){
	if(mask==en)return 0;
	if(dp[mask]!=-1)return dp[mask];
	ll ret = INF, swp;
	int nx;
	rep(i,0,19){
		if(mask&(1<<i))continue;
		nx = mask|(1<<i);
		swp = 0;
		rep(j,0,19)if((nx&(1<<j))!=0)swp+=cs[j][i];
		ret = min(ret,f(nx)+swp);
	}
	return dp[mask] = ret;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	en = (1<<20)-1;
	rep(i,1,n){
		cin>>x[i], --x[i];
		rep(j,0,19)pf[j][i] = pf[j][i-1];
		++pf[x[i]][i];
		rep(j,0,19)if(j!=x[i])cs[j][x[i]]+=pf[j][i];
	}
	memset(dp,-1,sizeof dp);
	cout<<f(0)<<endl;
	return 0;
}