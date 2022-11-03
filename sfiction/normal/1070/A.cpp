#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int dp[5010][501];

int main()
{
	int d,s;

	memset(dp, -1, sizeof(dp));
	scanf("%d%d",&d,&s);

	dp[0][0]=0;

	queue<pair<int, int> > q;
	q.push(make_pair(0,0));

	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k=0;k<10;k++)
		{
			int kk=(j*10+k)%d;
			if (i+k<=s && dp[i+k][kk]<0)
			{
				q.push(make_pair(i+k, kk));
				dp[i+k][kk] = k+j*10;
			}
		}
	}
	if (dp[s][0]>=0)
	{
		vector<int> ans;
		
		int dd = 0;
		int ss = s;
		while (ss>0)
		{
			int val = dp[ss][dd];
			int last_val = val%10;
			int last_mod = val/10;
			ans.push_back(last_val);
			ss-=last_val, dd = last_mod;
		}
		for (int i=ans.size()-1;i>=0;i--)
			printf("%d", ans[i]);
		puts("");
	}
	else
		puts("-1");
}