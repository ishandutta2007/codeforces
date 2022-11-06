#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

ll a[sz], cum[sz];

int main()
{
    int t=1;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
        for(int i=1; i<=n; i++) cum[i] = cum[i-1] + a[i];
        map <ll,int> mp;
        ll ans = 0;
        for(int i=n, j=n+1; i; i--) {
            mp[cum[i]] = i;
            if(mp.find(cum[i-1])!=mp.end()) j = min(j, mp[cum[i-1]]);
            ans += j-i;
        }
        printf("%lld\n", ans);
    }
}