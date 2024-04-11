#include <stdio.h>

int a[300000];
int n;

int FABS(int x) {
    if(x<0) return -x;
    return x;
}
int main() {
    ///freopen("2.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    long long ans = 0;
    for(int i=n-1;i;i--) {
        ans+=FABS(a[i]-a[i+1]);
    }
    ans+=FABS(a[1]);
    printf("%I64d\n",ans);
}