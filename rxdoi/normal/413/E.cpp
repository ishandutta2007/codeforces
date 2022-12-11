#include<cstdio>
#include<queue>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

const int Maxn=2e5+19,oo=(1<<29)-1;
int n,m,Map[Maxn<<1],Dis[25][2][Maxn<<1],a,b,x1,y1,x2,y2;
int Dx[4]={0,1,0,-1},Dy[4]={1,0,-1,0},cc;
char c[Maxn];

inline int to_Dis(int x,int y) {return x*n+y;}
inline int to_x(int num) {return (num-1)/n;}
inline int to_y(int num) {return (num-1)%n+1;}
inline void Read(int &x) 
{
	while (!isdigit(cc=getchar()));
	x=cc-'0';
	while (isdigit(cc=getchar())) x=x*10+cc-'0';
}
inline void BFS(int x,int Mid,int t,int L,int R)
{
	queue<int> Q;
	while (!Q.empty()) Q.pop();
	int now=to_Dis(t,Mid);
	if (Map[now]==0)
	{
		Q.push(now);Dis[x][t][now]=0;
		while (!Q.empty()) 
		{
			int num=Q.front();Q.pop();
			int nx=to_x(num),ny=to_y(num);
			for (int i=0;i<4;i++)
			{
				int xx=nx+Dx[i],yy=ny+Dy[i];
				if (!(xx>=0&&xx<=1&&yy>=L&&yy<=R)) continue;
				int nxt=to_Dis(xx,yy);
				if (Map[nxt]==0&&Dis[x][t][num]+1<Dis[x][t][nxt])
				{
					Dis[x][t][nxt]=Dis[x][t][num]+1;Q.push(nxt);
				}
			}
		}
	}
}
inline void Pre_doing(int x,int L,int R)
{
	if (L>R) return;
	int Mid=(L+R)>>1;
	if (L^R) 
	{
		Pre_doing(x+1,L,Mid-1);
		Pre_doing(x+1,Mid+1,R);
	}
	BFS(x,Mid,0,L,R);
	BFS(x,Mid,1,L,R);
}
inline int Query(int x,int L,int R)
{
	int Mid=(L+R)>>1;
	int Up=to_Dis(0,Mid),Dn=to_Dis(1,Mid);
	if (y1<=Mid&&y2>=Mid) return min(Dis[x][0][a]+Dis[x][0][b],Dis[x][1][a]+Dis[x][1][b]);
	if (y1<=Mid) return Query(x+1,L,Mid-1);else return Query(x+1,Mid+1,R);
}

int main()
{
	memset(Dis,60,sizeof(Dis));
	scanf("%d%d",&n,&m);
	for (int i=0;i<2;i++)
	{
		scanf("%s",c);
		for (int j=1;j<=n;j++) Map[i*n+j]=(c[j-1]=='X');
	}
	Pre_doing(0,1,n);
	while (m--)
	{
		Read(a);Read(b);
		y1=(a-1)%n+1;y2=(b-1)%n+1;
		if (y1>y2) swap(y1,y2);
		int tmp=Query(0,1,n);
		printf("%d\n",tmp<oo?tmp:-1);
	}
}