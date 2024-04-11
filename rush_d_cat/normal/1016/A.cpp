#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
LL n,m,a[N],s[N];
int main() {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
        printf("%lld ", s[i]/m - s[i-1]/m);
    }
}