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
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,x[MAX][MAX],dp[600][301][301];

int f(int nw,int r1,int c1,int r2,int c2){
	if(nw==n*2-1)return 0;
	if(dp[nw][r1][r2]!=-MOD2)return dp[nw][r1][r2];
	int ret = -MOD, nr1,nr2,nc1,nc2;
	rep(i,0,1){
		nr1 = r1+dr[i], nc1 = c1+dc[i];
		if(nr1<=n&&nc1<=n)
		rep(j,0,1){
			nr2 = r2+dr[j], nc2 = c2+dc[j];
			if(nr2<=n&&nc2<=n){
				if(nr1!=nr2)ret = max(ret,x[nr1][nc1]+x[nr2][nc2]+f(nw+1,nr1,nc1,nr2,nc2));
				else ret = max(ret,x[nr1][nc1]+f(nw+1,nr1,nc1,nr2,nc2));
			}
		}
	}
	return dp[nw][r1][r2] = ret;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)rep(j,1,n)cin>>x[i][j];
    rep(i,0,599)rep(j,1,300)rep(k,1,300)dp[i][j][k] = -MOD2;
    if(n==1)return cout<<x[1][1]<<endl,0;
    cout<<f(1,1,1,1,1)+x[1][1]<<endl;
	return 0;
}