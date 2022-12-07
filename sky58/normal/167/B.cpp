#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,double> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double dp[210][210][210];
int pro[210],ba[210];
int main()
{
	int i,j,k,n,a,b,x,y;vector <pint> c;double out=0.0;
	rep(i,210) rep(j,210) rep(k,210) dp[i][j][k]=0.0;
	cin>>n>>a>>b;dp[0][0][b]=1.0;
	rep(i,n) scanf("%d",&pro[i]);rep(i,n) scanf("%d",&ba[i]);
	rep(i,n) c.pb(mp(ba[i],0.01*pro[i]));
	sort(All(c));reverse(All(c));
	rep(i,n) rep(j,i+1) rep(k,207){
//		if(k<3) cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
		dp[i+1][j][k]+=dp[i][j][k]*(1.0-c[i].se);
		if(k+c[i].fi>=0) dp[i+1][j+1][min(205,k+c[i].fi)]+=dp[i][j][k]*c[i].se;
	}
//	rep(j,i+1) rep(k,207){if(k<3) cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;}
	REP(i,a,210) rep(j,210) out+=dp[n][i][j];
	printf("%.12f\n",out);
	return 0;
}