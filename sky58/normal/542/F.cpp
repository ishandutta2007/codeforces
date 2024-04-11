#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
vector<pint> a;
int dp[1919][1919];
int zyo[1010];
int main()
{
	int n,m,x,y,out=0,inf=1145141919;
	cin>>n>>m;
	rep(i,n){
		cin>>x>>y;a.pb(mp(x,y));
	}
	zyo[0]=1;rep(i,1005) zyo[i+1]=min(1005,zyo[i]*2);
	sort(All(a));reverse(All(a));a.pb(mp(0,0));
	rep(i,1919) rep(j,1919) dp[i][j]=-inf;
	dp[0][zyo[m-a[0].fi]]=0;
	rep(i,n) rep(j,1010){
		if(dp[i][j]<0) continue;
		//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		int n2=min(1005,j*zyo[a[i].fi-a[i+1].fi]);
		dp[i+1][n2]=max(dp[i+1][n2],dp[i][j]);
		if(j>0){
			int ne=min(1005,(j-1)*zyo[a[i].fi-a[i+1].fi]);
			dp[i+1][ne]=max(dp[i+1][ne],dp[i][j]+a[i].se);
		}
		/*rep(j,a[i].fi+1){
			dp[i+1][a[i].fi+1]=max(dp[i+1][a[i].fi+1],dp[i][j]+a[i].se);
		}
		rep(j,m+1) dp[i+1][j]=max(dp[i][j],dp[i+1][j]);*/
	}
	rep(i,1010) out=max(out,dp[n][i]);
	cout<<out<<endl;
}