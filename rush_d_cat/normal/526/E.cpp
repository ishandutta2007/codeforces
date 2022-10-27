#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1000000+ 10;

int n,q,b; LL a[N];
LL nex[N],cnt[N],sum[N];
LL ans;
void solve(){
    nex[n+1]=n+1,cnt[n+1]=0;
    for(int lef=n,rig=n;lef>=1;lef--){
        if(sum[n]-sum[lef-1] <= b) {
            nex[lef]=lef,cnt[lef]=0; continue;
        }
        while(rig>=1 && sum[rig]-sum[lef-1] > b) rig--;
        nex[lef] = nex[rig+1];
        cnt[lef] = cnt[rig+1] + 1;
    }
    for(int i=1;i<=n;i++){
        //printf("i=%d, nex=%d, cnt=%d\n", i,nex[i],cnt[i]);
        if(sum[i-1]<=b){
            int c1 = cnt[i];
            LL s = sum[i-1] + sum[n] - sum[nex[i]-1];
            if(s <= b) c1 ++; else c1 += 2;
            ans = min(ans, (LL)c1);
        }
    }
}

int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    while(q--){
        scanf("%d",&b);
        ans=n;
        solve();
        cout<<ans<<endl;
    }
}