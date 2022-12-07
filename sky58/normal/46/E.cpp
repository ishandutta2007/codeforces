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
lint dp[1600][1600],ka[1600][1600];
int main()
{
	int i,j,k,n,m,f;lint out=-1000000000000000LL;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		lint t=0;
		for(j=0;j<m;j++){scanf("%d",&f);t+=f;ka[i][j]=t;}
	}
//	for(i=0;i<n;i++) for(j=0;j<m;j++) cout<<ka[i][j]<<endl;
	for(i=0;i<1600;i++) for(j=0;j<1600;j++) dp[i][j]=out;for(i=0;i<1600;i++) dp[0][i]=0;
	for(i=0;i<n;i++){
		if(i%2==0){
			for(j=1;j<m;j++) dp[i+1][j]=ka[i][j]+dp[i][j-1];
			for(j=m-1;j>0;j--) dp[i+1][j]=max(dp[i+1][j+1],dp[i+1][j]);
		}
		else{
			for(j=0;j<m-1;j++) dp[i+1][j]=ka[i][j]+dp[i][j+1];
			for(j=1;j<m-1;j++) dp[i+1][j]=max(dp[i+1][j],dp[i+1][j-1]);
		}
	}
	for(i=0;i<m;i++) out=max(out,dp[n][i]);cout<<out<<endl;
	return 0;
}