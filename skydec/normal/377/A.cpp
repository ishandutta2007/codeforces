#include<stdio.h>
#include<algorithm>
using namespace std;
long dx[5]={0,1,0,-1,0};
long dy[5]={0,0,1,0,-1};
bool map[505][505];
bool gone[505][505];
long n,m,k;long stx=0,sty=0;long tot=0;long s=0;
void dfs(long x,long y)
{
    if(tot==s-k)return;
    tot++;gone[x][y]=true;
    for(long p=1;p<=4;p++)
    if(x+dx[p]>=1&&x+dx[p]<=n&&y+dy[p]>=1&&y+dy[p]<=m&&map[x+dx[p]][y+dy[p]]&&!gone[x+dx[p]][y+dy[p]])
    dfs(x+dx[p],y+dy[p]);
}
char getnext()
{
    char p=getchar();
    while(p!='.'&&p!='#')p=getchar();
    return p;
}
int main()
{
    scanf("%ld%ld%ld",&n,&m,&k);
    for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
    {
        char p=getnext();
        if(p=='#')map[i][j]=false;else map[i][j]=true;
        gone[i][j]=false;
        if(map[i][j])stx=i,sty=j,s++;
    }
    dfs(stx,sty);
    for(long i=1;i<=n;i++)
    {
        for(long j=1;j<=m;j++)
        if(!map[i][j])putchar('#');
        else if(!gone[i][j])putchar('X');
        else printf(".");
        putchar('\n');
    }
    return 0;
}