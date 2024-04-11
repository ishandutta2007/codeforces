#include <iostream>
#include <algorithm>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
using namespace std;
long long t, n, d, x, val, a[200005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n; n*=2;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+n+1);
        bool ok = true;
        long long sum = 0;
        for(int i=2; i<n; i+=2) {
            if (a[i] != a[i-1] || a[i+2] == a[i] || (a[i+2] - a[i])%i != 0) { ok = false; break; }
            sum += (a[i+2] - a[i])/i;
            if (sum >= a[n]/n) { ok = false; break; }
        }
        if (a[n] != a[n-1]) ok = false;
        if ((a[n]%n)!=0)
            ok = false;
        if (ok) cout << "YES\n"; else cout << "NO\n";
    }
}