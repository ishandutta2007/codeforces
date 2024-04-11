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

const int N=2000+19;
double f[N][N],p,Ans;
int n,t;

int main()
{
	scanf("%d%lf%d",&n,&p,&t);
	f[0][n]=1;
	For(i,0,t) For(j,0,n+1)
		if (j)
			f[i+1][j-1]+=f[i][j]*p,
			f[i+1][j]+=f[i][j]*(1-p);
		else f[i+1][j]+=f[i][j];
	For(i,0,n+1) Ans+=f[t][i]*(n-i);
	printf("%.10lf\n",Ans);
}