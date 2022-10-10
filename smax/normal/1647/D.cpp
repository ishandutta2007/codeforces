#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long x) {
    for (long long p=2; p*p<=x; p++)
        if (x % p == 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long x, d;
        cin >> x >> d;
        
        if (x % (d * d) != 0) {
            cout << "NO\n";
            continue;
        }
        
        if (x / (d * d) % d != 0) {
            long long y = x / (d * d);
            cout << (isPrime(y) ? "NO" : "YES") << "\n";
            continue;
        }
        
        long long y = x;
        int parts = 0;
        while (y % d == 0) {
            y /= d;
            parts++;
        }
        if (!isPrime(y)) {
            cout << "YES\n";
            continue;
        }
        if (isPrime(d)) {
            cout << "NO\n";
            continue;
        }
        if (parts >= 4) {
            cout << "YES\n";
            continue;
        }
        
        // d, d, d, y
        assert(parts == 3);
        bool ok = false;
        for (long long i=2; i*i<=d; i++)
            if (d % i == 0)
                for (long long a : {i, d / i})
                    if (d * a * y % (d * d) != 0)
                        ok = true;
        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;
}