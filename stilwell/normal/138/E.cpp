#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,L,R,i,j,k;
int sum[27][100005],l[505],r[505],ll[505],rr[505];
int suit[100005],ans;
char s[100005],opt[505],ch;
long long Ans;

void Inc(int x)
{
	if(suit[x]==R)--ans;
	++suit[x];
	if(suit[x]==L)++ans;
}
void Dec(int x)
{
	if(suit[x]==L)--ans;
	--suit[x];
	if(suit[x]==R)++ans;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;++i)s[i]-='a';
	for(i=0;i<26;++i)
	for(j=1;j<=n;++j)
	sum[i][j]=sum[i][j-1]+(s[j]==i);
	scanf("%d%d%d",&m,&L,&R);
	for(i=1;i<=m;++i)
	{
		for(ch=getchar();ch<'a'||ch>'z';ch=getchar());
		opt[i]=ch-'a';
		scanf("%d%d",&l[i],&r[i]);
	}
	for(i=1;i<=m;++i)ll[i]=1,rr[i]=0;
	for(i=1;i<=n;++i)
	{
		if(suit[i]>=L&&suit[i]<=R)++ans;
		for(j=1;j<=m;++j)
		if(r[j])
		{
			ch=opt[j];
			if(ll[j]==0&&sum[ch][i]==l[j])
			{
				for(k=1;k<=i;++k)if(s[k]==ch)break;
				ll[j]=1;rr[j]=k;
				for(;k;--k)Inc(k);
			}
			else
			{
				for(;rr[j]<i&&sum[ch][i]-sum[ch][rr[j]]>=l[j];)Inc(++rr[j]);
				for(;sum[ch][i]-sum[ch][ll[j]-1]>r[j];)Dec(ll[j]++);
			}
		}
		else
		{
			ch=opt[j];
			if(s[i]==ch)
			{
				if(ll[j])for(k=ll[j];k<=rr[j];++k)Dec(k);
				ll[j]=rr[j]=0;
			}
			else
			{
				if(ll[j])Inc(++rr[j]);
				else Inc(ll[j]=rr[j]=i);
			}
		}
		Ans+=ans;
	}
	printf("%I64d\n",Ans);
}