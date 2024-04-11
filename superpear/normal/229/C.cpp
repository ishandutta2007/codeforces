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

int n,m,du[1200000];

int main()
{
    int x1,y1;
    scanf("%d %d",&n,&m);
    memset(du,0,sizeof(du));
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&x1,&y1);
        ++du[x1];++du[y1];
    }
    long long ans1,ans2,ans3;
    ans1=(long long)n*(n-1)*(n-2)/6;
    ans2=(long long)m*(n-2);
    ans3=0;
    for (int i=1;i<=n;i++)
        ans3+=(long long)du[i]*(du[i]-1)/2;
    cout<<ans1-ans2+ans3<<endl;

    return 0;
}