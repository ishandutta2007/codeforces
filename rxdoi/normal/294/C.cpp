#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1000+19,P=1e9+7;
int C[N][N],A[N],Pow[N],n,m,c,Ans;

int main()
{
	n=IN(),m=IN();
	For(i,0,m) A[i]=IN();
	sort(A,A+m);
	Pow[0]=1;For(i,1,n+1) Pow[i]=2*Pow[i-1]%P;
	For(i,0,n+1)
	{
		C[i][0]=1;
		For(j,1,i+1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	}
	Ans=C[c=n-m][A[0]-1],c-=A[0]-1;
	For(i,0,m-1)
		if (A[i]+2<=A[i+1])
			Ans=1LL*Ans*C[c][A[i+1]-A[i]-1]%P*Pow[A[i+1]-A[i]-2]%P,c-=A[i+1]-A[i]-1;
	Ans=1LL*Ans*C[c][n-A[m-1]]%P;
	printf("%d\n",Ans);
}