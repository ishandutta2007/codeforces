#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5, inf=-2e9;

int a[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        ll ans1 = 0, cnt1 = 0;
        for(int i=0, k=0, v=inf; i<=n; i++) {
            int x = k & 1, y = a[i] > 0;
            if(x == y || i == n) {
                if(v ^ inf) ans1 += v, cnt1++;
                v = inf;
                k ^= 1;
            }
            v = max(v, a[i]);
        }

        ll ans2 = 0, cnt2 = 0;
        for(int i=0, k=0, v=inf; i<=n; i++) {
            int x = k & 1, y = a[i] > 0;
            if(x ^ y || i == n) {
                if(v ^ inf) ans2 += v, cnt2++;
                v = inf;
                k ^= 1;
            }
            v = max(v, a[i]);
        }

        ll ans;
        if(cnt1 > cnt2) ans = ans1;
        else if(cnt1 < cnt2) ans = ans2;
        else ans = max(ans1, ans2);
        printf("%lld\n", ans);
    }
}