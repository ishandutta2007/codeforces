#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,a[505];
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    if (n==1) {printf("%d\n",a[0]);return 0;}
    int t=a[1]-a[0];bool f=true;
    for (int i=1;i+1<n;i++) if (a[i+1]-a[i]!=t) f=false;
    if (f) printf("%d\n",a[n-1]+t); else printf("%d\n",a[n-1]);
    return 0;
}