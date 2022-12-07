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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool dp[105][53][105][2];
int main()
{
	string s;cin>>s;
	int i,j,k,l,n=s.size(),m,out=0;cin>>m;
	memset(dp,false,sizeof(dp));dp[0][0][0][0]=true;
	rep(i,n) rep(j,m+1) rep(k,102){
		if(dp[i][j][k][0]){
			if(s[i]=='F'){
				dp[i+1][j][k+1][0]=true;
				dp[i+1][j+1][k][1]=true;
			}
			else{
				dp[i+1][j+1][k+1][0]=true;
				dp[i+1][j][k][1]=true;
			}
		}
		if(dp[i][j][k][1]){
			if(s[i]=='F'){
				dp[i+1][j+1][k][0]=true;
				if(k==0) dp[i+1][j][1][0]=true;
				else dp[i+1][j][k-1][1]=true;
			}
			else{
				dp[i+1][j][k][0]=true;
				if(k==0) dp[i+1][j+1][1][0]=true;
				else dp[i+1][j+1][k-1][1]=true;
			}
		}
	}
	rep(j,102) rep(i,m+1){
		if(dp[n][i][j][0] || dp[n][i][j][1]){
			if((m-i)%2==0) out=max(out,j);
//			out=max(out,j);
		}
	}
	cout<<out<<endl;
	return 0;
}