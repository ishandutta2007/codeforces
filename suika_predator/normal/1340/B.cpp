#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,k;
char digit[11][11]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
char a[2333][11];
int add[2333][11];
int dp[2333][2333];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		for(int d=0;d<=9;d++)
		{
			int cnt=0;
			for(int j=0;j<7;j++)
			{
				if(digit[d][j]=='1'&&a[i][j]=='0')cnt++;
				else if(digit[d][j]=='0'&&a[i][j]=='1')
				{
					cnt=inf;
					break;
				}
			}
			add[i][d]=cnt;
//			cerr<<i<<' '<<a[i]
		}
	}
	dp[n][k]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=k;j++)
		{
			if(!dp[i][j])continue;
			for(int d=0;d<=9;d++)
			{
				if(add[i][d]<=j)
					dp[i-1][j-add[i][d]]=1;
			}
		}
	}
	if(dp[0][0]==0)
	{
		cout<<-1<<endl;
	}
	else
	{
		int cur=0;
		for(int i=1;i<=n;i++)
		{
			for(int d=9;d>=0;d--)
			{
				if(add[i][d]!=inf&&dp[i][cur+add[i][d]])
				{
					cout<<d;
					cur+=add[i][d];
					break;
				}
			}
		}
	}
	return 0;
}