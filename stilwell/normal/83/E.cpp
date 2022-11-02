#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 1000000000
using namespace std;

int n,m,i,j,k,len,l,r,add,Min;
int son[4000005][2],fa[4000005],fail[4000005],q[4000005];
int id[4000005],f[4000005],t[4000005];
char s[105],ch[4000005];

int main()
{
	scanf("%d",&n);
	m=id[0]=1;
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		len=strlen(s+1);
		for(j=1;j<=len;++j)s[j]-='0';
		for(k=j=1;j<=len;++j)
		{
			if(!son[k][s[j]])son[k][s[j]]=++m,fa[m]=k,ch[m]=s[j];
			k=son[k][s[j]];
		}
		id[i]=k;
	}
	for(q[l=r=1]=1;l<=r;++l)
	{
		k=q[l];
		if(son[k][0])q[++r]=son[k][0];
		if(son[k][1])q[++r]=son[k][1];
	}
	for(i=2;i<=m;++i)
	{
		k=q[i];
		for(j=fail[fa[k]];j;j=fail[j])if(son[j][ch[k]])break;
		if(j)fail[k]=son[j][ch[k]];else fail[k]=1;
	}
	for(i=2;i<=m;++i)f[i]=inf;
	for(i=1;i<=n;++i)
	{
		for(j=id[i],k=len+1;j;j=fa[j],--k)t[j]=k;
		for(j=id[i-1];j;j=fail[j])if(t[j])break;
		l=len-t[j]+1;Min=inf;
		for(j=id[i];j;j=fa[j])t[j]=0;
		for(j=id[i],k=add;j;j=fa[j],++k)if(f[j]+k<Min)Min=f[j]+k;
		add+=l;
		for(j=id[i-1];j;j=fail[j])if(Min-add<f[j])f[j]=Min-add;
	}
	printf("%d\n",f[1]+add);
}