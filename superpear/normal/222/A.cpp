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

const int maxn=500000;
int n,k,rc,fc,a[maxn],hash[maxn];
int main()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(hash,0,sizeof(hash));
    for (int i=1;i<=n;i++) hash[a[i]]++;
    if (hash[a[1]]==n)
    {
        cout<<0<<endl;
        return 0;
    }
    rc=1;fc=n;
    for (int i=1;i<=3*n;i++)
    {
        ++fc;
        a[fc]=a[rc+k-1];
        --hash[a[rc]];++hash[a[fc]];
        ++rc;
        if (hash[a[fc]]==n)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}