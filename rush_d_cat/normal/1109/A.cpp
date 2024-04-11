#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int cnt[2][1<<20], n, a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]^=a[i-1];
    }
    cnt[0][0]=1;

    LL ans=0;
    for(int i=1;i<=n;i++){
        ans+=cnt[i%2][a[i]];
        cnt[i%2][a[i]]++;
    }
    cout<<ans<<endl;
}