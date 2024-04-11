#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
#define out(x,y) cout << ">> " << x << " " << y << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 600;

int n,m,x[MAX],y[MAX];
ll dp[MAX][MAX][27],ans,hit;
string s;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for(char c:s)x[++n] = c-'a'+1;
    cin>>s;
    for(char c:s)y[++m] = c-'a'+1;
//    rep(i,1,n)cout<<x[i]; cout<<endl;
//    rep(i,1,m)cout<<y[i]; cout<<endl;
    
    rep(i,1,n)rep(j,1,m)dp[i][j][0] = 1;
	++n, ++m;
    rep(i,1,n)rep(j,1,m)rep(ls,0,26)if(dp[i][j][ls]){
    	dp[i][j][ls]%= MOD;
    	if(x[i]!=ls)dp[i+1][j][x[i]]+= dp[i][j][ls];
    	if(y[j]!=ls)dp[i][j+1][y[j]]+= dp[i][j][ls];
	}
	rep(i,1,n)rep(j,1,m)rep(ls,1,26){
		ans+= dp[i][j][ls]%MOD;
//		if(dp[i][j][ls]){
//			cout<<i<<' '<<j<<' '<<ls<<" = "<<dp[i][j][ls]<<endl;
//		}
	}
	--n, --m;
	rep(i,1,n){
		hit = 1;
		rep(j,i+1,n){
			if(x[j-1]==x[j])break;
			++hit;
		}
		ans-= hit*m;
	}
	rep(i,1,m){
		hit = 1;
		rep(j,i+1,m){
			if(y[j-1]==y[j])break;
			++hit;
		}
		ans-= hit*n;
	}
	ans%= MOD;
	if(ans<0)ans+= MOD;
	cout<<ans<<endl;
    return 0;
}