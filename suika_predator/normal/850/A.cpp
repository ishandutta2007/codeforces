#include<iostream>
#include<cstdio>
#define M_PI 3.1415926535897932384626
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,tmp,ans;
struct point
{
	int a,b,c,d,e;
	point(){}
	point (int a0,int b0,int c0,int d0,int e0)
	{
		a=a0,b=b0,c=c0,d=d0,e=e0;
	}
	point operator-(const point &p)const
	{
		return point(a-p.a,b-p.b,c-p.c,d-p.d,e-p.e);
	}
	int operator*(const point &p)const
	{
		return a*p.a+b*p.b+c*p.c+d*p.d+e*p.e;
	}
}p[12];
int ok[12],cnt;
int main()
{
	scanf("%d",&n);
	if(n>11)return printf("0\n"),0;
	else if(n<3)
	{
		printf("%d\n",n);
		for(int i=1;i<=n;i++)printf("%d\n",i);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d%d",&p[i].a,&p[i].b,&p[i].c,&p[i].d,&p[i].e);
	}
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			for(int k=1;k<=n;k++)
			{
				if(i==k||j==k)continue;
				point x=p[k]-p[i],y=p[j]-p[i];
				if(acos(x*y/(sqrt(x*x)*sqrt(y*y)))<M_PI/2.0)
				{
					flag=0;
					break;
				}
			}
			if(!flag)break;
		}
		ok[i]=flag,cnt+=flag;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
	{
		if(ok[i])
		{
			printf("%d\n",i);
		}
	}
	return 0;
}