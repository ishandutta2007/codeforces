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

int n,xc,ans,cs;
int a[120000],b[120000];

int main()
{
    scanf("%d %d",&n,&xc);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ans=0;
    cs=1;
    for (int i=n;i>=1;i--)
    {
        while ((cs<=n)&&(b[i]+a[cs]<xc)) ++cs;
        if (cs<=n)
        {
            ++ans;
            ++cs;
        }
    }
    cout<<1<<" "<<ans<<endl;
    return 0;
}