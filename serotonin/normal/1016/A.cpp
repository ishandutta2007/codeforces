#include <bits/stdc++.h>
using namespace std;
const int sz=2e5 + 5;

long long a[sz],ans[sz];

main()
{
    long long i,j,n,m,x=0,k;
    scanf("%I64d %I64d", &n, &m);
    for(i=0;i<n;i++) {
        scanf("%I64d", &a[i]);
        a[i]+=x;
        x=a[i];
        ans[i+1]=a[i]/m;
    }
    ans[0]=0;
    for(i=0;i<n;i++) {
        if(i<n-1) printf("%I64d ", ans[i+1]-ans[i]);
        else printf("%I64d\n", ans[i+1]-ans[i]);
    }
}