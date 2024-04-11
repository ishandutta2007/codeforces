#include <iostream>
using namespace std;
typedef unsigned long long LL;
const int N=3000000+10;
LL n, k;
LL a[N],nex[N];
LL ans=0;

int main() {
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        //a[i]=3;
    }
    nex[n]=n+1;
    for(int i=n-1;i>=1;i--) {
        if(a[i+1]>1) nex[i]=i+1;
        else nex[i]=nex[i+1];
    }
    for(int i=1;i<=n;i++){
        LL now=i;
        LL pro=a[i], sum=a[i]; 
        if(k==1) ans++;
        for(int cnt=1;cnt<=62;cnt++) {
            LL cnt_of_1 = nex[now] - now - 1;
            if (pro % k == 0 && sum < (pro / k) && sum+cnt_of_1 >= pro / k) ans ++;

            now = nex[now];
            if (now == n+1) break;
            if (pro > 2e18/a[now] + 1) break;
            sum += cnt_of_1+a[now];
            pro *= a[now];
            if ((pro % sum == 0) && (pro / sum == k)) ans ++;
        }
    }
    printf("%lld\n", ans);
}