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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

vector<int> f[120000];
int n,m,h,t,flag,o,x[120000],y[120000],biao[120000],hash[120000];

void check(int u,int v)
{
    int o1=0,o2=0,o3=0,ee;
    for (int i=0;i<f[u].size();i++)
    {
        if (f[u][i]==v) continue;
        ++o1;
        hash[f[u][i]]=o;
        if (o1==(h+t)) break;
    }
    for (int i=0;i<f[v].size();i++)
    {
        if (f[v][i]==u) continue;
        ++o2;
        if (hash[f[v][i]]==o) ++o3,hash[f[v][i]]=o+2; else hash[f[v][i]]=o+1;
        if (o2==(h+t)) break;
    }
    o1-=o3;o2-=o3;
    if (max(0,h-o1)+max(0,t-o2)<=o3)
    {
        cout<<"YES"<<endl;
        flag=0;
        memset(biao,0,sizeof(biao));
        ee=0;
        for (int i=1;i<=n;i++)
        {
            if (hash[i]==o) biao[i]=1;
            if (hash[i]==o+1) biao[i]=2;
            if (hash[i]==o+2)
            {
                if (ee<max(0,h-o1))
                {
                    ++ee;biao[i]=1;
                }
                else biao[i]=2;
            }
        }
        cout<<u<<" "<<v<<endl;
        ee=0;
        for (int i=1;i<=n;i++)
            if (biao[i]==1)
            {
                cout<<i<<" ";
                ++ee;
                if (ee==h) break;
            }
        cout<<endl;
        ee=0;
        for (int i=1;i<=n;i++)
            if (biao[i]==2)
            {
                cout<<i<<" ";
                ++ee;
                if (ee==t) break;
            }
        cout<<endl;
    }
    o+=3;
}

int main()
{
    scanf("%d %d %d %d",&n,&m,&h,&t);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        f[x[i]].push_back(y[i]);
        f[y[i]].push_back(x[i]);
    }
    memset(hash,0,sizeof(hash));
    flag=1;o=1;
    for (int i=1;i<=m;i++)
    {
        if (flag==1) check(x[i],y[i]);
        if (flag==1) check(y[i],x[i]);
    }
    if (flag==1) cout<<"NO"<<endl;

    return 0;
}