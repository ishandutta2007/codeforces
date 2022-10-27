#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
int n, a[N];
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+2*n);
    long long ans = 1LL * (a[n]-a[1]) * (a[2*n] - a[n+1]);
    for(int i=2;i<=n;i++) {
        ans=min(ans, 1LL*(a[i+n-1]-a[i])*(a[2*n]-a[1]));
    }
    cout<<ans<<endl;
}