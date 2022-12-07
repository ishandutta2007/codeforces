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
#define N 255
int dp[30010][514];
int a[36436];
int main()
{
	memset(a,0,sizeof(a));
	int n,d,out=0,x;
	cin>>n>>d;
	rep(i,n){
		cin>>x;a[x]++;
	}
	memset(dp,-1,sizeof(dp));
	dp[d][N]=0;
	rep(i,30001) rep(j,512){
		if(dp[i][j]<0) continue;
		dp[i][j]+=a[i];
		out=max(out,dp[i][j]);
		//if(i<30) cout<<i<<' '<<j-N+d<<' '<<dp[i][j]<<endl;
		rep(k,3){
			int l=j-N+d+k-1;
			if(l<1 || i+l>30000) continue;
			dp[i+l][j+k-1]=max(dp[i+l][j+k-1],dp[i][j]);
		}
	}
	cout<<out<<endl;
}