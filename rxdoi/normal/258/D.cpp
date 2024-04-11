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

const int N=1000+19;
double f[N][N],Ans;
int A[N],n,Q,L,R;

int main()
{
	n=IN(),Q=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) For(j,i+1,n+1) f[i][j]=(A[i]>A[j]?1:0);
	while (Q--)
	{
		L=IN();R=IN();
		if (L>R) swap(L,R);
		f[L][R]=0.5;
		For(i,L+1,R)
		{
			double a=f[L][i],b=f[i][R];
			f[L][i]=0.5*a+0.5*(1-b),f[i][R]=0.5*b+0.5*(1-a);
		}
		For(i,1,L) f[i][L]=f[i][R]=(f[i][L]+f[i][R])/2.0;
		For(i,R+1,n+1) f[L][i]=f[R][i]=(f[L][i]+f[R][i])/2.0;
	}
	For(i,1,n+1) For(j,i+1,n+1) Ans+=f[i][j];
	printf("%.10lf\n",Ans);
}