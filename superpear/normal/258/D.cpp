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

int n,m,xc,yc;
int a[1005];
double f[1005][1005];
double t,ans;

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i]>a[j]) f[i][j]=1; else f[i][j]=0;
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        for (int j=1;j<=n;j++)
            if ((j!=xc)&&(j!=yc))
            {
                t=(f[j][xc]+f[j][yc])/2;
                f[j][xc]=t,f[j][yc]=t;
                f[xc][j]=1-t,f[yc][j]=1-t;
            }
        f[xc][yc]=0.5,f[yc][xc]=0.5;
    }
    ans=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            ans+=f[i][j];
    printf("%.10lf\n",ans);

    return 0;
}