#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 1048576

using namespace std;
typedef long long int ll;

int dig[maxn],n,sum[maxn],m,l,t,w,c[maxn],zh[50][50];
ll dp[maxn];
char s[51][21];
double ans[maxn],tmp,ave,a[maxn],u;
bool sam[51][21];

int lowbit(int x)
{
	return (x&(-x));
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	    scanf("%s",s[i]);
	if (n==1) {
		printf("0.000000000\n");
		return 0;
	}
	l=strlen(s[0]);
	m=1<<l;
	for (int i=0;i<=l;i++)
	    zh[i][0]=1;
	for (int i=1;i<=l;i++)
	    for (int j=1;j<=i;j++)
	        zh[i][j]=zh[i-1][j-1]+zh[i-1][j];
	for (int i=0;i<=l;i++)
	    c[i]=zh[l][i];
	for (int i=0;i<m;i++)
	{
		w=i;
		dig[i]=0;
		for (int j=0;j<l;j++)
		{
			dig[i]+=w%2;
			w/=2;
		}
	}
	for (int i=0;i<n;i++)
	{
		ans[i]=0.0;a[0]=0.0;
		for (int j=0;j<n;j++)
		    for (int k=0;k<l;k++)
		        sam[j][k]=(s[i][k]==s[j][k]&&i!=j);
		memset(dp,0,sizeof(dp));
		dp[0]=((ll)1<<n)-1;
		for (int j=0;j<l;j++)
		{
			ll tmp=0;
			for (int k=0;k<n;k++)
			    if (sam[k][j]) tmp+=(ll)1<<k;
			dp[1<<j]=tmp;
		}
		for (int j=1;j<m;j++)
		    dp[j]=dp[j-lowbit(j)]&dp[lowbit(j)];
		//for (int j=0;j<m;j++) printf("%I64d\n",dp[j]); printf("------------\n");
		memset(sum,0,sizeof(sum));
		u=1.0;
		for (int j=1;j<m;j++) if (dp[j]==0) sum[dig[j]]++;
		//for (int j=1;j<=l;j++) printf("%d\n",sum[j]);
		for (int j=1;j<=l;j++)
		    a[j]=double(sum[j])/c[j];
		//for (int j=1;j<=l;j++) printf("%f\n",a[j]);
		for (int j=1;j<=l;j++)
		    ans[i]+=(a[j]-a[j-1])*j;
	}
	ave=0.0;
	for (int i=0;i<n;i++) ave=ave+ans[i];
	printf("%.9f\n",ave/n);
	return 0;
}