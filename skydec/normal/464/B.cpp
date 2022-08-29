#include<stdio.h>
using namespace std;
typedef long long LL;
int x[9],y[9],z[9];
int X[9],Y[9],Z[9];
bool find=0;
LL dis[9];
inline bool check()
{
     LL max=-1;LL cmax=-1;LL min=-1;;
     int c1=0;int c2=0;int c3=0;
     for(int i=2;i<=8;i++)
     {
             int dx=X[i]-X[1];
             int dy=Y[i]-Y[1];
             int dz=Z[i]-Z[1];
             dis[i]=dx*1ll*dx+dy*1ll*dy+dz*1ll*dz;
             //printf("%I64d\n",dis[i]);
             if(min==-1||dis[i]<min)min=dis[i];
             if(max==-1||dis[i]>max)max=dis[i];
             }
     //printf("%I64d %I64d %I64d\n",max,cmax,min);
     for(int i=2;i<=8;i++)
     if(dis[i]!=min&&dis[i]!=max)
     {
                                 if(cmax!=-1&&cmax!=dis[i])return 0;
                                 cmax=dis[i];  
                                 }
     else if(dis[i]==min)c3++;
     else if(dis[i]==max)c1++;
     if(cmax==-1)return 0;
     if(c1==1&&c3==3)
     if(max==min*3ll&&cmax==min*2ll)
     return 1;
     return 0;
}
inline bool checker()
{
     bool f=1;
     for(register int i=1;i<=8;i++)
     {
             int tmp=X[i];X[i]=X[1];X[1]=tmp;
             tmp=Y[i];Y[i]=Y[1];Y[1]=tmp;
             tmp=Z[i];Z[i]=Z[1];Z[1]=tmp;
             f&=check();
             tmp=X[i];X[i]=X[1];X[1]=tmp;
             tmp=Y[i];Y[i]=Y[1];Y[1]=tmp;
             tmp=Z[i];Z[i]=Z[1];Z[1]=tmp;
             if(!f)return 0;
             }
     if(f)
     {
          find=1;
          printf("YES\n");
          for(int i=1;i<=8;i++)printf("%d %d %d\n",X[i],Y[i],Z[i]);
          }
}
void dfs(int s)
{
     if(find)return;
     if(s>8)
     {
               checker();
               return;
               }
     X[s]=x[s];Y[s]=y[s];Z[s]=z[s];dfs(s+1);
     X[s]=x[s];Y[s]=z[s];Z[s]=y[s];dfs(s+1);
     X[s]=y[s];Y[s]=x[s];Z[s]=z[s];dfs(s+1);
     X[s]=y[s];Y[s]=z[s];Z[s]=x[s];dfs(s+1);
     X[s]=z[s];Y[s]=x[s];Z[s]=y[s];dfs(s+1);
     X[s]=z[s];Y[s]=y[s];Z[s]=x[s];dfs(s+1);
}
int main()
{
    for(int i=1;i<=8;i++)scanf("%d%d%d",&x[i],&y[i],&z[i]);
    //check();
    dfs(1);
    if(!find){printf("NO");}
    return 0;
}