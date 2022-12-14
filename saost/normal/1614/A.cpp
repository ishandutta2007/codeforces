#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, l, r, k, a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        int res = 0;
        cin >> n >> l >> r >> k;
        for(int i=1; i<=n; ++i) cin >> a[i];
        sort(a+1, a+n+1);
        for(int i=1; i<=n; ++i) {
            if (l <= a[i] && a[i] <= r && a[i] <= k) k -= a[i], ++res;
        }
        cout << res << '\n';
    }
}