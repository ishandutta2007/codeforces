#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int n, q;
LL a[N],k[N];
int main() {
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]), a[i] += a[i-1];
    for (int i=1;i<=q;i++) scanf("%lld",&k[i]);

    LL sum = 0;
    for (int i = 1; i <= q; i ++) {
        sum += k[i];
        if (sum >= a[n]) {
            sum = 0;
            printf("%d\n", n);
            continue;
        }
        int pos = upper_bound(a+1, a+1+n, sum) - a - 1;
        //printf("sum = %lld\n", sum);
        printf("%d\n", n - pos);
    }

}