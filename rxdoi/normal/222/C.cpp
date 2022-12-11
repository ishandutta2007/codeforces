#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int Maxn=(1e5+19)*24,PP=1e7+19;
int cntA[PP],cntB[PP],p[PP],A[Maxn],B[Maxn];
int n,m,x,ca,cb,cca,ccb;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=2;i<=1e7;i++)
		if (!p[i])
			for (int j=i+i;j<=1e7;j+=i) p[j]=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);A[i]=x;
		for (int j=2;j<=sqrt(x)&&p[x];j++) while (x%j==0) cntA[j]++,x/=j;
		if (x!=1) cntA[x]++;
	}	
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&x);B[i]=x;
		for (int j=2;j<=sqrt(x)&&p[x];j++) while (x%j==0) cntB[j]++,x/=j;
		if (x!=1) cntB[x]++;
	}
	for (int i=1;i<=PP;i++)
	{
		int x=min(cntA[i],cntB[i]);
		cntA[i]-=x;cntB[i]-=x;
	}
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;i++)
	{
		int x=A[i],t=1;
		for (int j=2;j<=sqrt(x)&&p[x];j++) while (x%j==0) {x/=j;if (cntA[j]) cntA[j]--,t*=j;}
		if (cntA[x]) cntA[x]--,t*=x;
		printf("%d ",t);
	}
	puts("");
	for (int i=1;i<=m;i++)
	{
		int x=B[i],t=1;
		for (int j=2;j<=sqrt(x)&&p[x];j++) while (x%j==0) {x/=j;if (cntB[j]) cntB[j]--,t*=j;}
		if (cntB[x]) cntB[x]--,t*=x;
		printf("%d ",t);
	}
	puts("");
}