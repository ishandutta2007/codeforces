#include <iostream>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
LL a[N],x[N],y[N],b[N],t; int n;
int main() {
    scanf("%d%lld",&n,&t);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]); a[n+1]=2e18+1;
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1;i<n;i++) {
        if (x[i]>x[i+1]) return !printf("No\n");
    }
    for(int i=1;i<=n;i++) {
        if (x[i]<i) return !printf("No\n");
    }
    a[n+1]=2e18;
    for(int i=1;i<=n;i++) b[i]=a[i+1]; // b[i]>=a[i+1]
    for(int i=1;i<=n;i++) b[x[i]] = a[x[i]+1]-1; // b[x[i]]<a[x[i]+1]
    for(int i=n;i>=1;i--) {
        if(b[i]==a[i+1]-1) {
            y[i]=i;
        } else {
            y[i]=y[i+1];
        }
        if(x[i]!=y[i]) return !printf("No\n");
    }
    b[n+1]=2e18+1;
    for(int i=n;i>=1;i--) {
        if(b[i]==a[i+1]) {
            b[i]=b[i+1]-1;
            if(b[i]<a[i+1]) return !printf("No\n");
        } else {
            if(b[i+1]<=b[i]) return !printf("No\n");
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++) printf("%lld ", b[i]+t);
}