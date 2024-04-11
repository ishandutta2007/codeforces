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
const int maxn=1000005;

priority_queue<PII> F;
int N,M,xc,yc,S,T;
int dp[maxn],outp[maxn];
vector<int> f[maxn];

int main()
{
	scanf("%d %d",&N,&M);
	for (int i=1;i<=M;i++)
	{
		scanf("%d %d",&xc,&yc);
		f[yc].p_b(xc);
		++outp[xc];
	}
	memset(dp,127,sizeof(dp));
	scanf("%d %d",&S,&T);
	dp[T]=0;
	F.push(m_p(-dp[T],T));

	while (!F.empty())
	{
		PII cc=F.top();
		F.pop();
		if (dp[cc.w2]!=-cc.w1) continue;
		for (int i=0;i<f[cc.w2].size();i++)
		{
			int cs=f[cc.w2][i];
			--outp[cs];
			if (outp[cs]==0)
			{
				if (dp[cc.w2]<dp[cs])
				{
					dp[cs]=dp[cc.w2];
					F.push(m_p(-dp[cs],cs));
				}
			}
			else
			{
				if (dp[cc.w2]+1<dp[cs])
				{
					dp[cs]=dp[cc.w2]+1;
					F.push(m_p(-dp[cs],cs));
				}
			}
		}
	}

	if (dp[S]==biglongint) dp[S]=-1;
	cout<<dp[S]<<endl;

    return 0;
}