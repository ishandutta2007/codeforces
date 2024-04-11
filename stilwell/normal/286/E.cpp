#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#define pi 3.141592653589793238462643383
using namespace std;

struct complex
{
	double num,inum;
	complex(double A=0.0,double B=0.0){num=A,inum=B;}
}a[3000005],w[2][3000005];
int N,m,n,na,nb,rev[3000005],i,j,k,ans;

complex operator +(const complex &A,const complex &B){return complex(A.num+B.num,A.inum+B.inum);}
complex operator -(const complex &A,const complex &B){return complex(A.num-B.num,A.inum-B.inum);}
complex operator *(const complex &A,const complex &B){return complex(A.num*B.num-A.inum*B.inum,A.num*B.inum+A.inum*B.num);}

void FFT(complex *a,int f)
{
	int i,j,k,t,l;
	complex x,y;
	for(i=0;i<n;++i)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(i=1;i<n;i<<=1)
	for(j=0,t=n/(i<<1);j<n;j+=i<<1)
	for(k=l=0;k<i;++k,l+=t)
	{
		x=w[f][l]*a[j+k+i];
		y=a[j+k];
		a[j+k]=y+x;
		a[j+k+i]=y-x;
	}
	if(f)for(i=0;i<n;++i)a[i].num/=n;
}

void prepare()
{
	int i,j,x,y;
	for(i=0;i<n;++i)
	{
		x=i;y=0;
		for(j=1;j<n;x>>=1,j<<=1)(y<<=1)|=x&1;
		rev[i]=y;
	}
	for(i=0;i<n;++i)
	{
		w[0][i]=complex(cos(2*pi*i/n),sin(2*pi*i/n));
		w[1][i]=complex(cos(2*pi*i/n),-sin(2*pi*i/n));
	}
}

void mult()
{
	int i;
	prepare();
	FFT(a,0);
	for(i=0;i<n;++i)a[i]=a[i]*a[i];
	FFT(a,1);
}

bool num[1000005],chk[1000005];

int main()
{
	scanf("%d%d",&N,&m);ans=N;
	for(n=1;n<m;n*=2);n*=2;
	for(;N;--N)scanf("%d",&k),num[k]=true,a[k].num=1;
	mult();
	for(i=1;i<=m;++i)
	if((int)(a[i].num+0.001))
	{
		if(num[i])--ans,chk[i]=true;
		else
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	printf("%d\n",ans);
	for(i=1;i<=m;++i)if(num[i]&&!chk[i])printf("%d ",i);
	printf("\n");
}