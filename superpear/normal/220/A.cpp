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

#define maxlongint 2147483647

using namespace std;

int a[200000],b[200000],e,n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) b[i]=a[i];
    sort(b+1,b+n+1);
    e=0;
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i]) e++;
    if (e<=2) printf("YES\n"); else printf("NO\n");
    return 0;
}