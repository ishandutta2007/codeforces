#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p 1000000007
using namespace std;

struct Matrix
{
	#define Matrix_Size 15
	#define Matrix_value long long
	#define Matrix_mod p
	
	int n;
	Matrix_value a[Matrix_Size][Matrix_Size];
	
	void clear(int N){n=N;for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)a[i][j]=0;}
	void unit(int N){clear(N);for(int i=1;i<=N;++i)a[i][i]=1;}
	
	Matrix operator +(const Matrix &b)const
	{
		Matrix tmp;tmp.clear(n);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			tmp.a[i][j]=a[i][j]+b.a[i][j];
			if(tmp.a[i][j]>=Matrix_mod)tmp.a[i][j]-=Matrix_mod;
		}
		return tmp;
	}
	Matrix operator -(const Matrix &b)const
	{
		Matrix tmp;tmp.clear(n);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			tmp.a[i][j]=a[i][j]-b.a[i][j];
			if(tmp.a[i][j]<0)tmp.a[i][j]+=Matrix_mod;
		}
		return tmp;
	}
	Matrix operator *(const Matrix &b)const
	{
		Matrix tmp;tmp.clear(n);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(a[i][j])
		for(int k=1;k<=n;++k)
		tmp.a[i][k]=(tmp.a[i][k]+a[i][j]*b.a[j][k])%Matrix_mod;
		return tmp;
	}
	Matrix operator *(const Matrix_value &b)const
	{
		Matrix tmp;tmp.clear(n);
		Matrix_value c=b%Matrix_mod;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		tmp.a[i][j]=a[i][j]*c%Matrix_mod;
		return tmp;
	}
	
	Matrix &operator +=(const Matrix &b){*this=*this+b;return *this;}
	Matrix &operator -=(const Matrix &b){*this=*this-b;return *this;}
	Matrix &operator *=(const Matrix &b){*this=*this*b;return *this;}
	Matrix &operator *=(const Matrix_value &b){*this=*this*b;return *this;}
	
	Matrix operator ^(long long n)const
	{
		Matrix power=*this,tmp;tmp.unit(power.n);
		for(;n;n>>=1)
		{
			if(n&1)tmp*=power;
			power*=power;
		}
		return tmp;
	}
	
	#undef Matrix_mod
	#undef Matrix_value
	#undef Matrix_Size
}A,invA;

int n,i,j,k,B;
long long a;
bool flag;

int Power(int a,long long b)
{
	int ans=1;
	for(;b;b>>=1,a=(long long)a*a%p)if(b&1)ans=(long long)ans*a%p;
	return ans;
}

int main()
{
	A.clear(2);
	A.a[1][1]=1;A.a[1][2]=2;A.a[2][1]=1;
	invA.a[1][2]=1;invA.a[2][1]=Power(2,p-2);invA.a[2][2]=p-Power(2,p-2);
	B=2;
	scanf("%d",&n);
	for(;n;--n)
	{
		scanf("%I64d",&a);
		if(a>1)
		{
			flag=true;
			B=Power(B,a%(p-1));
			A=(A^(a%(p-1)));
		}
	}
	if(flag)
	{
		B=(long long)B*Power(2,p-2)%p;
		A*=invA;A*=invA;
		printf("%I64d/%d\n",A.a[1][1],B);
	}
	else printf("0/1\n");
}