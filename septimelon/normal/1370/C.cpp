#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    
    bool win = (n != 1);
    if (n % 2 == 0) {
        if (n != 2) {
            if (n % 4 == 0) {
                while (n % 2 == 0) {
                    n /= 2;
                }
                if (n == 1) {
                    win = false;
                }
            } else {
                n /= 2;
                win = false;
                for (int i = 3; i * i <= n; i += 2) {
                    if (n % i == 0) {
                        win = true;
                        break;
                    }
                }
            }
        }
    }
    
    if (win) {
        cout << "Ashishgup\n";
    } else {
        cout << "FastestFinger\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}