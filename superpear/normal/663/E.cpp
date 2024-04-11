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

int dp[21][1100005];
int sc,N,M;
char st[100005];
int a[21][100005];

int main()
{
	scanf("%d %d",&N,&M);
	for (int i=1;i<=N;i++)
	{
		scanf("%s",st);
		for (int j=1;j<=M;j++)
			a[i][j]=st[j-1]-48;
	}
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=M;i++)
	{
		sc=0;
		for (int j=1;j<=N;j++)
			sc=sc*2+a[j][i];
		++dp[0][sc];
	}
	for (int i=1;i<=N;i++)
		for (int j=0;j<(1<<N);j++)
		{
			if (i==1) sc=0; else sc=(i-2-N)*dp[i-2][j];
			for (int p=0;p<N;p++)
				sc+=dp[i-1][j^(1<<p)];
			dp[i][j]=sc/i;
		}
	int ans=maxlongint;
	for (int i=0;i<(1<<N);i++)
	{
		sc=0;
		for (int j=0;j<=N;j++)
			sc+=min(j,N-j)*dp[j][i];
		ans=min(ans,sc);
	}
	printf("%d\n",ans);

	return 0;
}