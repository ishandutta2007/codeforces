#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int dp[5005];
char s[5005];
int n,a,b;
int dp2[5005][5005];

int main(){
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dp2[j][i]=(s[j]==s[i]?dp2[j-1][i-1]+1:0);
		}
	}
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=min(dp[i],dp[i-1]+a);
		for(int j=1;j<i;j++){
			dp[i]=min(dp[i],dp[max(j,i-dp2[j][i])]+b);
		}
	}
	printf("%d\n",dp[n]);
	return 0;
}