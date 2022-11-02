#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

int N,dp[100005][2][3],a[100005];
char st[100005];

int main()
{
	scanf("%d",&N);
	scanf("%s",st);
	for (int i=1;i<=N;i++) a[i]=st[i-1]-48;
	dp[1][a[1]][0]=1;
	dp[1][a[1]][1]=1;
	for (int i=1;i<N;i++)
	{
		if (a[i+1]==1) dp[i+1][1][0]=max(dp[i+1][1][0],dp[i][0][0]+1); else
		dp[i+1][0][0]=max(dp[i+1][0][0],dp[i][0][0]);
		if (a[i+1]==1) dp[i+1][1][1]=max(dp[i+1][1][1],dp[i][1][0]+1); else
		dp[i+1][0][1]=max(dp[i+1][0][1],dp[i][1][0]);
		if (a[i+1]==1) dp[i+1][1][1]=max(dp[i+1][1][1],dp[i][0][1]+1); else
		dp[i+1][0][1]=max(dp[i+1][0][1],dp[i][0][1]);
		if (a[i+1]==1) dp[i+1][1][2]=max(dp[i+1][1][2],dp[i][1][1]+1); else
		dp[i+1][0][2]=max(dp[i+1][0][2],dp[i][1][1]);
		if (a[i+1]==1) dp[i+1][1][2]=max(dp[i+1][1][2],dp[i][0][2]+1); else
		dp[i+1][0][2]=max(dp[i+1][0][2],dp[i][0][2]);

		if (a[i+1]==0) dp[i+1][0][0]=max(dp[i+1][0][0],dp[i][1][0]+1); else
		dp[i+1][1][0]=max(dp[i+1][1][0],dp[i][1][0]);
		if (a[i+1]==0) dp[i+1][0][1]=max(dp[i+1][0][1],dp[i][0][0]+1); else
		dp[i+1][1][1]=max(dp[i+1][1][1],dp[i][0][0]);
		if (a[i+1]==0) dp[i+1][0][1]=max(dp[i+1][0][1],dp[i][1][1]+1); else
		dp[i+1][1][1]=max(dp[i+1][1][1],dp[i][1][1]);
		if (a[i+1]==0) dp[i+1][0][2]=max(dp[i+1][0][2],dp[i][0][1]+1); else
		dp[i+1][1][2]=max(dp[i+1][1][2],dp[i][0][1]);
		if (a[i+1]==0) dp[i+1][0][2]=max(dp[i+1][0][2],dp[i][1][2]+1); else
		dp[i+1][1][2]=max(dp[i+1][1][2],dp[i][1][2]);

		//cout<<i<<" "<<dp[i][a[i]][0]<<" "<<dp[i][a[i]][1]<<" "<<dp[i][a[i]][2]<<endl;
	}

	cout<<max(dp[N][a[N]][2],dp[N][a[N]][1])<<endl;

    return 0;
}