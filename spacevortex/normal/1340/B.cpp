#include<bits/stdc++.h>
using namespace std;
string s[10]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
const int N=2050;
int n,K;
int dp[N][N],blt[N];
int b[10];
string t[N];
int qry(string s)
{
	int i,ret=0;
	for(i=0;i<7;i++)
	{
		if(s[i]=='1') ret|=(1<<i);
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	int i,j,k,w,d,now;
	string u;
	cin>>n>>K;
	for(i=1;i<(1<<7);i++) blt[i]=blt[i>>1]+(i&1);
	for(i=1;i<=n;i++) cin>>t[i];
	reverse(t+1,t+n+1);
	dp[0][0]=1;
	for(i=0;i<10;i++) b[i]=qry(s[i]);
	//printf("U%d %d\n",qry(t[1]),b[8]);
	for(i=0;i<n;i++)
	{
		w=qry(t[i+1]);
		for(j=0;j<10;j++)
		{
			if((w&b[j])==w) 
			{
				d=blt[b[j]^w];
				for(k=0;k<=K-d;k++)
				{
					if(dp[i][k]) dp[i+1][k+d]=1;
				}
			}
		}
	}
	if(dp[n][K]==0)
	{
		puts("-1");
		return 0;
	}
	now=K;
	for(i=n;i>=1;i--)
	{
		w=qry(t[i]);
		for(j=9;j>=0;j--)
		{
			if((w&b[j])==w&&(d=blt[b[j]^w])<=now&&dp[i-1][now-d]==1) 
			{
				putchar(48+j);now-=d;break;
			}
		}
	}
	return 0;
}