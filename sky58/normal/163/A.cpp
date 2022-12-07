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
string s,t;
int dp[5050][5050];
/*
int rec(int a,int b,int c){
	if(dp[a][b][c]>=0) return dp[a][b][c];
	if(a>=s.size() || b>=t.size()) return 0;
	if(s[a]==t[b]) ret+=1+rec(a+1,b+1,1);
*/	
int main()
{
	int out=0,i,j,mo=1000000007;
	cin>>s;cin>>t;
	rep(i,5050) rep(j,5050) dp[i][j]=0;
	for(i=s.size()-1;i>=0;i--) for(j=t.size()-1;j>=0;j--){
		if(s[i]==t[j]) dp[i][j]+=1+dp[i+1][j+1];
		dp[i][j]%=mo;dp[i][j]+=dp[i][j+1];dp[i][j]%=mo;
//		cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	}
	rep(i,s.size()) out=(out+dp[i][0])%mo;
	cout<<out<<endl;
	return 0;
}