#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 5005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[MAXN],last[MAXN][MAXN];
int N,K,V;
bool dp[MAXN][MAXN],flag[MAXN];
int main()
{
	scanf("%d%d%d",&N,&K,&V);
	int s=0;
	int t=0;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if(s<V)
	{
		puts("NO");
		return 0;
	}
	memset(last,-1,sizeof(last));
	memset(dp,false,sizeof(dp));
	memset(flag,false,sizeof(flag));
	dp[0][0]=true;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<K;j++)
			if(dp[i-1][j])
			{
				dp[i][j]=true;
				last[i][j]=0;
				dp[i][(j+a[i])%K]=true;
				last[i][(j+a[i])%K]=1;
			}
	}
	if(!dp[N][V%K])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int now=V%K;
	for(int i=N;i>=1;i--)
	{
		if(last[i][now]==1)
		{
			flag[i]=true;
			now=((now-a[i])%K+K)%K;
		}
	}
	int id1=-1,id2=-1,sum1=0,sum2=0;
	for(int i=1;i<=N;i++)
	{
		if(flag[i]) {id1=i; sum1+=a[i];}
		else {id2=i; sum2+=a[i];}
	}
	if(id1!=-1)
		for(int i=1;i<=N;i++)
			if(flag[i]&&i!=id1&&a[i])
				printf("%d %d %d\n",(a[i]+K-1)/K,i,id1);
	if(id2!=-1)
		for(int i=1;i<=N;i++)
			if(!flag[i]&&i!=id2&&a[i])
				printf("%d %d %d\n",(a[i]+K-1)/K,i,id2);
	if(id2==-1)
		for(int i=1;i<=N;i++)
			if(i!=id1) id2=i; 
	if(id1==-1)
		for(int i=1;i<=N;i++)
			if(i!=id2) id1=i; 
	if(sum1>V) printf("%d %d %d\n",(sum1-V)/K,id1,id2);
	if(sum1<V) printf("%d %d %d\n",(V-sum1)/K,id2,id1);
	return 0;
}