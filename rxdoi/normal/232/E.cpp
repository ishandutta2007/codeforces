#include<cstdio>
#include<bitset>
using namespace std;

const int Maxn=500+19;
bitset<Maxn> F[15][Maxn][Maxn];
int n,m,Q,x1,x2,y1,y2,c[Maxn][Maxn];
char Map[Maxn][Maxn];

inline void Dp(int Dis,int L,int R)
{
	int Mid=(L+R)>>1;
	if (L<R) Dp(Dis+1,L,Mid),Dp(Dis+1,Mid+1,R);
	for (int i=n;i>=1;i--)
		for (int j=Mid;j>=L;j--) 
			if (Map[i][j]=='.') 
			{
				F[Dis][i][j]=F[Dis][i+1][j];
				if (j==Mid) F[Dis][i][j][i]=1;else F[Dis][i][j]|=F[Dis][i][j+1];
			}
	for (int i=1;i<=n;i++)
		for (int j=Mid+1;j<=R;j++)
			if (Map[i][j]=='.') 
			{
				F[Dis][i][j]=F[Dis][i-1][j];
				if (j==Mid+1) F[Dis][i][j][i]=1;else F[Dis][i][j]|=F[Dis][i][j-1];
			}
}
inline int check(int Dis,int L,int R)
{
	int Mid=(L+R)>>1;
	if (y1<=Mid&&Mid+1<=y2) return (F[Dis][x1][y1]&F[Dis][x2][y2])!=0;
	if (y1<=Mid) return check(Dis+1,L,Mid);else return check(Dis+1,Mid+1,R);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",Map[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) c[i][j]=c[i-1][j]+(Map[i][j]=='#');
	Dp(0,1,m);
	scanf("%d",&Q);
	while (Q--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		puts((y1==y2?c[x1][y1]==c[x2][y2]:check(0,1,m))?"Yes":"No");
	}
}