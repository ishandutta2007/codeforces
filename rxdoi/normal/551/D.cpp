#include<cstdio>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

typedef long long LL;
struct Matrix {int n,m,s[2][2];} A,f;
LL n,k,tmp;int P,l,cnt,Ans;

int Pow(int a,LL b)
{
	int res=1;
	for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
	return res;
}

Matrix operator * (Matrix A,Matrix B)
{
	Matrix C;C.n=A.n,C.m=B.m;
	For(i,0,C.n) For(j,0,C.m)
	{
		C.s[i][j]=0;
		For(k,0,A.m) (C.s[i][j]+=1LL*A.s[i][k]*B.s[k][j]%P)%=P;
	}
	return C;
}
Matrix Pow(Matrix A,LL b)
{
	Matrix res=A;
	for (--b;b;b>>=1,A=A*A) if (b&1) res=res*A;
	return res;
}

int main()
{
	scanf("%I64d%I64d%d%d",&n,&k,&l,&P);Ans=1%P;
	for (LL i=k;i;i>>=1) cnt++;
	A.n=1,A.m=2;A.s[0][0]=A.s[0][1]=1;
	f.n=2,f.m=2;f.s[0][0]=f.s[0][1]=f.s[1][0]=1;
	A=A*Pow(f,n-1);
	tmp=(A.s[0][0]+A.s[0][1])%P;
	for (int i=0;i<l;i++,k>>=1)
		if (k&1) Ans=1LL*Ans*(Pow(2,n)-tmp+P)%P;else Ans=1LL*Ans*tmp%P;
	printf("%d\n",!k?Ans:0);
}