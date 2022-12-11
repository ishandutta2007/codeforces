#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int Maxn=100+19,M=1e5+19;
struct note {int x,y;};
int n,r,c,rr,cc,Ans;
int A[Maxn],Dis[Maxn][M],vis[Maxn][M];
queue<note> Q;

inline void Relax(int x,int y,int D)
{
	if (Dis[x][y]>D+1) 
	{
		Dis[x][y]=D+1;
		if (!vis[x][y]) Q.push((note){x,y});
		vis[x][y]=1;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]),A[i]++;
	scanf("%d%d%d%d",&r,&c,&rr,&cc);
	memset(Dis,60,sizeof(Dis));
	Dis[r][c]=0;Q.push((note){r,c});
	while (!Q.empty())
	{
		int nr=Q.front().x,nc=Q.front().y;Q.pop();
		if (nr!=1) Relax(nr-1,min(nc,A[nr-1]),Dis[nr][nc]);
		if (nr!=n) Relax(nr+1,min(nc,A[nr+1]),Dis[nr][nc]);
		if (nc!=1) Relax(nr,nc-1,Dis[nr][nc]);
		if (nc!=A[nr]) Relax(nr,nc+1,Dis[nr][nc]);
	}
	printf("%d\n",Dis[rr][cc]);
}