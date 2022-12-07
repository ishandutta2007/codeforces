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
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dp[4100][4100];int ti[8100],di[8100];
int main()
{
	int i,j,k,n,out=0;cin>>n>>k;
	rep(i,8050) ti[i]=di[i]=86401;
	rep(i,n) scanf("%d %d",&ti[i],&di[i]);
	rep(i,4050) rep(j,4050) dp[i][j]=100000000;dp[0][0]=1;
	rep(i,n+1) rep(j,n+1){
		dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
		dp[i+1][j+1]=min(dp[i+1][j+1],max(dp[i][j],ti[i])+di[i]);
		out=max(out,ti[j+k]-dp[i][j]);
	}
	cout<<out<<endl;return 0;
}