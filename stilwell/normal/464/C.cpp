#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#define p 1000000007
using namespace std;

int n,i,j,k,l;
char s[100005],t[100005];
int d[100005],son[100005],next[100005],num[100005],tot;
long long def[15],len[15],tmp1,tmp2,ans;

int main()
{
	scanf("%s",s+1);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",t+1);
		l=strlen(t+1);
		d[i]=t[1]-'0';
		for(j=l;j>=4;--j)
		{
			num[++tot]=t[j]-'0';
			next[tot]=son[i];
			son[i]=tot;
		}
	}
	for(i=0;i<=9;++i)def[i]=i,len[i]=10;
	for(i=n;i>=1;--i)
	{
		tmp1=0;tmp2=1;
		for(j=son[i];j;j=next[j])
		{
			tmp1=(tmp1*len[num[j]]%p+def[num[j]])%p;
			tmp2=tmp2*len[num[j]]%p;
		}
		def[d[i]]=tmp1;
		len[d[i]]=tmp2;
	}
	l=strlen(s+1);
	ans=0;
	for(i=1;i<=l;++i)
	{
		k=s[i]-'0';
		ans=(ans*len[k]%p+def[k])%p;
	}
	printf("%I64d\n",ans);
}