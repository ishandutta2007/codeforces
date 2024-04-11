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
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

int n,sc,ans;
int hash[1000005],next[100005],time[1000005],a[100005],f[4005][4005];

int main()
{
    scanf("%d",&n);
    memset(hash,0,sizeof(hash));
    memset(next,0,sizeof(next));
    memset(time,0,sizeof(time));
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        ++time[a[i]];
        if (hash[a[i]]!=0)
            next[hash[a[i]]]=i;
        hash[a[i]]=i;
    }
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            f[i][j]=2;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            sc=next[i];
            if (sc!=0)
            {
                if (sc>j)
                    f[j][sc]=max(f[j][sc],f[i][j]+1);
                else
                    f[sc][j]=max(f[sc][j],f[i][j]);
            }
        }
    ans=1;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            ans=max(ans,f[i][j]);
    for (int i=0;i<=1000000;i++) ans=max(ans,time[i]);
    printf("%d\n",ans);

    return 0;
}