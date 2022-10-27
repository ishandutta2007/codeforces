#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=300000+10;
int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    LL ans=0;
    for(int i=1;i<n;i++) {
        ans=ans+a[i];
    }
    for(int i=1;i<=n;i++) {
        ans=ans+1LL*a[i]*i;
    }
    cout<<ans<<endl;
}