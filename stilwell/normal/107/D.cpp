#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

long long n;
int N,m,i,j,k,Ans;
long long Power[505][505],tmp[505][505],ans[505][505];
char opt[1005];
int num[1005],a[1005];
bool app[1005],ok[1005],OK;

int hash()
{
	int h=0,i;
	for(i=1;i<=m;++i)h=h*num[i]+a[i];
	return h;
}
void Ihash(int x)
{
	int i;
	for(i=m;i>=1;--i)a[i]=x%num[i],x/=num[i];
}

int main()
{
	scanf("%I64d%d",&n,&m);
	if(m==0)
	{
		if(n==0)printf("1\n");
		else printf("0\n");
		return 0;
	}
	N=1;
	for(i=1;i<=m;++i)
	{
		opt[i]=getchar();
		while(opt[i]<'A'||opt[i]>'Z')opt[i]=getchar();
		scanf("%d",&num[i]);
		N*=num[i];
		app[opt[i]]=true;
	}
	for(i=0;i<N;++i)
	{
		Ihash(i);
		for(j='A';j<='Z';++j)
		if(app[j])
		{
			for(k=1;k<=m;++k)if(opt[k]==j)a[k]=(a[k]+1)%num[k];
			++Power[hash()][i];
			for(k=1;k<=m;++k)if(opt[k]==j)a[k]=(a[k]+num[k]-1)%num[k];
		}
	}
	for(i=0;i<N;++i)ans[i][i]=1;
	for(;n;n>>=1)
	{
		if(n&1)
		{
			memset(tmp,0,sizeof(tmp));
			for(i=0;i<N;++i)
			for(j=0;j<N;++j)
			for(k=0;k<N;++k)
			tmp[i][k]=(tmp[i][k]+Power[i][j]*ans[j][k])%12345;
			memcpy(ans,tmp,sizeof(tmp));
		}
		memset(tmp,0,sizeof(tmp));
		for(i=0;i<N;++i)
		for(j=0;j<N;++j)
		for(k=0;k<N;++k)
		tmp[i][k]=(tmp[i][k]+Power[i][j]*Power[j][k])%12345;
		memcpy(Power,tmp,sizeof(tmp));
	}
	for(i=0;i<N;++i)
	{
		for(j='A';j<='Z';++j)if(app[j])ok[j]=false;
		Ihash(i);
		for(j=1;j<=m;++j)if(a[j]==0)ok[opt[j]]=true;
		OK=true;
		for(j='A';j<='Z';++j)if(app[j])OK&=ok[j];
		if(OK)Ans=(Ans+ans[i][0])%12345;
	}
	printf("%d\n",Ans);
}