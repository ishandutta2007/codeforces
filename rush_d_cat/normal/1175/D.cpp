#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=300000+10;
int n,k; LL a[N];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=n;i>=1;i--)a[i]+=a[i+1];
    LL ans=a[1];
    sort(a+2,a+1+n);
    for(int i=n;i>n-k+1;i--){
        ans+=a[i];
    }
    cout<<ans<<endl;
}