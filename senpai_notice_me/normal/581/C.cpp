#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 100005

int n,k,sk[MAX_N],last=0,ans=0;

bool cnmp(int a,int b) {
    if (a%10==b%10) return a<b;
    return (a%10)>(b%10);
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",sk+i);
    sort(sk+1,sk+n+1,cnmp);
    for (int i=1;i<=n;i++) {
        if (k>=(10-sk[i]%10)) {
            k-=(10-sk[i]%10); sk[i]+=(10-sk[i]%10);
        }
        ans+=sk[i]/10; last+=(100-sk[i])/10;
    }
    k/=10;
    ans+=min(k,last);
    printf("%d",ans);
    return 0;
}