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
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define add(x,y) x = (x+(y))%mod
#define pb push_back
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 3005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

char c[MX][MX];
int dp1[MX][MX];
int dp2[MX][MX];

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	
	rep(i,n) scanf("%s",c[i]);
	
	dp1[1][0] = 1;
	dp2[0][1] = 1;
	rep(i,n)rep(j,m){
		if(c[i][j] == '#') dp1[i][j] = dp2[i][j] = 0;
		add(dp1[i+1][j],dp1[i][j]);
		add(dp1[i][j+1],dp1[i][j]);
		add(dp2[i+1][j],dp2[i][j]);
		add(dp2[i][j+1],dp2[i][j]);
	}
	
	//rep(i,n){rep(j,m) printf("%d ",dp1[i][j]); puts("");}
	//rep(i,n){rep(j,m) printf("%d ",dp2[i][j]); puts("");}
	
	ll ans = (ll)dp1[n-1][m-2]*dp2[n-2][m-1]%mod;
	ans = (ans-(ll)dp1[n-2][m-1]*dp2[n-1][m-2]%mod);
	ans = (ans+mod)%mod;
	cout << ans << endl;
	
	return 0;
}