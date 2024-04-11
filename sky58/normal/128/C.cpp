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
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int dp[1100][1100],dp2[1100][1100];
int mo=1000000007;
int main()
{
	int i,j,x,y,k;cin>>x>>y>>k;
	memset(dp,0,sizeof(dp));memset(dp2,0,sizeof(dp2));
	rep(i,1100) dp2[0][i]=i;
	REP(i,1,1100) REP(j,3,1100){
		dp[i][j]=(dp[i][j-1]+dp2[i-1][j-2])%mo;
		dp2[i][j]=(dp2[i][j-1]+dp[i][j])%mo;
	}
	cout<<((lint)dp[k][x]*dp[k][y])%mo<<endl;
	return 0;
}