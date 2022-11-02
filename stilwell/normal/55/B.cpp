#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long a[10],ans;
char ch,opt[10];

void dfs(int x)
{
	if(x==1)
	{
		if(a[1]<ans)ans=a[1];
		return;
	}
	long long b[5];
	b[1]=a[1];b[2]=a[2];b[3]=a[3];b[4]=a[4];
	for(int i=1;i<=x;++i)
	for(int j=i+1;j<=x;++j)
	{
		for(int k=1;k<i;++k)a[k]=b[k];
		for(int k=i+1;k<j;++k)a[k-1]=b[k];
		for(int k=j+1;k<=x;++k)a[k-2]=b[k];
		if(opt[x]=='+')a[x-1]=b[i]+b[j];else a[x-1]=b[i]*b[j];
		dfs(x-1);
	}
}

int main()
{
	scanf("%I64d%I64d%I64d%I64d",&a[1],&a[2],&a[3],&a[4]);
	ch=getchar();while(ch!='+'&&ch!='*')ch=getchar();opt[4]=ch;
	ch=getchar();while(ch!='+'&&ch!='*')ch=getchar();opt[3]=ch;
	ch=getchar();while(ch!='+'&&ch!='*')ch=getchar();opt[2]=ch;
	ans=1000000000000ll;
	dfs(4);
	printf("%I64d\n",ans);
}