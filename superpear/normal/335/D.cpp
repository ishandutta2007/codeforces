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

int N,R,o,findans;
int sum[3005][3005],a[3005][3005],heng[3005][3005],shu[3005][3005],sumheng[3005][3005],sumshu[3005][3005];
int ans[100005],xc[100005],yc[100005],xd[100005],yd[100005];

int main()
{
    R=3000;
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
        scanf("%d %d %d %d",&xc[i],&yc[i],&xd[i],&yd[i]);
    memset(a,0,sizeof(a));
    for (int i=1;i<=N;i++)
        for (int x=xc[i]+1;x<=xd[i];x++)
            for (int y=yc[i]+1;y<=yd[i];y++)
                a[x][y]=1;
    sum[0][0]=0;
    for (int i=1;i<=R;i++)
        for (int j=1;j<=R;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    memset(heng,0,sizeof(heng));
    memset(shu,0,sizeof(shu));
    for (int i=1;i<=N;i++)
    {
        for (int x=xc[i]+1;x<=xd[i];x++)
            heng[x][yc[i]]=1,
            heng[x][yd[i]]=1;
        for (int y=yc[i]+1;y<=yd[i];y++)
            shu[xc[i]][y]=1,
            shu[xd[i]][y]=1;
    }
    memset(sumheng,0,sizeof(sumheng));
    for (int j=0;j<=R;j++)
        sumheng[0][j]=heng[0][j];
    for (int i=1;i<=R;i++)
        for (int j=0;j<=R;j++)
            sumheng[i][j]=sumheng[i-1][j]+heng[i][j];
    memset(sumshu,0,sizeof(sumshu));
    for (int i=0;i<=R;i++)
        sumshu[i][0]=shu[i][0];
    for (int i=0;i<=R;i++)
        for (int j=1;j<=R;j++)
            sumshu[i][j]=sumshu[i][j-1]+shu[i][j];

    findans=1;
    for (int i=1;i<=N;i++)
        for (int j=1;j<=R;j++)
        {
            if (xc[i]+j>R) break;
            if (yc[i]+j>R) break;
            int x1=xc[i]+1,y1=yc[i]+1,x2=xc[i]+j,y2=yc[i]+j;
            if (sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]!=j*j) break;
            if (sumheng[x2][y1-1]-sumheng[x1-1][y1-1]!=j) break;
            if (sumshu[x1-1][y2]-sumshu[x1-1][y1-1]!=j) break;
            if (sumheng[x2][y2]-sumheng[x1-1][y2]!=j) continue;
            if (sumshu[x2][y2]-sumshu[x2][y1-1]!=j) continue;

                findans=0;
                printf("YES");
                int o=0;
                for (int i=1;i<=N;i++)
                    if ((xd[i]>=x1)&&(xd[i]<=x2)&&(yd[i]>=y1)&&(yd[i]<=y2))
                        ++o,ans[o]=i;
                printf(" %d\n",o);
                for (int i=1;i<o;i++) printf("%d ",ans[i]);
                printf("%d\n",ans[o]);
                return 0;

        }
    printf("NO\n");

    return 0;
}