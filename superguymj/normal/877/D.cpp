#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1005;
const int hx[]={0,1,0,-1};
const int hy[]={1,0,-1,0};
int n,m,k,sx,sy,tx,ty,dis[N][N][2],head,tail;
char s[N][N];
struct data{int x,y,dis;} q[N*N*2];

int bfs()
{
	rep(i,1,n) rep(j,1,m) dis[i][j][0]=dis[i][j][1]=1e9;
	q[head=tail=0]=(data){sx,sy,dis[sx][sy][0]=dis[sx][sy][1]=0};
	while(head<=tail)
	{
		data tmp=q[head++];
		if(tmp.x==tx && tmp.y==ty) return tmp.dis;
		rep(i,0,3)
		{
			int x=tmp.x,y=tmp.y;
			rep(j,1,k)
			{
				x+=hx[i],y+=hy[i];
				if(x<1 || y<1 || x>n || y>m || dis[x][y][i%2]!=1e9 || s[x][y]=='#') break;
				dis[x][y][i%2]=tmp.dis+1,q[++tail]=(data){x,y,tmp.dis+1};
			}
		}
	}
	return -1;
}

int main()
{	
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n) scanf("%s",s[i]+1);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	printf("%d\n",bfs());
	return 0;
}