#include<cstdio>
#include<cctype>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100+19;
int A[N][N],B[N][N];
int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	For(i,1,n+1) For(j,1,m+1) scanf("%d",&B[i][j]),A[i][j]=1;
	For(i,1,n+1) For(j,1,m+1)
		if (!B[i][j])
		{
			For(k,1,n+1) A[k][j]=0;
			For(k,1,m+1) A[i][k]=0;
		}
	For(i,1,n+1) For(j,1,m+1)
		if (B[i][j])
		{
			int f=0;
			For(k,1,n+1) f|=A[k][j];
			For(k,1,m+1) f|=A[i][k];
			if (!f) return puts("NO"),0;
		}
	puts("YES");
	for (int i=1;i<=n;i++,puts(""))
		For(j,1,m+1) printf("%d ",A[i][j]);
}