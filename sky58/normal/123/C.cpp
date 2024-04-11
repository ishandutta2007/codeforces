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
lint inf=1100000000000000000LL;
lint dp[210][210];
string s="(";
int ma[210][210];
int n,m;
lint cal(void){
	int i,j;
	rep(i,210) rep(j,210) dp[i][j]=0;dp[0][0]=1;
	rep(i,n+m-1) rep(j,i+1){
		if(s[i]!='(' && j>0) dp[i+1][j-1]=min(inf,dp[i+1][j-1]+dp[i][j]);
		if(s[i]!=')') dp[i+1][j+1]=min(inf,dp[i+1][j+1]+dp[i][j]);
	}
	return dp[n+m-1][0];
}
int main()
{
	int i,j;lint k;
	cin>>n>>m>>k;
	char out[210][210];vector <pint> pri;
	if((n+m)%2<1) return 0;
	rep(i,n) rep(j,m) scanf("%d",&ma[i][j]);
	REP(i,1,n+m-2){
		int mi=11000;
		rep(j,n){
			if(i-j<0 || i-j>=m) continue;
			mi=min(mi,(ma[j][i-j]));
		}
		pri.pb(mp(mi,i));
	}
	sort(All(pri));
	rep(i,n+m-3) s+=" ";s+=")";
	if(cal()<k) return 0;
	rep(i,n+m-3){
		int t=pri[i].se;s[t]='(';lint ka=cal();
		if(ka<k){k-=ka;s[t]=')';}
	}
	rep(i,m+n-1) rep(j,n){
		if(i-j<0 || i-j>=m) continue;out[j][i-j]=s[i];
	}
	rep(i,n){
		rep(j,m) cout<<out[i][j];
		cout<<endl;
	}
	return 0;
}