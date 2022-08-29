#include<stdio.h>
#include<cstring>
#define MAXN 1005
using namespace std;
int data[MAXN][MAXN];
int l[MAXN][MAXN];
int r[MAXN][MAXN];
int d[MAXN][MAXN];
int u[MAXN][MAXN];
int n,m,q;
void read(int &x)
{
     x=0;char p=getchar();
     while(!(p<='9'&&p>='0'))p=getchar();
     while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
void workl(int x)
{
     l[x][1]=data[x][1];
     for(int i=2;i<=m;i++)if(data[x][i])l[x][i]=l[x][i-1]+1;else l[x][i]=0;
}
void workr(int x)
{
     r[x][m]=data[x][m];
     for(int i=m-1;i>=1;i--)if(data[x][i])r[x][i]=r[x][i+1]+1;else r[x][i]=0;
}
void workd(int x)
{
     d[n][x]=data[n][x];
     for(int i=n-1;i>=1;i--)if(data[i][x])d[i][x]=d[i+1][x]+1;else d[i][x]=0;
}
void worku(int x)
{
     u[1][x]=data[1][x];
     for(int i=2;i<=n;i++)if(data[i][x])u[i][x]=u[i-1][x]+1;else u[i][x]=0;
}
int t[MAXN];
int s[MAXN];
void Max(int &x,int y){if(y>x)x=y;}
int query(int x,int y)
{
    int ans=0;
    t[1]=0;
    for(int i=2;i<=n;i++)
    {
            int j=i-1;while(j&&l[j][y]>=l[i][y])j=t[j];
            t[i]=j;
            }
    s[n]=n+1;
    for(int i=n-1;i>=1;i--)
    {
            int j=i+1;while(j!=n+1&&l[j][y]>=l[i][y])j=s[j];
            s[i]=j;
            }
    for(int i=1;i<=n;i++)
    if(t[i]<x&&x<s[i])Max(ans,l[i][y]*(s[i]-t[i]-1));
    
    t[1]=0;
    for(int i=2;i<=n;i++)
    {
            int j=i-1;while(j&&r[j][y]>=r[i][y])j=t[j];
            t[i]=j;
            }
    s[n]=n+1;
    for(int i=n-1;i>=1;i--)
    {
            int j=i+1;while(j!=n+1&&r[j][y]>=r[i][y])j=s[j];
            s[i]=j;
            }
    for(int i=1;i<=n;i++)
    if(t[i]<x&&x<s[i])Max(ans,r[i][y]*(s[i]-t[i]-1));
    
    t[1]=0;
    for(int i=2;i<=m;i++)
    {
            int j=i-1;while(j&&u[x][j]>=u[x][i])j=t[j];
            t[i]=j;
            }
    
    s[m]=m+1;
    for(int i=m-1;i>=1;i--)
    {
            int j=i+1;while(j!=m+1&&u[x][j]>=u[x][i])j=s[j];
            s[i]=j;
            }
    for(int i=1;i<=m;i++)
    if(t[i]<y&&y<s[i])Max(ans,u[x][i]*(s[i]-t[i]-1));
    
    t[1]=0;
    for(int i=2;i<=m;i++)
    {
            int j=i-1;while(j&&d[x][j]>=d[x][i])j=t[j];
            t[i]=j;
            }
    
    s[m]=m+1;
    for(int i=m-1;i>=1;i--)
    {
            int j=i+1;while(j!=m+1&&d[x][j]>=d[x][i])j=s[j];
            s[i]=j;
            }
    for(int i=1;i<=m;i++)
    if(t[i]<y&&y<s[i])Max(ans,d[x][i]*(s[i]-t[i]-1));
    return ans;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    read(data[i][j]);
    for(int i=1;i<=n;i++)workl(i),workr(i);
    for(int j=1;j<=m;j++)workd(j),worku(j);
    while(q--)
    {
              int opt,x,y;scanf("%d%d%d",&opt,&x,&y);
              if(opt==1)
              {
                        data[x][y]=!data[x][y];
                        workl(x);workr(x);
                        workd(y);worku(y);
                        }
              else printf("%d\n",query(x,y));
              }
    return 0;
}