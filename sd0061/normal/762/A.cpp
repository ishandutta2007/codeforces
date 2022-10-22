#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n , K , i;
    cin >> n >> K;
    for (i = 1 ; i * i <= n ; ++ i) {
        if (n % i == 0) {
            if (!-- K) {
                cout << i << endl;
                return 0;
            }
        }
    }
    -- i; if (i * i == n) -- i;
    while (i > 0) {
        if (n % i == 0) {
            if (!-- K) {
                cout << n / i << endl;
                return 0;
            }
        }
        -- i;
    }
    cout << -1 << endl;
}