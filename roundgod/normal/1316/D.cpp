#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P a[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];
int curx,cury,cnt;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
char rmp[4]={'U','L','D','R'};
char mp[4]={'D','R','U','L'};
void bfs()
{
    str[curx][cury]='X';
    queue<P> que;
    que.push(P(curx,cury));
    while(que.size())
    {
        P p=que.front(); que.pop();
        int x=p.F,y=p.S;
        if(vis[x][y]) continue;
        vis[x][y]=true; cnt++;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!vis[nx][ny]&&a[nx][ny].F==curx&&a[nx][ny].S==cury)
            {
                que.push(P(nx,ny));
                str[nx][ny]=mp[i];
            }
        }
    }
}
void die()
{
    puts("INVALID");
    exit(0);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d%d",&a[i][j].F,&a[i][j].S);
    cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i][j].F==-1&&a[i][j].S==-1)
            {
                vis[i][j]=true; cnt++;
                bool f=false;
                for(int k=0;k<4;k++)
                {
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&a[nx][ny].F==-1&&a[nx][ny].S==-1)
                    {
                        f=true;
                        str[i][j]=rmp[k];
                        break;
                    }
                }
                if(!f) die();
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(!vis[i][j]&&a[i][j].F==i&&a[i][j].S==j)
            {
                curx=i;
                cury=j;
                bfs();
            }
        }
    if(cnt==n*n) 
    {
        puts("VALID");
        for(int i=1;i<=n;i++) printf("%s\n",str[i]+1);
    }
    else die();
    return 0;
}