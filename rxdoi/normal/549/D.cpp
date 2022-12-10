#include<cstdio>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=100+19;
char s[N][N];
int f[N][N];
int Ans,n,m,t;

int main()
{
	scanf("%d%d",&n,&m);
	For(i,1,n+1) scanf("%s",s[i]+1);
	for (int i=n;i;i--)
		for (int j=m;j;j--)
			if (f[i][j]!=(t=s[i][j]=='W'?1:-1))
			{
				Ans++,t-=f[i][j];
				For(k,1,i+1) For(l,1,j+1) f[k][l]+=t;
			}
	printf("%d\n",Ans);
}