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

const int N=500+19;
int vis[N][N],n,m,x1,y1,x2,y2,cnt,tot;
char s[N][N];
int Dx[4]={0,1,0,-1},Dy[4]={1,0,-1,0};

bool DFS(int x,int y)
{
	vis[x][y]=1;
	if (x==x2&&y==y2) return 1;
	if ((x!=x1||y!=y1)&&s[x][y]=='X') return 0;
	For(i,0,4)
	{
		int tx=x+Dx[i],ty=y+Dy[i];
		if (tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty])
			if (DFS(tx,ty)) return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	For(i,1,n+1) scanf("%s",s[i]+1);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	For(i,0,4)
	{
		int tx=x2+Dx[i],ty=y2+Dy[i];
		if (tx>=1&&tx<=n&&ty>=1&&ty<=m&&s[tx][ty]=='.') cnt++;
	}
	if (abs(x1-x2)+abs(y1-y2)==1) cnt++;
	if (s[x2][y2]=='X'&&cnt<1||s[x2][y2]=='.'&&cnt<2) return puts("NO"),0;
	
	puts(DFS(x1,y1)?"YES":"NO");
}