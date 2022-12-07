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
string ma[3010];
lint dp[3010][3010][2];
int main()
{
	int n,m;cin>>n>>m;lint out=0,mo=1000000007;
	rep(i,n) cin>>ma[i];
	dp[0][1][0]=dp[1][0][1]=1;
	rep(i,n) rep(j,m){
		if(ma[i][j]=='#') dp[i][j][0]=dp[i][j][1]=0;
		rep(k,2){
			dp[i][j][k]%=mo;dp[i+1][j][k]+=dp[i][j][k];dp[i][j+1][k]+=dp[i][j][k];
		}
	}
	out+=(dp[n-2][m-1][0]*dp[n-1][m-2][1])%mo;
	out-=(dp[n-1][m-2][0]*dp[n-2][m-1][1])%mo;
	cout<<(out+mo)%mo<<endl;
	return 0;
}