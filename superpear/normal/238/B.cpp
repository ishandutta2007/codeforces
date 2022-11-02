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
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

int n,h,c,cs,minc,mine,maxe;
int a[200000],where[200000],nowans[200000];
pair<int,int> b[200000];

int main()
{
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
    scanf("%d %d",&n,&h);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&cs);
        b[i]=make_pair(cs,i);
    }
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++) a[i]=b[i].first;
    minc=abs(a[1]+a[2]-a[n]-a[n-1]);
    for (int i=1;i<=n;i++) nowans[i]=1;
    c=min(n,4);
    for (int i=0;i<=((1<<c)-1);i++)
    {
        memset(where,0,sizeof(where));
        for (int j=1;j<=c;j++) where[j]=(i>>(j-1))%2+1;
        mine=maxlongint;
        maxe=a[n]+a[n-1];
        for (int j=1;j<=c;j++)
            for (int k=j+1;k<=c;k++)
                if (where[j]!=where[k]) mine=min(mine,a[j]+a[k]+h),maxe=max(maxe,a[j]+a[k]+h);
                                   else mine=min(mine,a[j]+a[k]),maxe=max(maxe,a[j]+a[k]);
        for (int j=1;j<=c;j++)
            for (int k=c+1;k<=n;k++)
                if (where[j]!=1) maxe=max(maxe,a[j]+a[k]+h),mine=min(mine,a[j]+a[k]+h);
                            else maxe=max(maxe,a[j]+a[k]),mine=min(mine,a[j]+a[k]);
        if (maxe-mine<minc)
        {
            minc=maxe-mine;
            for (int j=1;j<=c;j++) nowans[b[j].second]=where[j];
            for (int j=c+1;j<=n;j++) nowans[b[j].second]=1;
        }
    }
    printf("%d\n",minc);
    for (int i=1;i<=n;i++) printf("%d ",nowans[i]);
    printf("\n");

    return 0;
}