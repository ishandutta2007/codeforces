#include<bits/stdc++.h>
using namespace std;
char s[500];
int r[500];
long long dp[100];
int che[111];
int main()
{
	dp[0] = 1;
	dp[1] = 1;
	for(int x = 2;x<=50;x++) dp[x] = dp[x-1] + dp[x-2];
	cin >> s;
	int x = strlen(s);
	int flag = 0;
	int ok = 0;
	if(s[0] == s[x-1])
	{
		flag = 1;
		ok = 0;
	}
	else
	{
		for(int i = 0;i<x-1;i++)
		{
			if(s[i]==s[i+1])
			{
				flag = 1;
				ok = i+1;
			}
		}
	}
	if(!flag)
	{
		x = x/2;
		printf("%lld\n",dp[x]+dp[x-2]);
		return 0;
	}
	for(int i = ok;i<x;i++) 
	{
		if(s[i]=='A') r[i-ok] = 0;
		else r[i-ok] = 1;
	}
	for(int i = 0;i<ok;i++)
	{
		if(s[i]=='A') r[x-ok+i] = 0;
		else r[x-ok+i] = 1;
	}
	//for(int i = 0;i<x;i++) printf("%d ",r[i]);
	//printf("\n");	
	for(int i = 0;i<x-1;i++) if(r[i]==1) if(r[i+1]==0) che[i+1] = 1;
	for(int i = 0;i<x-1;i++) if(r[i]==0) if(r[i+1]==1) che[i+1] = 2;
	//for(int i = 0;i<x;i++) printf("%d ",che[i]);
	//printf("\n");
	long long xx = 0;
	long long yy = 1;
	for(int i = 0;i<x;i++) if(che[i]==1)
	{
		if(i>=2&&che[i-2]) 
		{
			long long txx = xx + yy;
			long long tyy = xx;
			xx = txx;
			yy = tyy;
		}
		else
		{
			long long txx = xx + yy;
			long long tyy = xx + yy;
			xx = txx;
			yy = tyy;				
		}
		if(i+1==x-1) if(r[i+1]==1) yy = 0;
		if(i+2<x) if(r[i+1]==1) if(r[i+2]==1) yy = 0;
		if(i>=2) if(!che[i-2]) if(r[i-2]==0) yy = 0;
		//printf("%d %lld %lld\n",i,xx,yy);	
	}
	for(int i = 0;i<x;i++) if(che[i]==2) if(r[(i+1)%x]==1) if(r[(i-2+x)%x]==0) xx = yy = 0;
	printf("%lld\n",xx+yy);
	return 0;
}