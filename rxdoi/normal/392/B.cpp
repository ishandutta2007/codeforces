#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int M=40+9;
const LL oo=1LL<<60;
LL A[4][4],F[M][M][M],n;

inline LL Go(int i,int j,int k)
{
	if (k==0) return 0;
	if (F[i][j][k]<oo) return F[i][j][k];
	int x=6-i-j;
	LL& Ans=F[i][j][k];
	Ans=A[i][j]+Go(i,x,k-1)+Go(x,j,k-1);
	//Ans=min(Ans,Go(i,x,k)+Go(x,j,k));
	Ans=min(Ans,A[i][x]+A[x][j]+2*Go(i,j,k-1)+Go(j,i,k-1));
	return Ans;
}

int main()
{
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++) scanf("%I64d",&A[i][j]);
	scanf("%d",&n);
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			for (int k=1;k<=n;k++) F[i][j][k]=1LL<<60;
	printf("%I64d\n",Go(1,3,n));
}