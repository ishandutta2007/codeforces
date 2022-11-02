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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

int a[705][705],du[705],f[705][705];
LL ans,ans1;
int n,m,xc,yc,c1,c2;

int main()
{
    memset(a,0,sizeof(a));
    scanf("%d %d",&n,&m);
    memset(du,0,sizeof(du));
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        a[xc][yc]=1;
        a[yc][xc]=1;
        ++du[xc];
        ++du[yc];
    }
    ans=0;ans1=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            f[i][j]=0;
            for (int k=1;k<=n;k++)
                if ((k!=i)&&(k!=j))
                    if ((a[i][k]==1)&&(a[j][k]==1))
                    {
                        ++f[i][j];
                        if (a[i][j]==1) ans1+=(LL)du[k]-2;
                    }
            f[j][i]=f[i][j];
        }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (a[i][j]==1)
                for (int k=1;k<=n;k++)
                    if ((k!=i)&&(k!=j))
                    {
                        c1=f[i][k];
                        if (a[k][j]==1) c1--;
                        c2=f[j][k];
                        if (a[k][i]==1) c2--;
                        ans+=(LL)c1*c2;
                    }
    ans-=ans1;
    ans/=5;
    cout<<ans<<endl;

    return 0;
}