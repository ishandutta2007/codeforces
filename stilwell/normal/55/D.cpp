#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int T,i,j,k,n2,n3,n5,n7,t2,t3,t5,t7;
int aim[55][10];
long long l,r,num[25];
long long f[50][2530],g[50][2530],tmp[50][2530];

int cal(int n2,int n3,int n5,int n7){return n2*3*2*2+n3*2*2+n5*2+n7;}
int Cal(int x)
{
	int y=1;
	if(x%2)y*=7;x/=2;
	if(x%2)y*=5;x/=2;
	if(x%3==1)y*=3;
	if(x%3==2)y*=9;
	x/=3;
	if(x==1)y*=2;
	if(x==2)y*=4;
	if(x==3)y*=8;
	return y;
}

long long calc(long long lim)
{
	if(lim==0)return 1;
	int a[20],len=0,i,j,k;
	long long ans=0;
	for(long long t=lim;t;t/=10)a[++len]=t%10;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	f[0][0]=1;
	for(;len;--len)
	{
		memset(tmp,0,sizeof(tmp));
		for(i=0;i<=47;++i)
		for(j=0;j<2520;++j)
		if(g[i][j])
		for(k=0;k<=9;++k)
		tmp[aim[i][k]][(j+k*num[len])%2520]+=g[i][j];
		for(i=0;i<=47;++i)
		for(j=0;j<2520;++j)
		if(f[i][j])
		for(k=0;k<a[len];++k)
		tmp[aim[i][k]][(j+k*num[len])%2520]+=f[i][j];
		memcpy(g,tmp,sizeof(tmp));
		memset(tmp,0,sizeof(tmp));
		for(i=0;i<=47;++i)
		for(j=0;j<2520;++j)
		if(f[i][j])
		tmp[aim[i][a[len]]][(j+a[len]*num[len])%2520]+=f[i][j];
		memcpy(f,tmp,sizeof(tmp));
	}
	for(i=0;i<=47;++i)
	{
		k=Cal(i);
		for(j=0;j<2520;j+=k)ans+=f[i][j]+g[i][j];
	}
	return ans;
}

int main()
{
	for(n2=0;n2<=3;++n2)
	for(n3=0;n3<=2;++n3)
	for(n5=0;n5<=1;++n5)
	for(n7=0;n7<=1;++n7)
	{
		k=cal(n2,n3,n5,n7);
		for(i=0;i<=9;++i)
		{
			t2=t3=t5=t7=0;
			for(j=i;j&&j%2==0;j/=2)++t2;
			for(j=i;j&&j%3==0;j/=3)++t3;
			for(j=i;j&&j%5==0;j/=5)++t5;
			for(j=i;j&&j%7==0;j/=7)++t7;
			aim[k][i]=cal(max(n2,t2),max(n3,t3),max(n5,t5),max(n7,t7));
		}
	}
	num[1]=1;
	for(i=2;i<=20;++i)num[i]=num[i-1]*10%2520;
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",calc(r)-calc(l-1));
	}
}