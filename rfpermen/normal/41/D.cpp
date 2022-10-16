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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
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

int n,m,k,x[MAX][MAX],ans = -1,st,dp[MAX][MAX][15];

int f(int r,int c,int md){
	if(c<1||c>m)return -1e9;
	if(!r)return (md ? -1e9 : 0);
	if(dp[r][c][md]!=-1)return dp[r][c][md];
	return dp[r][c][md] = max(f(r-1,c+1,(md+x[r][c])%k),f(r-1,c-1,(md+x[r][c])%k)) + x[r][c];
}

void bt(int r,int c,int md){
	if(r==1)return;
	if(dp[r][c][md]==f(r-1,c+1,(md+x[r][c])%k)+x[r][c])cout<<'R', bt(r-1,c+1,(md+x[r][c])%k);
	else cout<<'L', bt(r-1,c-1,(md+x[r][c])%k);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    char c;
    cin>>n>>m>>k; ++k;
    rep(i,1,n)rep(j,1,m){
    	cin>>c;
    	x[i][j] = c-'0';
	}
	memset(dp,-1,sizeof dp);
	rep(i,1,m)if(f(n,i,0)>ans)ans = f(n,i,0), st = i;
	if(ans==-1)return cout<<ans,0;
	cout<<ans<<endl;
	cout<<st<<endl;
	bt(n,st,0);
    return 0;
}