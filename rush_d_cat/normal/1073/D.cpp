#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=200000+10;
LL T,s;int n,a[N];
int main() {
    scanf("%d%lld",&n,&T);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    LL ans=0;
    while(1) {
        LL nex=0,c=0;
        for(int i=1;i<=n;i++){
            if(nex+a[i]>T) continue;
            nex+=a[i]; c++;
        }
        if(nex==0)break;
        ans += (T/nex) * c; T%=nex;
    }
    printf("%lld\n", ans);
}