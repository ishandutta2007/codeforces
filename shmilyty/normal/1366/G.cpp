#include<bits/stdc++.h>
using namespace std;
int nxt[10001],dp[10001][10001];
string a,b;
int main()
{
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
	{
		nxt[i]=-1;
		int bal=0;
		if(a[i]!='.')
			for(int l=i;l<a.size();l++)
			{
				if(a[l]=='.')
					bal--;
				else
					bal++;
				if(!bal)
				{
					nxt[i]=l;
					break;
				}
			}
	}
	for(int i=0;i<=a.size();i++)
		for(int l=0;l<=b.size();l++)
			dp[i][l]=1e9;
	dp[0][0]=0;
	for(int i=0;i<a.size();i++)
		for(int l=0;l<=b.size();l++)
		{
			dp[i+1][l]=min(dp[i+1][l],dp[i][l]+1);
			if(l<b.size()&&a[i]==b[l])
				dp[i+1][l+1]=min(dp[i+1][l+1],dp[i][l]);
			if(a[i]!='.'&&nxt[i]!=-1)
				dp[nxt[i]+1][l]=min(dp[nxt[i]+1][l],dp[i][l]);
		}		
	cout<<dp[a.size()][b.size()];
}