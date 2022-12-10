#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1000+19,P=1e9+7;
int C[N][N],n,c,x,Ans=1;

int main()
{
	n=IN();c=IN();
	For(i,0,N)
	{
		C[i][0]=1;
		For(j,1,i+1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	}
	For(i,1,n)
	{
		x=IN();
		Ans=1LL*Ans*C[c+x-1][x-1]%P;
		c+=x;
	}
	printf("%d\n",Ans);
}