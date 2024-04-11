#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a;
    if (k == 1) {
        cout << "YES\n";
        cout << n << "\n";
        return;
    }
    if (n % 2 == 0 && k % 2 == 1) {
        for (int i = 0; i < k - 1; ++i) {
            a.push_back(2);
            n -= 2;
        }
    } else {
        for (int i = 0; i < k - 1; ++i) {
            a.push_back(1);
            n -= 1;
        }
    }
    if (n <= 0 || n % 2 != a[0] % 2) {
        cout << "NO\n";
    } else {
        a.push_back(n);
        cout << "YES\n";
        for (int i = 0; i < k; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
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