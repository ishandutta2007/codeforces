#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define N 1610
int n,m;bool a[N][N],b[N][N];
int v[N][N],tg=0,d[N][N],qx[N*N],qy[N*N],A[N*N],L,w[N][N];
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int ff(int sx,int sy,int sd)
{
    int le=0,ri=1;
    qx[0]=sx,qy[0]=sy,d[sx][sy]=0,v[sx][sy]=tg;
    while(le<ri)
    {
        int x=qx[le],y=qy[le];le++;
        if(d[x][y]==sd)break;
        for(int i=0;i<4;i++)
        {
            int x1=x+dx[i],y1=y+dy[i];
            if(x1<0||x1>=n||y1<0||y1>=m)continue;
            if(!a[x1][y1])continue;
            if(v[x1][y1]!=tg)v[x1][y1]=tg,qx[ri]=x1,qy[ri]=y1,ri++,d[x1][y1]=d[x][y]+1;
        }
    }
    return ri;
}
int gg(int sx,int sy)
{
    int le=0,ri=1;
    qx[0]=sx,qy[0]=sy,w[sx][sy]=tg;
    while(le<ri)
    {
        int x=qx[le],y=qy[le];le++;
        for(int i=0;i<4;i++)
        {
            int x1=x+dx[i],y1=y+dy[i];
            if(x1<0||x1>=n||y1<0||y1>=m)continue;
            if(!b[x1][y1])continue;
            if(w[x1][y1]!=tg)w[x1][y1]=tg,qx[ri]=x1,qy[ri]=y1,ri++,d[x1][y1]=d[x][y]+1;
        }
    }
    return ri;
}
set<int> W;
int hh(int sx,int sy)
{
    int le=0,ri=1;
    qx[0]=sx,qy[0]=sy,d[sx][sy]=0,v[sx][sy]=tg;
    int s=0;
    while(le<ri)
    {
        int x=qx[le],y=qy[le];le++;
        if(w[x][y]&&W.find(w[x][y])==W.end())W.insert(w[x][y]),s++;
        for(int i=0;i<4;i++)
        {
            int x1=x+dx[i],y1=y+dy[i];
            if(x1<0||x1>=n||y1<0||y1>=m)continue;
            if(!a[x1][y1])continue;
            if(v[x1][y1]!=tg)v[x1][y1]=tg,qx[ri]=x1,qy[ri]=y1,ri++,d[x1][y1]=d[x][y]+1;
        }
    }
    return s;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int x;scanf("%d",&x);
            a[i][j]=x;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)if(a[i][j])
        {
            tg++;
            if(ff(i,j,5)<=20)b[i][j]=1;
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)if(b[i][j])
            tg++,gg(i,j);
    tg++;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)if(a[i][j]&&v[i][j]!=tg)A[L++]=hh(i,j);
    sort(A,A+L);
    printf("%d\n",L);
    for(int i=0;i<L;i++)printf("%d%c",A[i],i==L-1?'\n':' ');
    return 0;
}