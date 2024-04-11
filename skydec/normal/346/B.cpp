#include<stdio.h>
#include<cstring>
#include<map>
#include<algorithm>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define MAXN 205
using namespace std;
char a[MAXN],b[MAXN],c[MAXN];
int Na,Nb,Nc;
int f[MAXN][MAXN][MAXN];
int next[MAXN];
struct pre
{
       int pi,pj,pk,path;
       void mk(int x,int y,int z,int u)
       {
            pi=x;pj=y;pk=z;path=u;
            }
}pa[MAXN][MAXN][MAXN],u;
int ne[MAXN][MAXN],nf[MAXN][MAXN];
void init()
{
     per(i,Na-1,0)
     {
                  rep(j,'A','Z')ne[i][j]=ne[i+1][j];
                  ne[i][a[i+1]]=i+1;
                  }
     
     per(i,Nb-1,0)
     {
                  rep(j,'A','Z')nf[i][j]=nf[i+1][j];
                  nf[i][b[i+1]]=i+1;
                  }
     next[1]=0;
     rep(i,2,Nc)
     {
                int j=next[i-1];
                while(j&&c[j+1]!=c[i])j=next[j];
                if(c[j+1]==c[i])next[i]=j+1;
                else next[i]=0;
                }
}
int add(int x,char p)
{
     while(c[x+1]!=p&&x)x=next[x];
     if(c[x+1]==p)return x+1;return 0;
}
char q[MAXN];
void Output()
{
     int tot=0;
     int i,j,k;i=u.pi;j=u.pj;k=u.pk;
     while(i&&j)
     {
                   q[++tot]=pa[i][j][k].path;
                   int i1=i;int j1=j;int k1=k;
                   i=pa[i1][j1][k1].pi;
                   j=pa[i1][j1][k1].pj;
                   k=pa[i1][j1][k1].pk;
                   }
     per(i,tot,1)printf("%c",q[i]);
     if(!tot)printf("0\n");
}
int main()
{
    scanf("%s",a+1);Na=strlen(a+1);
    scanf("%s",b+1);Nb=strlen(b+1);
    scanf("%s",c+1);Nc=strlen(c+1);
    init();u.pi=u.pj=u.pk=u.path=0;
    rep(i,0,Na)rep(j,0,Nb)rep(k,0,Nc-1)
    rep(p,'A','Z')
    {
      if(f[i][j][k]>f[u.pi][u.pj][u.pk])
      {
         u.pi=i;u.pj=j;u.pk=k;
         }
      int us=add(k,p);
      if(!ne[i][p])continue;
      if(!nf[j][p])continue;
      if(us==Nc)continue;
      if(f[ne[i][p]][nf[j][p]][us]<f[i][j][k]+1)
      {
        f[ne[i][p]][nf[j][p]][us]=f[i][j][k]+1;
        pa[ne[i][p]][nf[j][p]][us].mk(i,j,k,p);
        }
    }
    //printf("%d %d\n",ne[8]['R'],nf[1]['R']);
    Output();
    return 0;
}