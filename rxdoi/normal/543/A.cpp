#include<cstdio>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=500+19;
int F[N][N],A[N],c=1,p,n,m,b,Mod,Ans;

int main()
{
	scanf("%d%d%d%d",&n,&m,&b,&Mod);
	For(i,1,n+1) scanf("%d",&A[i]);
	F[0][0]=1;
	For(i,1,n+1)
	{
		c^=1,p^=1;
		for (int j=1;j<=m;j++)
			for (int k=A[i];k<=b;k++) (F[j][k]+=F[j-1][k-A[i]])%=Mod;
	}
	For(i,0,b+1) (Ans+=F[m][i])%=Mod;
	printf("%d\n",Ans);
}