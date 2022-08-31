// 
#include<stdio.h>
#include<cstring>
#define bi(x) ((x)+120)
using namespace std;
typedef long long LL;
#define jsb 1000000007
LL k;int n;int f[302][302];
int g[302][302];int jz[302][302];
int dx[9]={0,-1,-1,1,1,2,2,-2,-2};
int dy[9]={0,2,-2,2,-2,1,-1,1,-1};
struct ww{
       int a[4][4];
       inline ww operator *(const ww &b)const
       {
              ww c;memset(c.a,0,sizeof c.a);
              for(int i=1;i<=3;i++)
              for(int j=1;j<=3;j++)
              for(int p=1;p<=3;p++)
              c.a[i][j]=(c.a[i][j]+a[i][p]*1ll*b.a[p][j])%jsb;
              return c;
              }
};
inline void Tiao()
{
       memset(g,0,sizeof g);
       for(int i=1;i<=300;i++)
       for(int j=1;j<=300;j++)
       if(f[i][j])
       {
                  g[i][j]=1;
                  for(int wph=1;wph<=8;wph++)
                  if(!jz[i+dx[wph]][j+dy[wph]])
                  g[i+dx[wph]][j+dy[wph]]=1;
                  }
       for(int i=1;i<=300;i++)
       for(int j=1;j<=300;j++)
       f[i][j]=g[i][j];
}
int calc()
{
    int res=0;
    for(int i=1;i<=300;i++)
    for(int j=1;j<=300;j++)
    res+=f[i][j];
    return res;
}
void __shi(int f1,int f2)
{
     LL b=k-50ll;
     ww a,c;
     memset(c.a,0,sizeof c.a);
     for(int i=1;i<=3;i++)c.a[i][i]=1;
     memset(a.a,0,sizeof a.a);
     a.a[1][2]=-1;
     a.a[2][1]=1;
     a.a[2][2]=2;
     a.a[3][2]=a.a[3][3]=1;
     for(;b;b>>=1,a=a*a)if(b&1)c=c*a;
     ww mb;memset(mb.a,0,sizeof mb.a);
     mb.a[1][1]=f1;
     mb.a[1][2]=f2;
     mb.a[1][3]=28;
     mb=mb*c;
     printf("%d\n",(mb.a[1][2]+jsb)%jsb);
}
int main()
{
    //freopen("chess.in","r",stdin);
    //freopen("chess.out","w",stdout);
    scanf("%I64d%d",&k,&n);
    if(k==0){printf("1\n");return 0;}
    for(int i=1;i<=n;i++)
    {
            int x,y;scanf("%d%d",&x,&y);
            jz[bi(x)][bi(y)]=1;
            }
    int pre=0;int now;f[bi(0)][bi(0)]=1;
    if(k<=50)
    {
              for(int i=1;i<=k;i++)Tiao();
              printf("%d\n",calc());
              return 0;
              }
    int f1,f2;
    for(int i=1;i<=50;i++)
    {
            Tiao();
            if(i==49)f1=calc();
            if(i==50)f2=calc();
            }
    if(f1==f2)
    {
              printf("%d\n",f1);
              return 0;
              }
    __shi(f1,f2);
    return 0;
}