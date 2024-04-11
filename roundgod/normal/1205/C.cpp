#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 daekods
#define y1 fdiasjisa
#define x2 asdkosa
#define y2 saofkasio
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[MAXN][MAXN];
int dx[6]={0,1,2,0,-1,-2};
int dy[6]={2,1,0,-2,-1,0};
int get_ans(int x1,int y1,int x2,int y2)
{
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x^1;
}
void get_all(int x,int y)
{
    queue<P> que;
    que.push(P(x,y));
    while(que.size())
    {
        P p=que.front(); que.pop();
        for(int i=0;i<3;i++)
        {
            int nx=p.F+dx[i],ny=p.S+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&a[nx][ny]==-1)
            {
                a[nx][ny]=get_ans(p.F,p.S,nx,ny)^a[p.F][p.S];
                que.push(P(nx,ny));
            }
        }
        for(int i=3;i<6;i++)
        {
            int nx=p.F+dx[i],ny=p.S+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&a[nx][ny]==-1)
            {
                a[nx][ny]=get_ans(nx,ny,p.F,p.S)^a[p.F][p.S];
                que.push(P(nx,ny));
            }
        }
    }
}
void revert_all(int par)
{
    if(!par) return;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(!((i+j)&1)) continue;
            a[i][j]^=1;
        }
}
void print_all()
{
    puts("!"); fflush(stdout);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d",a[i][j]);
        }
        puts("");
        fflush(stdout);
    }
}
int main()
{
    scanf("%d",&n);
    memset(a,-1,sizeof(a));
    a[1][1]=1;
    a[n][n]=0;
    get_all(1,1);
    bool f=false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(f) break;
            if((i+j)&1) continue;
            if(j>1&&i<n&&a[i][j]!=a[i+1][j-1])
            {
                int same;
                if(j<n)
                {
                    same=get_ans(i,j-1,i+1,j+1);
                    a[i][j-1]=a[i+1][j+1]^same;
                    get_all(i,j-1);
                }
                else
                {
                    same=get_ans(i,j-1,i+2,j);
                    a[i][j-1]=a[i+2][j]^same;
                    get_all(i,j-1);
                }
                f=true;
            }
        }
    if(!f)
    {
        a[1][2]=1;
        get_all(1,2);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(f) break;
                if(!((i+j)&1)) continue;
                if(j>1&&i<n&&a[i][j]!=a[i+1][j-1])
                {
                    int same;
                    if(i==n-1&&j==n)
                    {
                        same=get_ans(i,j-2,i+1,j);
                        revert_all(a[i][j-2]^a[i+1][j]^same);
                    }
                    else if(j<n)
                    {
                        same=get_ans(i,j-1,i+1,j+1);
                        revert_all(a[i][j-1]^a[i+1][j+1]^same);
                    }
                    else
                    {
                        same=get_ans(i,j-1,i+2,j);
                        revert_all(a[i][j-1]^a[i+2][j]^same);
                    }
                    f=true;
                }
            }
    }
    if(!f)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(!((i+j)&1)) continue;
                if(f) break;
                if(i+1<=n&&j+2<=n&&a[i][j]==a[i+1][j+2]&&a[i+1][j]==a[i+1][j+1])
                {
                    int same=get_ans(i,j,i+1,j+2);
                    revert_all(same);
                    f=true;
                    break;
                }
                else if(i+1<=n&&j+2<=n&&a[i][j]!=a[i+1][j+2]&&a[i+1][j]!=a[i+1][j+1])
                {
                    int same=get_ans(i,j,i+1,j+2);
                    revert_all(!same);
                    f=true;
                    break;
                }
            }
    }
    assert(f);
    print_all();
    return 0;
}