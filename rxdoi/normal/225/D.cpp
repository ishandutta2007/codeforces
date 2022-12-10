#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=16,tot=14745600+19;
char s[N][N],Map[N][N];
int Dx[4]={1,0,-1,0},Dy[4]={0,1,0,-1};
int Q[tot],Dis[tot],Len,n,m,S;

int GetID()
{
	int t=0,x,y;
	For(i,0,n) For(j,0,m) if (s[i][j]=='1') t=i*m+j,x=i,y=j;
	For(i,2,Len) For(k,0,4)
	{
		int tx=x+Dx[k],ty=y+Dy[k];
		if (tx>=0&&tx<n&&ty>=0&&ty<m&&s[tx][ty]=='0'+i) {t=t<<2|k,x=tx,y=ty;break;}
	}
	return t;
}
void ReID(int t,int &Ax,int &Ay)
{
	int A[N],x,y;
	for (int i=Len-1;i>=2;i--) A[i]=t&3,t>>=2;
	For(i,1,n+1) 
	For(i,0,n) For(j,0,m) s[i][j]=Map[i][j];
	s[Ax=x=t/m][Ay=y=t%m]='2';
	For(i,2,Len) s[x=x+Dx[A[i]]][y=y+Dy[A[i]]]='0'+i+1;
}
void BFS(int S)
{
	memset(Dis,-1,sizeof(Dis));Dis[S]=0;
	int f=1,w=0,t;Q[1]=S;
	while (f>w)
	{
		int x,y;
		ReID(Q[++w],x,y);
		For(i,0,4)
		{
			int nx=x+Dx[i],ny=y+Dy[i];
			if (nx>=0&&nx<n&&ny>=0&&ny<m&&(s[nx][ny]=='.'||s[nx][ny]=='@'))
			{
				if (s[nx][ny]=='@') {printf("%d\n",Dis[Q[w]]+1);return;}
				s[nx][ny]='1';
				if (Dis[t=GetID()]==-1) Dis[t]=Dis[Q[w]]+1,Q[++f]=t;
				s[nx][ny]='.';
			}
		}
	}
	puts("-1");
}

int main()
{
	scanf("%d%d",&n,&m);
	For(i,0,n) scanf("%s",Map[i]);
	For(i,0,n) For(j,0,m) s[i][j]=Map[i][j];
	For(i,0,n) For(j,0,m) if (isdigit(Map[i][j])) Len=max(Len,Map[i][j]-'0'),Map[i][j]='.';
	BFS(GetID());
}