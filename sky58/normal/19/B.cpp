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
lint dp[2100][4100];
lint inf=100000000000000000LL;
lint lmax(lint a,lint b){
	if(a<b) return b;return a;
}
lint lmin(lint a,lint b){
	if(a>b) return b;return a;
}
int main()
{
	int i,j,n,t,c;cin>>n;lint out=inf;
	for(i=0;i<2100;i++) for(j=0;j<4100;j++) dp[i][j]=inf;
	dp[0][2050]=0;
	for(i=0;i<n;i++){
		cin>>t>>c;
		for(j=0;j<4100;j++){
			if(dp[i][j]>=inf) continue;
			dp[i+1][min(4070,j+t)]=lmin(dp[i][j]+c,dp[i+1][min(4070,j+t)]);
			dp[i+1][j-1]=lmin(dp[i][j],dp[i+1][j-1]);
		}
	}
	for(i=2050;i<4100;i++) out=lmin(out,dp[n][i]);
	cout<<out<<endl;
	return 0;
}