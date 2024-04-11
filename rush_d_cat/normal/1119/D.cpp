#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 300000+10;
int n,q;
LL s[N],a[N],pre[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
    }
    sort(s+1,s+1+n);
    int tot=1; a[1]=1e18+1;
    for(int i=2;i<=n;i++){
        if(s[i]!=s[i-1]) a[++tot]=s[i]-s[i-1]-1;
    }
    sort(a+1,a+1+tot);
    for(int i=1;i<=tot;i++){
        pre[i]=pre[i-1]+a[i];
    }

    scanf("%d",&q);
    //printf("tot=%lld\n", tot);
    while(q--) {
        LL l,r; scanf("%lld%lld",&l,&r);
        r -= l;
        int pos = upper_bound(a+1,a+1+tot,r) - a - 1;
        //printf("pos = %d\n", pos);
        LL ans=tot + pre[pos] + (tot-pos)*r;
        printf("%lld ", ans);
    }
}