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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 72+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;
 
int n,nx[MAX],x[MAX],dp[MAX][1<<20];
ll ans;
char c;

int f(int nw,int mask){
	if(nx[nw]==-1){
		if(!mask)return 0;
		return mask==(1<<__builtin_popcount(mask))-1;
	}
	
	if(dp[nw][mask]!=-1)return dp[nw][mask];
	
	int z = 0;
	ll ret = f(n+1,mask);
	
	rep(i,nx[nw],n){
		z = (z<<1)|x[i];
		if(z>20)break;
		ret+= f(i+1,mask|(1<<z-1));
	}
	return dp[nw][mask] = ret%MOD;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    mems(nx,-1);
    rep(i,1,n)cin>>c, x[i] = c=='1';
    rep(i,1,n){
    	rep(j,i,n)if(x[j]){
    		nx[i] = j;
    		break;
		}
	}
	mems(dp,-1);
	rep(i,1,n)ans+= f(i,0);
	cout<<ans%MOD<<endl;
	return 0;
}