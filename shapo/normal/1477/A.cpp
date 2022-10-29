#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define pa pair
#define tu tuple

typedef uint32_t uint;
typedef int64_t ll;

typedef ve<int> vi;
typedef ve<vi> v2i;
typedef pa<int, int> pii;

ll
gcd(ll a, ll b)
{
    while (b) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int n;
        ll k;
        cin >> n >> k;
        ve<ll> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        ll diff = 0ll;
        for (int i = 1; i < n; ++i) {
            diff = gcd(diff, abs(x[i] - x[0]));
        }
        if (abs(x[0] - k) % diff == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}