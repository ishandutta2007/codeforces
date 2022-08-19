#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<complex>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define dels(x,y) x = (x-(y)+mod)%mod;
#define muls(x,y) x = ((ll)x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 350, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int dp[MX][MX];
int n, n2, m, m2, x;

int f(){
	rep(j,m2)rep(k,m2) dp[j][k] = 1;
	rep(i,n){
		drep(j,m2)drep(k,m2){
			if(j && k && j<=k){
				if(j <= x) dp[j][k] = dp[j-1][k-1];
				else dp[j][k] = (dp[j-1][k-1]-dp[x-1][k-1]+mod)%mod;
			} else dp[j][k] = 0;
		}
		rep(j,m2)rrep(k,m) adds(dp[j][k],dp[j][k-1]);
		rrep(j,m)rep(k,m2) adds(dp[j][k],dp[j-1][k]);
		//rep(j,m+1){rep(k,j+1) printf("%d ",dp[j][k]); puts("");}
	}
	dels(dp[m][m],dp[x-1][m]);
	return dp[m][m];
}

int g(){
	dp[0][0] = 1;
	rrep(i,m){
		drep(j,n2)drep(k,j+1){
			if(i == x){
				adds(dp[j+1][k+1],dp[j][k]);
				adds(dp[j+1][k],dp[j][k]);
				dp[j][k] = 0;
			} else {
				adds(dp[j+1][k+1],dp[j][k]);
				adds(dp[j+1][k],dp[j][k]);
				if(j != k) adds(dp[j][k+1],dp[j][k]);
			}
		}
		//rep(j,n2){rep(k,n2) printf("%d ",dp[j][k]); puts("");}puts("");
	}
	
	return dp[n][n];
}

int main(){
	cin >> n >> m >> x;
	n2 = n+1; m2 = m+1;
	
	ll res;
	if(m < 317) res = f(); else res = g();
	ll p = 1;
	rrep(i,n) muls(p,i);
	muls(res,p);
	
	cout << res << endl;
	
	return 0;
}