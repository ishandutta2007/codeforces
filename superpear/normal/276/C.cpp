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

int n,q,data[200005],f[200005],xc,yc;

int main()
{
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&data[i]);
    memset(f,0,sizeof(f));
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc]++;
        if (yc<n) f[yc+1]--;
    }
    for (int i=2;i<=n;i++) f[i]=f[i-1]+f[i];
    sort(f+1,f+n+1);
    sort(data+1,data+n+1);
    LL ans=0;
    for (int i=1;i<=n;i++) ans+=(LL)f[i]*data[i];
    printf("%I64d\n",ans);

    return 0;
}