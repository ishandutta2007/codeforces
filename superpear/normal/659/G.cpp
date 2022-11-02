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

const int bigp=1000000007;
const int maxn=1000005;

int N;
int a[maxn],dp[maxn][3];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d",&a[i]);
	
	dp[0][0]=1;
	for (int i=0;i<N;i++)
	{
		dp[i+1][0]=dp[i][0];
		int sc;
		if (i!=N-1)
		{
			sc=max(0,a[i+1]-a[i+2]);
			dp[i+1][1]=(dp[i+1][1]+(a[i+1]-sc-1))%bigp;
			sc=max(0,max(a[i+1]-a[i],a[i+1]-a[i+2]));
			dp[i+1][1]=(dp[i+1][1]+(LL)dp[i][1]*(a[i+1]-sc-1))%bigp;
		}
		sc=max(0,a[i+1]-a[i]);
		dp[i+1][2]=(dp[i+1][2]+(LL)dp[i][1]*(a[i+1]-sc-1))%bigp;
	}
	
	int ans=0;
	for (int i=1;i<=N;i++) ans=(ans+dp[i][2])%bigp;
	for (int i=1;i<=N;i++) ans=(ans+a[i]-1)%bigp;
	printf("%d\n",ans);
	
	return 0;
}