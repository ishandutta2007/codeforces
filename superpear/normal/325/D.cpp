#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=3005;

int a[3005][6005];
int fa[1000005];
int M,N,Q,tc,o,ans,xc,yc,flag;

void merge(int x,int y)
{
    //cout<<x<<" "<<y<<endl;
    int xc=x,yc=y,uu;
    while (fa[x]!=x) x=fa[x];
    while (fa[y]!=y) y=fa[y];
    fa[x]=y;
    while (fa[xc]!=y)
    {
        uu=fa[xc];
        fa[xc]=y;
        xc=uu;
    }
    while (fa[yc]!=y)
    {
        uu=fa[yc];
        fa[yc]=y;
        yc=uu;
    }
}

int getfa(int x)
{
    while (fa[x]!=x) x=fa[x];
    return x;
}

int main()
{
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);

    scanf("%d %d %d",&M,&N,&Q);
    memset(a,0,sizeof(a));
    if (N==1)
    {
        cout<<0<<endl;
        return 0;
    }

    tc=Q*2;
    for (int i=1;i<=tc;i++) fa[i]=i;

    int y1,y2;
    ans=0;
    for (int i=1;i<=Q;i++)
    {
        scanf("%d %d",&xc,&yc);
        flag=1;
        for (int xi=xc-1;xi<=xc+1;xi++)
            for (int yi=yc-1;yi<=yc+1;yi++)
                if ((xi>=1)&&(xi<=M))
                    for (int xj=xc-1;xj<=xc+1;xj++)
                        for (int yj=yc+N-1;yj<=yc+N+1;yj++)
                            if ((xj>=1)&&(xj<=M))
                            {
                                if (yi==0) y1=2*N; else
                                if (yi==2*N+1) y1=1; else y1=yi;
                                if (yj==0) y2=2*N; else
                                if (yj==2*N+1) y2=1; else y2=yj;
                                if ((a[xi][y1]!=0)&&(a[xj][y2]!=0))
                                    if (getfa(a[xi][y1])==getfa(a[xj][y2])) flag=0;
                                    //,cout<<xi<<" "<<yi<<" "<<xj<<" "<<yj<<endl;
                            }
        if (flag==1)
        {
            ++ans;
            a[xc][yc]=i,a[xc][yc+N]=i+Q;
            for (int xi=xc-1;xi<=xc+1;xi++)
                for (int yi=yc-1;yi<=yc+1;yi++)
                    if ((xi>=1)&&(xi<=M))
                    {
                        if (yi==0) y1=2*N; else
                        if (yi==2*N+1) y1=1; else y1=yi;
                        if (a[xi][y1]!=0) merge(a[xc][yc],a[xi][y1]);
                    }
            for (int xi=xc-1;xi<=xc+1;xi++)
                for (int yi=yc+N-1;yi<=yc+N+1;yi++)
                    if ((xi>=1)&&(xi<=M))
                    {
                        if (yi==0) y1=2*N; else
                        if (yi==2*N+1) y1=1; else y1=yi;
                        if (a[xi][y1]!=0) merge(a[xc][yc+N],a[xi][y1]);
                    }
        }
        //cout<<flag<<endl;
    }

    /*for (int i=1;i<=M;i++)
    {
        for (int j=1;j<=N*2;j++)
            if (a[i][j]==0) printf("%3d",0); else printf("%3d",getfa(a[i][j]));
        cout<<endl;
    }*/

    printf("%d\n",ans);

    return 0;
}