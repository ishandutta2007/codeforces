#include<bits/stdc++.h>
using namespace std;
char a[223456];
int dp[123456][26];
int need[123456][26];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	cin >> a;
	for(int t = 0;t<26;t++) 
	{
		int pos = 0;
		for(int i = 0;i<k;i++) if(a[i] == 'a' + t) need[pos++][t] = i;
		if(!pos) 
		{
			for(int i = 0;i<k;i++) dp[i][t] = -1;
			continue;
		}
		//printf("pos = %d\n",pos);
		int tpos = 0;
		for(int i = 0;i<k;i++)
		{
			if(i<=need[tpos][t]) dp[i][t] = need[tpos][t];
			else if(tpos==pos-1) dp[i][t] = need[tpos][t];
			else if(need[tpos+1][t] - i < i - need[tpos][t]) dp[i][t] = need[++tpos][t]; 
			else dp[i][t] = need[tpos][t];
		}
		//for(int i = 0;i<k;i++) printf("%d %c dp %d = %d\n",t,t+'a',i,dp[i][t]);
	}
	
	for(int i = 0;i<n;i++)
	{
		cin >> a;
		int x = strlen(a);
		long long cnt = 0;
		for(int j = 0;j<x;j++)
		{
			int f = min(j,k-1);
			int z = a[j] - 'a';
			if(dp[f][z] == -1) cnt += x;
			else cnt += abs(j-dp[f][z]);
		}
		printf("%lld\n",cnt);
	}

	return 0;
}