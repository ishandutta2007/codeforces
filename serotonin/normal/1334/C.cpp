#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

typedef pair <ll,int> pii;
#define x first
#define y second

ll a[sz], b[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%lld %lld", &a[i], &b[i]);
        ll tot = a[0];
        for(int i=1; i<n; i++) {
            tot += max(0LL, a[i] - b[i-1]);
        }

        ll ans = tot;
        for(int i=1; i<n; i++) {
            tot += a[i] - a[i-1];
            if(i == 1) tot += max(0LL, a[0] - b[n-1]);
            else tot += max(0LL, a[i-1] - b[i-2]);
            tot -= max(0LL, a[i] - b[i-1]);
            ans = min(ans, tot);
        }

        printf("%lld\n", ans);
    }
}