#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int ask(int i,int j,int k)
{
	printf("? %d %d %d\n",i,j,k);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int n,a[N],b[N],mx,cm;
void sol()
{
	scanf("%d",&n);
	for(int i=3;i<=n;i++)
		a[i]=ask(1,2,i);
	if(a[3]>a[4])
		mx=3,cm=4;
	else
		mx=4,cm=3;
	int z=1;
	for(int i=3;i<=n;i++)
		if(a[i]!=a[3])
			z=0;
	if(z)
	{
		for(int i=4;i<=n;i++)
		{
			if(ask(i,2,3)>a[3])
			{
				printf("! %d %d\n",3,i);
				fflush(stdout);
				return;
			}
		}
		printf("! 1 2\n");
		fflush(stdout);
		return;
	}
	for(int i=5;i<=n;i++)
	{
		if(a[i]>a[mx])
			cm=mx,mx=i;
		else if(a[i]>a[cm])
			cm=i;
	}
	for(int i=1;i<=n;i++)
		if(i!=mx&&i!=cm)
			b[i]=ask(mx,cm,i);
	int v=-1,f=1;
	for(int i=1;i<=n;i++)
	{
		if(i==mx||i==cm)
			continue;
		if(v==-1)
			v=b[i];
		else if(v!=b[i])
			f=0;	
	}
	if(f)
	{
		printf("! %d %d\n",mx,cm);
		fflush(stdout);
		return;
	}
	int p=-1;
	for(int i=1;i<=n;i++)
	{
		if(i==mx||i==cm)
			continue;
		if(p==-1)
			p=i;
		else if(b[i]>b[p])
			p=i;
	}
	printf("! %d %d\n",mx,p);
	fflush(stdout);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}