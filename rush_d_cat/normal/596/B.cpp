#include <iostream>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
int n,a[N];
LL abss(LL x) {
    if(x<0) return -x; return x;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    LL ans=0;
    for(int i=1;i<=n;i++) ans += abss(a[i]-a[i-1]);
    cout<<ans<<endl;
}