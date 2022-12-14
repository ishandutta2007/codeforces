#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
long long t, n, a[N], Q[N], f[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) cin >> a[i];
        bool ok = (a[1] < a[n]);
        if (ok) cout << "YES\n"; else cout << "NO\n";
    }
}