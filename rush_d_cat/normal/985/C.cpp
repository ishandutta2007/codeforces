#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=100000+10;
typedef long long LL;
int n,k,l;
int a[N];
int main() {
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n*k;i++) {
        scanf("%d",&a[i]);
    }
    int m=n*k;
    sort(a+1,a+1+m);
    int p = upper_bound(a+1,a+1+m,a[1]+l) - a - 1;
    // [1, p]
    int cnt=n-1; LL ans=a[1];
    for(int i=1;i<=p;) {
        int nex=i+k;
        if(cnt==0) break;
        if(nex+cnt-1<=p) {
            i=i+k, cnt--; ans+=a[i];
        } else {
            int r=p, l=p-cnt+1;
            if (l>i) {
                for(int j=l;j<=r;j++) ans+=a[j];
                cnt=0;
            } 
            break;
        }
    }
    if (cnt) ans=0;
    printf("%lld\n", ans);

}