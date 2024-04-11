#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define INT long long
#define Inf (0x3f3f3f3f)
#define SZ(s) ((int)(s).size())
using namespace std;
//Coded by Charlieyan, all rights reserved.
//Orz DJQ in order to AC

int dp[5005][5005][2];
int sz[5005];
vector<int> son[5005];
int n,B;
int cost[5005],jcost[5005];

void dfs(int now){
	memset((int*)dp[now],0x3f,sizeof(dp[now]));
	dp[now][0][0]=0;
	dp[now][1][0]=cost[now];
	dp[now][1][1]=cost[now]-jcost[now];
	sz[now]=1;
	//cerr<<now<<endl;
	for(int i=0;i<SZ(son[now]);i++){
		dfs(son[now][i]);
		//cerr<<sz[now]<<' '<<now<<' '<<i<<endl;
		for(int j=sz[now];j>=0;j--){
			for(int k=0;k<=sz[son[now][i]];k++){
				dp[now][j+k][0]=min(dp[now][j+k][0],dp[now][j][0]+dp[son[now][i]][k][0]);
				dp[now][j+k][1]=min(dp[now][j+k][1],dp[now][j][1]+dp[son[now][i]][k][0]);
				dp[now][j+k][1]=min(dp[now][j+k][1],dp[now][j][1]+dp[son[now][i]][k][1]);
			}
		}
		sz[now]+=sz[son[now][i]];
	}
	//cerr<<now<<endl;
}

int main(){
	scanf("%d%d",&n,&B);
	for(int i=1;i<=n;i++){
		scanf("%d%d",cost+i,jcost+i);
		if(i!=1){
			int fa;
			scanf("%d",&fa);
			son[fa].push_back(i);
		}
	}
	dfs(1);
	for(int i=n;i>=0;i--){
		//cerr<<dp[1][i][0]<<' '<<dp[1][i][1]<<' '<<i<<endl;
		if(min(dp[1][i][0],dp[1][i][1])<=B){
			printf("%d\n",i);
			return 0;
		}
	}
}