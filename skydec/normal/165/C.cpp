#include<stdio.h>
#include<cstring>
#define MAXN 1100000
using namespace std;
char str[MAXN];int n,k;
int ct[MAXN];
int is[MAXN];
int sum[MAXN];
int zero[MAXN];
int main()
{
	scanf("%d",&k);
	scanf("%s",str+1);
	n=strlen(str+1);
	int tot=0;
	for(int i=1;i<=n;i++)
	if(str[i]=='1')
	{
		sum[i]=sum[i-1]+1;
		is[i]=++tot;
		ct[tot]=i;
		zero[i]=0;
	}
	else sum[i]=sum[i-1],zero[i]=zero[i-1]+1;
	long long ans=0;
	if(!k)
	{
		for(int i=1;i<=n;i++)
		if(str[i]=='0')ans+=zero[i]*1ll;
		printf("%I64d\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)if(sum[i]>=k)ans+=1ll*(zero[ct[sum[i]-k+1]-1]+1);
	printf("%I64d\n",ans);
	return 0;
}