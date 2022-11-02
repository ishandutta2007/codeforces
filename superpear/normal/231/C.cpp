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

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

long long sum[120000],cs;
int n,k,maxc,maxk,a[120000];

int main()
{
    int left,right,mid;
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    maxc=0;maxk=maxlongint;
    sum[0]=0;
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=n;i++)
    {
        left=1;right=i;
        while (left<=right)
        {
            mid=(left+right)/2;
            cs=(long long)a[i]*(i-mid+1)-sum[i]+sum[mid-1];
            if (cs<=k) right=mid-1; else left=mid+1;
        }
        if (i-left+1>maxc)
        {
            maxc=i-left+1;maxk=a[i];
        }
    }
    cout<<maxc<<" "<<maxk<<endl;

    return 0;
}