#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,x;
int p[100005],prime[100005],tot;
int num[100005];
char opt;
bool act[100005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=2;i<=n;++i)
	{
		if(!p[i])p[i]=prime[++tot]=i;
		for(j=1;j<=tot&&prime[j]<=n/i&&prime[j]<=p[i];++j)p[i*prime[j]]=prime[j];
	}
	for(;m;--m)
	{
		opt=getchar();
		while(opt!='+'&&opt!='-')opt=getchar();
		scanf("%d",&x);
		if(opt=='+')
		{
			if(act[x])printf("Already on\n");
			else
			{
				for(j=x;j!=1;j/=p[j])
				if(act[num[p[j]]]){printf("Conflict with %d\n",num[p[j]]);break;}
				if(j!=1)continue;
				for(j=x;j!=1;j/=p[j])
				num[p[j]]=x;
				act[x]=true;
				printf("Success\n");
			}
		}
		else
		{
			if(!act[x])printf("Already off\n");
			else printf("Success\n");
			act[x]=false;
		}
	}
}