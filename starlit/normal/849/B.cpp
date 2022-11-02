#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define N 1005
using namespace std;
int n,a[N],tp;
bool f[N],flag;
int mx,my,now,lx,ly;
int gcd(int x,int y)
{
	if(x<y)swap(x,y);
	return y?gcd(y,x%y):x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	for(int i=2;i<=n;i++)
	{
		memset(f,0,sizeof f);
		mx=i-1,my=a[i]-a[1];flag=0;
		tp=gcd(mx,abs(my));
		mx/=tp,my/=tp;
		tp=0,now=a[1];
		for(int j=1;j<=n;j+=mx)
		{
			if(now==a[j])f[j]=1,tp++;
			now+=my;
			if(now>1e9||now<-1e9)break;
		}
		if(tp==n)
		{puts("No");return 0;}
		else if(tp==n-1)
		{puts("Yes");return 0;}
		for(tp=2;tp<=n;tp++)
		if(!f[tp])break;
		lx=mx,ly=my;
		for(int j=tp+1;j<=n;j++)
		if(!f[j])
		{
			mx=j-tp,my=a[j]-a[tp];
			now=gcd(mx,abs(my));
			mx/=now,my/=now;
			break;
		}
		if(mx!=lx||my!=ly)continue;
		now=a[tp];
		for(int j=tp;j<=n;j+=mx)
		{
			if(now==a[j])f[j]=1;
			now+=my;
			if(now>1e9||now<-1e9)break;
		}
		now=a[tp];
		for(int j=tp;j;j-=mx)
		{
			if(now==a[j])f[j]=1;
			now-=my;
			if(now>1e9||now<-1e9)break;
		}
		for(int i=2;i<=n&&!flag;i++)
		if(!f[i])flag=1;
		if(!flag){puts("Yes");return 0;}
	}
	my=a[3]-a[2];
	if(a[1]==a[2]-my)
	{puts("No");return 0;}
	a[3]+=my;
	for(int i=4;i<=n;i++)
	if(a[i]!=a[3])
	{puts("No");return 0;}
	else
	{
		a[3]+=my;
		if((a[3]>1e9||a[3]<-1e9)&&i<n)
		{puts("No");return 0;}
	}
	puts("Yes");
}
/*
6
1 2 1 3 4 5
*/