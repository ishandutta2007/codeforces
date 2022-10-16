#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[233333];
int b[233333],c[233333],l,r,fl;
int main()
{
	scanf("%d",&n);
	int id=0;
	for(int i=1;i<=n+1;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		{
			++id;
			b[id]=c[id]=l;
			l=r=id;
		}
		else
		{
			++id;
			if(l!=r)
			{
				fl=1;
			}
			b[id]=c[id]=l;
			for(int j=2;j<=a[i];j++)b[id+j-1]=l,c[id+j-1]=r;
			l=id;
			r=id=id+a[i]-1;
			//cout<<id<<endl;
		}
	}
	if(fl)
	{
		printf("ambiguous\n");
		for(int i=1;i<=id;i++)printf("%d ",b[i]);printf("\n");
		for(int i=1;i<=id;i++)printf("%d ",c[i]);printf("\n");
	}
	else
	{
		printf("perfect\n");
//		for(int i=1;i<=id;i++)printf("%d ",b[i]);printf("\n");
	}
	return 0;
}