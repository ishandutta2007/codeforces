#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100000 + 10;
int n,k,m,a[N];

int main() {
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);

    double sum=0,ans=0;
    for(int i=n;i>=1;i--) {
        sum += a[i];
        if (m >= i-1) {
            int A = m-(i-1);
            int B = n-(i-1);
            ans = max(ans, (sum + min(1LL*B*k, 1LL*A)) / B );
        }
    }
    printf("%.9f\n", ans);
}