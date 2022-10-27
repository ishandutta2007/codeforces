#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
const LL MOD = 998244353;
map<LL,int> mp, bu;
LL gcd(LL x, LL y) {
    return y==0?x:gcd(y,x%y);
}
int n; LL a[N]; bool ok[N];
LL sqrt4(LL x) {
    LL t=sqrt(sqrt(x));
    for(LL i=max(t-4,1LL);i<=t+4;i++) {
        if(i*i*i*i==x) return i;
    }
    return 0;
}
LL sqrt2(LL x) {
    LL t = sqrt(x);
    for(LL i=max(t-4,1LL);i<=t+4;i++) {
        if(i*i==x) return i;
    }
    return 0;
}
LL sqrt3(LL x) {
    LL t = pow(x, 1.0/3);
    for(LL i=max(t-4,1LL);i<=t+4;i++) {
        if(i*i*i==x) return i;
    }
    return 0;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        if (sqrt4(a[i])) {
            mp[sqrt4(a[i])] += 4; ok[i] = 1;
        } else if(sqrt2(a[i])) {
            mp[sqrt2(a[i])] += 2; ok[i] = 1;
        } else if(sqrt3(a[i])) {
            mp[sqrt3(a[i])] += 3, ok[i] = 1;
        }
    }

    LL ans = 1;
    for(int i=1;i<=n;i++) {
        if(ok[i]) continue;
        LL p = -1;
        for(int j=1;j<=n;j++) if(i!=j){
            LL g = gcd(a[i],a[j]);
            if (g == 1) continue;
            if (g != a[i]) {
                p = g; break;
            }
        }
        if (p != -1) mp[p] ++, mp[a[i]/p] ++;
        else bu[a[i]] ++;
    }
    for(auto p: mp) {
        ans = ans * (p.second + 1) % MOD;
    }
    for(auto p: bu) {
        ans = ans * (p.second + 1) % MOD * (p.second + 1) % MOD;
    }
    cout << ans << endl;
}