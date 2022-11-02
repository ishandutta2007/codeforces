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
#include <string>

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;
const int bigp=1000000007;

int n,k,cs,a[10000],f[10000],ans[10000];

int pow(int a,int b)
{
    if (b==0) return 1;
    int d=pow(a,b/2);
    d=((long long)(d)*d)%bigp;
    if (b%2==1) d=((long long)(d)*a)%bigp;
    return d;
}

int c(int n,int k)
{
    int e=1;
    for (int i=n;i>=n-k+1;i--) e=((long long)(e)*i)%bigp;
    for (int i=1;i<=k;i++) e=((long long)(e)*pow(i,bigp-2))%bigp;
    return e;
}

int main()
{
    //freopen("C.in","r",stdin);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) f[n+1-i]=c(i+k-2,i-1);
    //for (int i=1;i<=n;i++) cout<<f[i]<<" "<<endl;
    memset(ans,0,sizeof(ans));
    for (int i=1;i<=n;i++)
    {
        for (int j=n-i+1;j<=n;j++)
        {
            cs=j-(n-i);
            ans[i]=(ans[i]+((long long)a[cs]*f[j]%bigp))%bigp;
        }
    }
    for (int i=1;i<n;i++) printf("%d ",ans[i]);printf("%d\n",ans[n]);

    return 0;
}