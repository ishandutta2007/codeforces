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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double dp[1100][1100],sum[1100][1100];
int main()
{
	int i,j,n,m,a,b;double out=0.0;
	rep(i,1100) rep(j,1100) dp[i][j]=sum[i][j]=0.0;
	cin>>n>>m;
	rep(i,n){
		cin>>a;dp[a-1][i]=1.0;
	}
	rep(i,m){
		cin>>a>>b;a--;b--;
		rep(j,n) dp[j][a]=dp[j][b]=(dp[j][a]+dp[j][b])/2;
	}
	for(i=n-1;i>=0;i--) rep(j,n){
		sum[i][j]=dp[i][j];
		if(i<n-1) sum[i][j]+=sum[i+1][j];
		if(j>0) sum[i][j]+=sum[i][j-1];
		if(i<n-1 && j>0) sum[i][j]-=sum[i+1][j-1];
	}
	rep(i,n-1) rep(j,n){
		out+=dp[i][j]*sum[i+1][j]/2;
		if(j>0) out+=dp[i][j]*sum[i+1][j-1]/2;
	}
	printf("%.12f\n",out);
	return 0;
}