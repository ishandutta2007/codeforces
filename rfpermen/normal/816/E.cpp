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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,bt,x[MAX],y[MAX],z,dp[2][MAX][MAX],sz[MAX],ans,tmp[MAX];
vector<int> v[MAX];

void f(int nw){
	int hit = 1, la;
	dp[1][nw][1] = y[nw];
	dp[0][nw][1] = x[nw];
	
	for(int i:v[nw]){
		f(i);
		la = hit+sz[i];
//		cout<<i<<" = "<<sz[i]<<endl;
		rep(j,0,la)tmp[j] = dp[0][nw][j];
		rep(j,0,hit){
			rep(k,1,sz[i])tmp[k+j] = min(tmp[k+j], dp[0][nw][j] + dp[0][i][k]);
		}
		rep(j,0,la)dp[0][nw][j] = tmp[j];
		
		rep(j,1,la)tmp[j] = dp[1][nw][j];
		rep(j,1,hit){
			rep(k,1,sz[i])tmp[k+j] = min(tmp[k+j], dp[1][nw][j] + min(dp[1][i][k],dp[0][i][k]));
		}
		rep(j,1,la)dp[1][nw][j] = tmp[j];
		hit = la;
	}
//	cout<<"_____________\n";
//	cout<<"nw = "<<nw<<endl;
//	cout<<"0 = ";
//	rep(i,1,hit)cout<<dp[0][nw][i]<<' '; cout<<endl;
//	cout<<"1 = ";
//	rep(i,1,hit)cout<<dp[1][nw][i]<<' '; cout<<endl;
	sz[nw] = hit;
	return;
}

int main(){
// cout<<fixed<<setprecision(6);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>bt;
    rep(i,1,n){
    	cin>>x[i]>>y[i]; y[i] = x[i]-y[i];
//    	db(y[i]);
    	if(i>1)cin>>z, v[z].pb(i);
	}
	rep(i,1,n){
		dp[1][i][0] = INF;
		rep(j,1,n)dp[0][i][j] = dp[1][i][j] = INF;
	}
	f(1);
//	rep(i,1,n){
//		rep(j,1,sz[i]){
//			if(dp[0][i][j]<dp[1][i][j])cout<<"<> "<<i<<' '<<j<<endl;
//		}
//	}
//	rep(i,1,n){
//		cout<<dp[0][1][i]<<' ';
//	}
//	cout<<endl;
	rep(i,1,n)if(min(dp[0][1][i], dp[1][1][i])<=bt)ans = i;
	cout<<ans<<endl;
    return 0;
}