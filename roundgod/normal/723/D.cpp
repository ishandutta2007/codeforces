#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAXL 1500
#define MAXN 52
#define INF 100000000
using namespace std;
struct type
{
    int val,x,y;
};
int n,m,k,cnt,f;
char field[MAXN][MAXN],same[MAXN][MAXN];
type sav[MAXL];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool cmp(const type &a, const type &b)
{
     return a.val<b.val;
}
void dfs(int x,int y)
{
    field[x][y]='*';
    if(x==0||y==0||x==n-1||y==m-1) f=0;
    cnt++;
    for(int i=0;i<4;i++)
        {
           int nx=x+dx[i],ny=y+dy[i];
           if(0<=nx&&nx<n&&0<=ny&&ny<m&&field[nx][ny]=='.') dfs(nx,ny);
        }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%s",field[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          same[i][j]=field[i][j];
    memset(sav,0,sizeof(sav));
    int index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(field[i][j]=='.')
            {
                f=1;
                cnt=0;
                dfs(i,j);
                if(f)
                {
                    sav[index].val=cnt;
                    sav[index].x=i;
                    sav[index].y=j;
                    index++;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        field[i][j]=same[i][j];
    sort(sav,sav+index,cmp);
    int s=0;
    for(int i=0;i<index-k;i++)
    {
        s+=sav[i].val;
        dfs(sav[i].x,sav[i].y);
    }
    printf("%d\n",s);
    for(int i=0;i<n;i++)
        printf("%s\n",field[i]);
return 0;
}