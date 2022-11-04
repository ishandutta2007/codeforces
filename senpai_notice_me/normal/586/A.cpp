#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int n,num[105],ans=0;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",num+i);
    for (int i=1;i<=n;i++) {
        if (num[i]==1 ||(num[i]==0 && num[i-1]==1 && num[i+1]==1)) ans++;
    }
    printf("%d",ans);
    
    return 0;
}