#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[101][2601];

#define MOD 1000000007

int main()
{
	//freopen("in1.in","r",stdin);
	dp[0][0] = 1;
	for(int i=1;i<=100;i++)
		for(int s=1;s<=i*26;s++)
			for(int k=1;k<=min(26,s);k++)
				(dp[i][s]+=dp[i-1][s-k])%=MOD;
	int t;
	char s[102];
	for(scanf("%d",&t);t--;)
	{
		scanf(" %s",s);
		int sum = 0, len = 0;
		for(char *c = s;*c;c++) sum+=*c-'a'+1, len++;
		printf("%d\n",(dp[len][sum]-1+MOD)%MOD);
	}
	return 0;
}