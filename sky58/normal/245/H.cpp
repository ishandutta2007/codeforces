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
bool kai[5010][5010];
int dp[5010][5010];
int main()
{
	int i,j,n,m,a,b;string s;
	cin>>s;n=s.size();
	memset(kai,false,sizeof(kai));
	rep(i,n) kai[i][i]=kai[i][i+1]=true;
	rep(i,n) rep(j,n-i+1){
		if(!kai[j][j+i]) continue;
		if(j>0 && i+j<n){
			if(s[j-1]==s[i+j]){
				kai[j-1][i+j+1]=true;
			}
		}
	}
	memset(dp,0,sizeof(dp));
	REP(i,1,n+1) rep(j,n-i+1){
		if(kai[j][i+j]) dp[j][i+j]++;
		dp[j][i+j]+=(dp[j+1][i+j]+dp[j][i+j-1]-dp[j+1][i+j-1]);
	}
	cin>>m;
	rep(i,m){
		scanf("%d %d",&a,&b);
		printf("%d\n",dp[a-1][b]);
	}
	return 0;
}