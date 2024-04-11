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

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

int n,ans;
int a[120000],b[120000],f[120000];
int main()
{
    ans=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d %d",&a[i],&b[i]);
    f[1]=1;
    for (int i=2;i<=n;i++)
    {
        if ((a[i]==a[i-1])&&(b[i]==b[i-1])) f[i]=f[i-1]+1; else f[i]=1;
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;

    return 0;
}