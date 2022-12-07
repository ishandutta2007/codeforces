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
int dp[5100][5100];
char s[5100];
int main()
{
	int n,m,out=0;
	memset(dp,0,sizeof(dp));
	scanf("%d %d\n",&n,&m);
	rep(i,n){
		gets(s);
		//rep(j,m) printf("%c\n",s[j]);
		int now=-1;
		rep(j,m){
			if(s[j]=='0'){
				if(now>=0){
					dp[now][j]++;now=-1;
				}
			}
			else{
				if(now<0) now=j;
			}
		}
		if(now>=0) dp[now][m]++;
	}
	rep(i,m) for(int j=m;j>i;j--){
		if(j<m) dp[i][j]+=dp[i][j+1];
		if(i>0) dp[i][j]+=dp[i-1][j];
		if(j<m && i>0) dp[i][j]-=dp[i-1][j+1];
	}
	rep(i,m) REP(j,i+1,m+1) out=max(out,(j-i)*dp[i][j]);
	cout<<out<<endl;
}