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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int n,k,x[MAX],b[MAX];
double le,ri,mid,res,c[MAX][MAX],dp[MAX];
bool vis[MAX];

double f(int nw){
	if(nw==n)return 0.0;
	if(vis[nw])return dp[nw];
	vis[nw] = 1;
	dp[nw] = INF;
	rep(i,nw+1,n)dp[nw] = min(dp[nw],f(i) + c[nw][i] - mid*b[i]);
	return dp[nw];
}

int main(){
//	cout<<fixed<<setprecision(9);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>x[i]>>b[i];
    rep(i,0,n)rep(j,i+1,n)c[i][j] = sqrt(abs(x[j]-x[i]-k));
    le = 0.0, ri = 1000.0;
    rep(it,1,50){
    	mid = (le+ri)/2.0;
    	mems(vis,0);
    	if(f(0)<=0.0)ri = mid;
    	else le = mid;
	}
	
	int nw = 0;
	while(nw!=n){
		rep(i,nw+1,n)if(fabs(dp[nw]-(f(i) + c[nw][i] - mid*b[i]))<EPS){
			nw = i;
			cout<<nw<<' ';
			break;
		}
	}
	cout<<endl;
	return 0;
}