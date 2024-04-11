#include<bits/stdc++.h>
#define MAXN 1005
#define MAXK 45
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,k,q;
int a[MAXN][MAXN];
int d[MAXK][MAXK];
int to[MAXK][MAXN][MAXN];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
void floyd_warshall()
{
    for(int kk=1;kk<=k;kk++)
        for(int i=1;i<=k;i++)
          for(int j=1;j<=k;j++) d[i][j]=min(d[i][j],d[i][kk]+d[kk][j]);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++)
            d[i][j]=(i==j?0:INF);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int c=1;c<=k;c++)
    {
        queue<P> que;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j]==c) 
                {
                    que.push(P(i,j));
                    to[c][i][j]=0;
                }
                else to[c][i][j]=INF;
        while(que.size())
        {
            P p=que.front(); que.pop();
            int x=p.F,y=p.S;
            for(int dir=0;dir<4;dir++)
            {
                int nx=x+dx[dir],ny=y+dy[dir];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&to[c][nx][ny]==INF)
                {
                    to[c][nx][ny]=to[c][x][y]+1;
                    int cc=a[nx][ny];
                    d[c][cc]=d[cc][c]=min(d[c][cc],to[c][nx][ny]+1);
                    que.push(P(nx,ny));
                }
            }
        }
    }
    floyd_warshall();
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y,xx,yy;
        scanf("%d%d%d%d",&x,&y,&xx,&yy);
        int ans=max(x-xx,xx-x)+max(y-yy,yy-y);
        for(int c1=1;c1<=k;c1++)
            for(int c2=1;c2<=k;c2++) 
                ans=min(ans,to[c1][x][y]+to[c2][xx][yy]+d[c1][c2]+1);
        printf("%d\n",ans);
    }
    return 0;
}