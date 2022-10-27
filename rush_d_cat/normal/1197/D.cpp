#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
LL n,m,k,a[N];
LL s[N],pre[N][12];
int main() {
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
        if(i>=m) pre[i][i%m] = min(pre[i-m][i%m], s[i] - k * (i / m));
        else pre[i][i%m] = s[i] - k * (i / m);
    }

    LL res=0;
    for(LL r=1;r<=n;r++) {
        LL tmp = s[r] - k * (r/m);
        LL mn = 1e18;
        for(int j=r-1;j>=max(r-m,0LL);j--) {
            if(j%m >= r%m) {
                mn = min(mn, pre[j][j%m]);
            } else {
                mn = min(mn, pre[j][j%m] + k);
            }
        }
        res = max(res, tmp - mn);
    }
    cout << res << endl;
}
/*
s[r] - s[l-1] - k * (r-(l-1))/m


r%m > (l-1)%m
: (r-(l-1))/m = r/m - (l-1)/m + 1

r%m <= (l-1)%m
: (r-(l-1))/m = r/m - (l-1)/m

(s[r] - k * r / m) - (s[l-1] - k * (l-1) / m)
*/