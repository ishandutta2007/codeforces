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
#define N 50
int a[30],b[30];
lint dp[30][30][30];
lint inf=123456789012345LL;

map<int,vector <vector <lint> > > me;
vector <vector <lint> > tmp,one,ret;
vector <lint> cl;

vector <vector <lint> > rec(int a){
	if(me[a].size()>0) return me[a];
	vector <vector <lint> > ret=tmp,mae=rec(a/2),ato=rec(a-a/2);
	rep(i,N) rep(j,N) rep(k,N){
		ret[i][j]=min(ret[i][j],mae[i][k]+ato[k][j]);
	}
	return me[a]=ret;
}
int main()
{
	int n,m;cin>>n>>m;
	rep(i,n) cin>>a[i];rep(i,n) cin>>b[i];
	rep(i,30) rep(j,30) rep(k,30) dp[i][j][k]=inf;dp[0][0][0]=0;
	rep(i,n) rep(j,n+1) rep(k,n+1){
		dp[i+1][j+1][k]=min(dp[i+1][j+1][k],dp[i][j][k]+a[i]);
		if(j<1) dp[i+1][j][k+1]=min(dp[i+1][j][k+1],dp[i][j][k]+b[i]);
		else dp[i+1][j-1][k]=min(dp[i+1][j-1][k],dp[i][j][k]+b[i]);
	}
	//cout<<dp[2][0][0]<<endl;
	//rep(i,n+1) rep(j,n+1) cout<<i<<' '<<j<<' '<<dp[n][i][j]<<endl;
	rep(i,N) cl.pb(inf);rep(i,N) tmp.pb(cl);one=tmp;
	rep(i,N) rep(j,N) rep(k,N){
		if(i-k<=n && j-k<=n && i>=k && j>=k) one[i][j]=min(one[i][j],dp[n][j-k][i-k]);
	}
	me[1]=one;
	ret=rec(m);
	cout<<ret[0][0]<<endl;
	return 0;
}