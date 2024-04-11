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

#define maxlongint 2147483647
#define biglongint 2139062143


using namespace std;

int main()
{
    int n,m,xc,yc,zc,t,e,a[200][200],b[200][200],rc,fc,u[40000],biao[200];
    scanf("%d %d",&n,&m);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&xc,&yc,&zc);
        ++a[xc][0];
        a[xc][a[xc][0]]=yc;
        b[xc][a[xc][0]]=zc;
        ++a[yc][0];
        a[yc][a[yc][0]]=xc;
        b[yc][a[yc][0]]=zc;
    }
    memset(biao,0,sizeof(biao));
    for (int i=1;i<=n;i++)
        if (biao[i]==0)
        {
            rc=1;fc=1;u[rc]=i;biao[i]=1;
            while (rc<=fc)
            {
                for (int j=1;j<=a[u[rc]][0];j++)
                {
                    t=a[u[rc]][j];
                    if (b[u[rc]][j]==0)
                    {
                        if (biao[t]==0)
                        {
                            biao[t]=3-biao[u[rc]];
                            ++fc;u[fc]=t;
                        }
                        else
                            if (biao[t]!=3-biao[u[rc]])
                            {
                                cout<<"Impossible"<<endl;
                                return 0;
                            }
                    }
                    if (b[u[rc]][j]==1)
                    {
                        if (biao[t]==0)
                        {
                            biao[t]=biao[u[rc]];
                            ++fc;u[fc]=t;
                        }
                        else
                            if (biao[t]!=biao[u[rc]])
                            {
                                cout<<"Impossible"<<endl;
                                return 0;
                            }
                    }
                }
                ++rc;
            }
        }
    e=0;
    for (int i=1;i<=n;i++) if (biao[i]==1) ++e;
    cout<<e<<endl;
    for (int i=1;i<=n;i++) if (biao[i]==1) cout<<i<<" ";
    cout<<endl;

    return 0;
}