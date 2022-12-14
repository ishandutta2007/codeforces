#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long t, n, a[N], f[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n*4; ++i) cin >> a[i];
        sort(a+1, a+n*4+1);
        long long ans = a[1] * a[n*4];
        int i;
        for(i=1; i<=n*2; i+=2) {
            if (a[i] != a[i+1] || a[n*4-i] != a[n*4-i+1]) break;
            long long a2 = a[i] * a[n*4-i+1];
            if (ans != a2) {
                break;
            }
        }
        if (i > n*2) cout << "YES\n"; else cout << "NO\n";
    }
}