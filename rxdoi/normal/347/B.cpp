#include<cstdio>
#include<iostream>
using namespace std;

const int Maxn=100000+19;
int A[Maxn],Dis[Maxn],n,Pre=0,Ans=0;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	for (int i=0;i<n;i++)
	{
		Dis[A[i]]=i;
		Pre+=(i==A[i]);
	}
	Ans=Pre;
	for (int i=0;i<n;i++)
	{
		if (i==A[i]) continue;
		Ans=max(Ans,Pre+1+(i==A[A[i]]));
	}
	printf("%d\n",Ans);
	return 0;
}