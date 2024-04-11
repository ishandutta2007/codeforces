#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,k,a[N],pre[N];
map<int,int> mp;
int main() {
    scanf("%d%d",&n,&k);
    int all = (1<<k)-1; 
    mp[0]++;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]); pre[i]=pre[i-1]^a[i];
        mp[min(pre[i],all^pre[i])] ++;
    }
    LL ans = (LL)n*(n+1)/2;
    for(auto p: mp) {
        LL c = p.second / 2;
        LL d = p.second - c;
        ans -= (c*(c-1)/2 + d*(d-1)/2);
    }
    cout<<ans<<endl;
}