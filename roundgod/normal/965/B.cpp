#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
string str[MAXN];
int lcnt[MAXN][MAXN],rcnt[MAXN][MAXN],ucnt[MAXN][MAXN],dcnt[MAXN][MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) cin>>str[i];
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			lcnt[i][j]=cnt;
			if(str[i][j]=='.') cnt++; else cnt=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=n-1;j>=0;j--)
		{
			rcnt[i][j]=cnt;
			if(str[i][j]=='.') cnt++; else cnt=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			ucnt[j][i]=cnt;
			if(str[j][i]=='.') cnt++; else cnt=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(int j=n-1;j>=0;j--)
		{
			dcnt[j][i]=cnt;
			if(str[j][i]=='.') cnt++; else cnt=0;
		}
	}
	int ans=0,tx=0,ty=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int res=0;
			if(str[i][j]=='#') continue;
			if(lcnt[i][j]+rcnt[i][j]+1>=k) res+=min(k,min(lcnt[i][j]+rcnt[i][j]+2-k,min(1+lcnt[i][j],1+rcnt[i][j])));
			if(ucnt[i][j]+dcnt[i][j]+1>=k) res+=min(k,min(ucnt[i][j]+dcnt[i][j]+2-k,min(1+ucnt[i][j],1+dcnt[i][j])));
			if(res>ans)
			{
				ans=res;
				tx=i;ty=j;
			}
		}
	printf("%d %d\n",tx+1,ty+1);
	return 0;
}