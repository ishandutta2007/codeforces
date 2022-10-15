#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[5];
int dp[MAXN][5][(1<<12)];
string str[4];
void upd(int &a,int b) {a=min(a,b);}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<4;i++) scanf("%d",&a[i]);
	for(int i=0;i<4;i++) cin>>str[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<5;j++)
			for(int mask=0;mask<(1<<12);mask++)
				dp[i][j][mask]=INF;
	dp[0][0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
			for(int mask=0;mask<(1<<12);mask++)
			{
				if(dp[i][j][mask]==INF) continue;
				if((mask&(1<<j))||(str[j][i]=='.')) upd(dp[i][j+1][mask|(1<<j)],dp[i][j][mask]);
				for(int num=1;num<=4;num++)
				{
					int tmask=mask,pos=j;
					for(int x=0;x<num;x++)
						for(int y=0;y<num;y++)
							if(i+x<n&&j+y<4) tmask|=(1<<(pos+y+x*4));
					//printf("num=%d tmask=%d\n",num,tmask);
					if(num<4) upd(dp[i][j+1][tmask],dp[i][j][mask]+a[num-1]);
					else upd(dp[i+1][0][tmask>>4],dp[i][j][mask]+a[num-1]);
				}
			}
		for(int mask=0;mask<(1<<12);mask++)
			if((mask&15)==15) upd(dp[i+1][0][mask>>4],dp[i][4][mask]);
	}
	printf("%d\n",dp[n][0][0]);
	return 0;
}