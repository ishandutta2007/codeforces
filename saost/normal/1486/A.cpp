#include <iostream>

using namespace std;
long long n, t, x, old;

int main()
{
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        bool ok = true;
        old = 0;
        for(int i=0; i<n; i++) {
            scanf("%lld", &x);
            old += x;
            if (old < i) ok = false;
            old = max(0ll, old - i);
        }
        if (ok) cout << "YES\n"; else cout << "NO\n";
    }
}