#include <bits/stdc++.h>
using namespace std;
long long n, q, att, def, sum, a[200005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], sum += a[i];
    sort(a+1, a+n+1);
    cin >> q;
    while (q--) {
        cin >> def >> att;
        int x = lower_bound(a+1, a+n, def) - a;
        long long res = max(0LL, att - sum + a[x]) + max(0LL, def - a[x]);
        if (x > 1) --x;
        long long res2 = max(0LL, att - sum + a[x]) + max(0LL, def - a[x]);
        cout << min(res, res2) << '\n';
    }
}