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
lint dp[5010][5010];
lint x[5010];
int a[5010],b[5010],c[5010],d[5010];
int main()
{
	int n,s,g,cho=0,X;lint inf=1145141919810364364LL;
	scanf("%d %d %d",&n,&s,&g);s--;g--;
	rep(i,n){
		scanf("%d",&X);x[i]=X;
	}
	x[n]=x[n-1];
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);
	rep(i,n) scanf("%d",&c[i]);
	rep(i,n) scanf("%d",&d[i]);
	rep(i,5010) rep(j,5010) dp[i][j]=inf;dp[0][0]=0;
	rep(i,n){
		if(i==s){
			rep(j,n+5){
				if(dp[i][j]>=inf) continue;if(i>0 && j+j+cho<1) continue;if(j+cho<0) continue;
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+d[i]+(x[i+1]-x[i])*(j+j+cho+1));
				if(j>0) dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+c[i]+(x[i+1]-x[i])*(j-1+j-1+cho+1));
			}
			cho++;
		}
		else if(i==g){
			rep(j,n+5){
				if(dp[i][j]>=inf) continue;if(i>0 && j+j+cho<1) continue;if(j+cho<0) continue;
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+b[i]+(x[i+1]-x[i])*(j+1+j+1+cho-1));
				if(j+cho>0) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]+(x[i+1]-x[i])*(j+j+cho-1));
			}
			cho--;
		}
		else{
			rep(j,n+5){
				if(dp[i][j]>=inf) continue;if(i>0 && j+j+cho<1) continue;if(j+cho<0) continue;
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+b[i]+d[i]+(x[i+1]-x[i])*(j+1+j+1+cho));
				if(j+cho>0) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]+d[i]+(x[i+1]-x[i])*(j+j+cho));
				if(j>0) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+b[i]+c[i]+(x[i+1]-x[i])*(j+j+cho));
				if(j>0 && j+cho>0) dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+a[i]+c[i]+(x[i+1]-x[i])*(j-1+j-1+cho));
			}
		}
	}
	cout<<dp[n][0]<<endl;
}