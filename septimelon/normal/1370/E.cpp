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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    int s0t1 = 0, s1t0 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (s[i] == '1') {
                ++s1t0;
            } else {
                ++s0t1;
            }
        }
    }
    if (s1t0 != s0t1) {
        cout << "-1\n";
        return 0;
    }
    
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (s[i] == '0') {
                if (c1 != 0) {
                    --c1;
                }
                ++c0;
            } else {
                if (c0 != 0) {
                    --c0;
                }
                ++c1;
            }
        }
    }
    
    cout << c0 + c1 << "\n";
    
    return 0;
}