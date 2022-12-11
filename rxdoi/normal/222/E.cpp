#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=52+19,Mod=1e9+7;
typedef long long LL;
struct Matrix
{
	LL n,m;
	LL s[Maxn][Maxn];	
	Matrix() {n=m=0;memset(s,0,sizeof(s));}
} can,F;
LL n,m,k,Ans;
char s[10];

Matrix operator * (Matrix A,Matrix B)
{
	Matrix C;
	C.n=A.n;C.m=B.m;
	for (int i=1;i<=A.n;i++)
		for (int j=1;j<=B.m;j++)
			for (int k=1;k<=A.m;k++) (C.s[i][j]+=1LL*A.s[i][k]*B.s[k][j]%Mod)%=Mod;
	return C;
}
Matrix Power(Matrix A,LL b)
{
	Matrix Res,tmp=A;
	Res.n=Res.m=m;
	for (int i=1;i<=m;i++) Res.s[i][i]=1;
	while (b)
	{
		if (b&1) Res=Res*tmp;
		tmp=tmp*tmp;
		b>>=1;
	}
	return Res;
}

int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);n--;
	can.n=can.m=m;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++) can.s[i][j]=1;
	while (k--)
	{
		scanf("%s",s);
		int x=(s[0]>='a'?s[0]-'a'+1:s[0]-'A'+1+26);
		int y=(s[1]>='a'?s[1]-'a'+1:s[1]-'A'+1+26);
		can.s[x][y]=0;
	}
	F.n=1,F.m=m;
	for (int i=1;i<=m;i++) F.s[1][i]=1;
	Matrix tmp=F*Power(can,n);
	for (int i=1;i<=m;i++) (Ans+=tmp.s[1][i])%=Mod;
	printf("%I64d\n",Ans);
}