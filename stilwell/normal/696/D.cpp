#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define inf 1000000000000000000ll
using namespace std;

int n,m,i,j,k,l;
int son[100005][26],a[100005],val[100005],Val[100005],fail[100005];
long long A[205][205],B[205][205],C[205][205];
char s[100005];
long long L,ans;

int get(int l,int r)
{
	int k=0;
	for(int i=l;i<=r;++i)
	if(!son[k][s[i]])return 0;
	else k=son[k][s[i]];
	return k;
}

void dfs(int x,int y)
{
	int i,j,k=0;
	if(x)
	{
		for(i=2;i<=y;++i)
		{
			k=get(i,y);
			if(k){fail[x]=k;break;}
		}
	}
	for(i=0;i<26;++i)if(son[x][i])s[y+1]=i,dfs(son[x][i],y+1);
}

int main()
{
	scanf("%d%I64d",&n,&L);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);l=strlen(s+1);
		for(j=1,k=0;j<=l;++j)
		{
			if(!son[k][s[j]-'a'])son[k][s[j]-'a']=++m;
			k=son[k][s[j]-'a'];
		}
		val[k]+=a[i];
	}
	dfs(0,0);
	for(i=0;i<=m;++i)
	for(j=0;j<=m;++j)
	C[i][j]=A[i][j]=-inf;
	for(i=0;i<=m;++i)
	for(j=i;j;j=fail[j])
	Val[i]+=val[j];
	for(i=0;i<=m;++i)
	for(i=0;i<=m;++i)
	for(j=0;j<26;++j)
	{
		for(k=i;k;k=fail[k])if(son[k][j])break;
		if(son[k][j])k=son[k][j];
		if(Val[k]>A[k][i])A[k][i]=Val[k];
	}
	for(i=0;i<=m;++i)C[i][i]=0;
	for(;L;L>>=1)
	{
		if(L&1)
		{
			for(i=0;i<=m;++i)
			for(j=0;j<=m;++j)
			B[i][j]=-inf;
			for(i=0;i<=m;++i)
			for(j=0;j<=m;++j)
			for(k=0;k<=m;++k)
			if(A[i][j]+C[j][k]>B[i][k])
			B[i][k]=A[i][j]+C[j][k];
			for(i=0;i<=m;++i)
			for(j=0;j<=m;++j)
			C[i][j]=B[i][j];
		}
		for(i=0;i<=m;++i)
		for(j=0;j<=m;++j)
		B[i][j]=-inf;
		for(i=0;i<=m;++i)
		for(j=0;j<=m;++j)
		for(k=0;k<=m;++k)
		if(A[i][j]+A[j][k]>B[i][k])
		B[i][k]=A[i][j]+A[j][k];
		for(i=0;i<=m;++i)
		for(j=0;j<=m;++j)
		A[i][j]=B[i][j];
	}
	for(i=0;i<=m;++i)if(C[i][0]>ans)ans=C[i][0];
	printf("%I64d\n",ans);
}