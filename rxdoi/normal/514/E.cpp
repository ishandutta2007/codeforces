#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int Mod=1e9+7;
struct Matrix
{
	int n,m;
	int s[101][101];
	Matrix() {For(i,0,101) For(j,0,101) s[i][j]=0;}
} A,f;
int n,x,D;

Matrix operator * (Matrix A,Matrix B)
{
	Matrix C;C.n=A.n,C.m=B.m;
	For(i,0,C.n) For(k,0,A.m) For(j,0,C.m)
		(C.s[i][j]+=1LL*A.s[i][k]*B.s[k][j]%Mod)%=Mod;
	return C;
}
Matrix Pow(Matrix A,int b)
{
	Matrix res=A;
	for (--b;b;b>>=1,A=A*A) if (b&1) res=res*A;
	return res;
}

int main()
{
	scanf("%d%d",&n,&x);
	if (!x) return puts("1"),0;
	For(i,0,n)
	{
		scanf("%d",&D);
		A.s[100-D][99]++;
		A.s[100-D][100]++;
	}
	For(i,1,100) A.s[i][i-1]=1;
	A.s[100][100]=1,A.n=A.m=101;
	f.s[0][99]=f.s[0][100]=1,f.n=1,f.m=101;
	f=f*Pow(A,x);
	printf("%d\n",f.s[0][100]);
}