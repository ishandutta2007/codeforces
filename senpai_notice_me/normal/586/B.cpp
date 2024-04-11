#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
using std::min;

int n,e[105][105],ans=0;

int road(int i,int j) {
    int ret=0;
    for (int k=i;k<j;k++) ret+=e[k][k+1];
    return ret;
}

int main() {
    
    scanf("%d",&n);
    for (int i=1;i<n;i++)
        scanf("%d",&e[i-1][i]);
    for (int i=1;i<n;i++)
        scanf("%d",&e[i-1+n][i+n]);
    for (int i=0;i<n;i++)
        scanf("%d",&e[i][i+n]);
    
    int Min=0;
    for (int i=1;i<n;i++)
        if (road(0,i)+e[i][i+n]+road(i+n,n+n-1)<road(0,Min)+e[Min][Min+n]+road(Min+n,n+n-1)) Min=i;
    ans+=road(0,Min)+e[Min][Min+n]+road(Min+n,n+n-1);
    
    e[Min][Min+n]=1e8; Min=0;
    
    for (int i=1;i<n;i++)
        if (road(0,i)+e[i][i+n]+road(i+n,n+n-1)<road(0,Min)+e[Min][Min+n]+road(Min+n,n+n-1)) Min=i;
    ans+=road(0,Min)+e[Min][Min+n]+road(Min+n,n+n-1);
    
    printf("%d",ans);
    
    return 0;
}