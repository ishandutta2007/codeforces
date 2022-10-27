#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 300000+10;
typedef long long LL;
int n;LL a[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    LL pre=0, ans=0;
    for(int i=1;i<=n;i++){
        LL p2=min(pre,a[i]/2);
        ans+=p2; a[i]-=p2*2; pre-=p2;
        LL p3=a[i]/3;
        ans+=p3; a[i]-=p3*3;
        pre+=a[i];
    }
    cout<<ans<<endl;
}