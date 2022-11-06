#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 1e5+7, inf = -2e18;

ll a[sz], cum[sz];
vector <ll> w[66];

ll tree[sz*2];

ll query(int i, int j, int n)
{
    i += n;
    j += n;

    ll mi = inf;

    while (i < j) {
        if(i & 1) {
            mi = max(mi, tree[i]);
            i++;
        }

        if(j & 1) {
            j--;
            mi = max(mi, tree[j]);
        }

        i >>= 1;
        j >>= 1;
    }
    return mi;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        cum[i] = a[i] + cum[i-1];
        for(ll j=-30; j<=a[i]; j++) {
            w[j+30].push_back(i);
        }
    }

    for(int i=0; i<n; i++) tree[i+n] = cum[i+1];
    for(int i=n-1; i>=1; i--) tree[i] = max(tree[2*i], tree[2*i+1]);

    ll ans = 0;
    for(int i=1; i<=n; i++) {
        for(int k=i; k<=n; ) {
            int r = a[k] + 31;
            int pos = upper_bound(w[r].begin(), w[r].end(), k) - w[r].begin();
            if(pos == w[r].size()) pos = n+1;
            else pos = w[r][pos];

            ll mx = query(k-1, pos-1, n) - cum[i-1] - a[k];
            ans = max(ans, mx);
            k = pos;
        }
    }

    printf("%lld\n", ans);
}