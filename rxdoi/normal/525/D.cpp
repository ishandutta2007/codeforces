#include<cstdio>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=2000+19;
struct node {int x,y;} Q[N*N];
char s[N][N];
int n,m,f,w;

inline void Push(int x,int y)
{
	if (s[x][y]=='.') return;s[x][y]='.';
	Q[++f]=(node){x,y};
}
inline void Check(int x,int y)
{
	if (x<2||x>n||y<1||y>m-1) return;
	if (s[x][y]+s[x][y+1]+s[x-1][y]+s[x-1][y+1]!='.'+'.'+'.'+'*') return;
	Push(x,y),Push(x,y+1),Push(x-1,y),Push(x-1,y+1);
}

int main()
{
	scanf("%d%d",&n,&m);
	For(i,1,n+1) scanf("%s",s[i]+1);
	For(i,1,n+1) For(j,1,m+1) Check(i,j);
	while (f>w)
	{
		node A=Q[++w];
		Check(A.x,A.y-1),Check(A.x,A.y),Check(A.x+1,A.y-1),Check(A.x+1,A.y);
	}
	For(i,1,n+1) puts(s[i]+1);
}