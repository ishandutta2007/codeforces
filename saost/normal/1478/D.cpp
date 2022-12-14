#include <iostream>
#include <algorithm>
#define FOR(i,l,r) for(int i=l; i<=r; i++)
using namespace std;
long long t, n, d, x, val, a[200005];

long long ff(long long x, long long mod) {
    if (x%mod == 0) return 0;
    if (x<0) return mod + x%mod;
    else return x%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> d;
        FOR(i, 1, n) cin >> a[i];
        sort(a+1, a+n+1);
        val = a[2] - a[1];
        FOR(i, 3, n) val = __gcd(val, a[i] - a[i-1]);
        if (ff(d, val) != ff(a[1], val)) cout << "NO\n";
        else cout << "YES\n";
    }
}