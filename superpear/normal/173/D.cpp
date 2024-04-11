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

const int maxn=100005;
vector<int> f[maxn],g[maxn];
int n,m,xc,yc,rc,fc,cs,o,size1,size2,ct,lou1,lou2;
int which[maxn],u[maxn],biao[maxn],vis[maxn];

int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>xc>>yc;
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }
    memset(which,0,sizeof(which));
    for (int i=1;i<=n;i++)
        if (which[i]==0)
        {
            which[i]=1;
            rc=1;fc=1;u[rc]=i;
            while (rc<=fc)
            {
                for (int j=0;j<f[u[rc]].size();j++)
                {
                    cs=f[u[rc]][j];
                    if (which[cs]==0)
                    {
                        which[cs]=3-which[u[rc]];
                        ++fc;u[fc]=cs;
                    }
                }
                ++rc;
            }
        }
    size1=0;size2=0;
    for (int i=1;i<=n;i++) if (which[i]==1) ++size1; else ++size2;
    if (size1%3==0)
    {
        o=0;
        for (int i=1;i<=n;i++)
            if (which[i]==1) biao[i]=o/3+1,++o;
        for (int i=1;i<=n;i++)
            if (which[i]==2) biao[i]=o/3+1,++o;
        cout<<"YES"<<endl;
        for (int i=1;i<=n;i++) cout<<biao[i]<<" ";cout<<endl;
        return 0;
    }
    if (size1%3==2)
    {
        swap(size1,size2);
        for (int i=1;i<=n;i++) which[i]=3-which[i];
    }
    ct=-1;
    for (int i=1;i<=n;i++)
        if ((which[i]==1)&&(size2-f[i].size()>=2)) {ct=i;break;}
    if (ct!=-1)
    {
        memset(vis,0,sizeof(vis));
        for (int i=0;i<f[ct].size();i++) vis[f[ct][i]]=1;
        lou1=-1;lou2=-1;
        for (int i=1;i<=n;i++)
            if ((which[i]==2)&&(vis[i]==0))
            {
                if (lou1==-1) lou1=i; else lou2=i;
            }
        o=3;
        biao[ct]=1;biao[lou1]=1;biao[lou2]=1;
        for (int i=1;i<=n;i++)
            if ((which[i]==1)&&(biao[i]==0)) biao[i]=o/3+1,++o;
        for (int i=1;i<=n;i++)
            if ((which[i]==2)&&(biao[i]==0)) biao[i]=o/3+1,++o;
        cout<<"YES"<<endl;
        for (int i=1;i<=n;i++) cout<<biao[i]<<" ";cout<<endl;
        return 0;
    }
    int ef=0,qq[maxn];
    for (int i=1;i<=n;i++) if (which[i]==2) ++ef,qq[ef]=i;
    for (int i=1;i<=n;i++)
        if (which[i]==1)
        {
            for (int j=1;j<=size2;j++) vis[qq[j]]=0;
            for (int j=0;j<f[i].size();j++) vis[f[i][j]]=1;
            for (int j=1;j<=size2;j++) if (vis[qq[j]]==0) g[qq[j]].p_b(i);
        }
    o=0;
    for (int i=1;i<=n;i++)
    {
        if (o==6) break;
        if ((which[i]==2)&&(g[i].size()>=2))
        {
            o+=3;biao[i]=o/3;biao[g[i][0]]=o/3;biao[g[i][1]]=o/3;
        }
    }
    if (o!=6)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
        if ((which[i]==1)&&(biao[i]==0)) biao[i]=o/3+1,++o;
    for (int i=1;i<=n;i++)
        if ((which[i]==2)&&(biao[i]==0)) biao[i]=o/3+1,++o;
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++) cout<<biao[i]<<" ";cout<<endl;

    return 0;
}