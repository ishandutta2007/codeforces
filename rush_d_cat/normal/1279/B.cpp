#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
typedef long long LL;
int t,n,s;
LL pre[N],a[N];
pair<LL,int> mx[N];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&s);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            pre[i]=a[i]+pre[i-1];
            mx[i]=max(mx[i-1],make_pair(a[i],i));
        }
        if(pre[n]<=s) {
            printf("0\n"); continue;
        }
        int ans=0;
        for(int i=n;i>=1;i--){
            if(pre[i]>s && pre[i] - mx[i].first <= s) {
                ans = mx[i].second;
            }
        }
        printf("%d\n", ans);
    }
}