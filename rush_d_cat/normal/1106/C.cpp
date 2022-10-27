#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int a[N], n;
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    LL ans=0;
    for(int i=1;i<=n/2;i++) {
        ans = ans +  1LL*(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    }
    cout << ans << endl;
}