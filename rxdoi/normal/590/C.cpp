#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Mp make_pair
#define x first
#define y second
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

typedef long long LL;
typedef double Db;
typedef pair<int,int> Pii;

const int N=1000+19,oo=(1<<30)-1;
int D[4][N][N],n,m,Ans=oo;
int Dx[4]={1,0,-1,0},Dy[4]={0,1,0,-1};
char s[N][N];
Pii Q[N*N];

void BFS(int c)
{
	int f=0,w=0;
	For(i,1,n+1) For(j,1,m+1)
		if (s[i][j]==c+'0') Q[++f]=Mp(i,j),D[c][i][j]=0;else D[c][i][j]=-1;
	while (f>w)
	{
		Pii A=Q[++w];
		For(i,0,4)
		{
			Pii B=Mp(A.x+Dx[i],A.y+Dy[i]);
			if (B.x<1||B.x>n||B.y<1||B.y>m||s[B.x][B.y]=='#'||~D[c][B.x][B.y]) continue;
			D[c][B.x][B.y]=D[c][A.x][A.y]+1,Q[++f]=B;
		}
	}
}

int main()
{
	n=IN(),m=IN();
	For(i,1,n+1) scanf("%s",s[i]+1);
	BFS(1),BFS(2),BFS(3);
	For(t,1,4) For(p,1,4)
	{
		int Min=oo;
		For(i,1,n+1) For(j,1,m+1) if (s[i][j]==p+'0') Min=min(Min,D[t][i][j]);
		For(i,1,n+1) For(j,1,m+1) if (s[i][j]==p+'0') D[t][i][j]=Min;
	}
	For(i,1,n+1) For(j,1,m+1)
		if (~D[1][i][j]&&~D[2][i][j]&&~D[3][i][j])
			Ans=min(Ans,D[1][i][j]+D[2][i][j]+D[3][i][j]-2);
	printf("%d\n",Ans==oo?-1:Ans);
}