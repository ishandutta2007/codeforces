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

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

double p[120000],f[120000],g[120000];
int n;
double ans;

int main()
{
    cin>>n;
    p[0]=0;g[0]=0;
    for (int i=1;i<=n;i++) cin>>p[i];
    ans=0;
    f[0]=0;
    for (int i=1;i<=n;i++)
    {
        f[i]=(f[i-1]+g[i-1]*2+(1-p[i-1]))*p[i];
        g[i]=g[i-1]*p[i]+p[i]*(1-p[i-1]);
    }
    for (int i=1;i<=n;i++) ans=ans+f[i];
    printf("%.10lf\n",ans);

    return 0;
}