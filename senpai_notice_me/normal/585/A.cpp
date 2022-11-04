#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 4005
using std::max;
using std::min;

long long n,v[MAX_N],d[MAX_N],p[MAX_N];
bool outq[MAX_N];

int main() {
    scanf("%I64d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d%I64d%I64d",v+i,d+i,p+i);
    
    long long ans=0,out;
    for (int i=1;i<=n;i++) {
        if (outq[i]) continue;
        ans++; out=0;
        for (int j=i+1;j<=n;j++) {
            if (outq[j]) continue;
            p[j]-=max(v[i]--,0LL)+out;
            if (p[j]<0) out+=d[j], outq[j]=true;
        }
    }
    printf("%I64d\n",ans);
    for (int i=1;i<=n;i++) if (!outq[i]) printf("%d ",i);
    
    return 0;
}