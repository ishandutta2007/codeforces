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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(4, 0);
    while (a[3] == 0) {
        for (int i = 0; i < 4; ++i) {
            if (a[i] == 0) {
                a[i] = 4;
                break;
            } else if (a[i] == 4) {
                a[i] = 7;
                break;
            } else {
                a[i] = 4;
            }
        }
        int cur = 0;
        for (int i = 3; i >= 0; --i) {
            cur *= 10;
            cur += a[i];
        }
        if (n % cur == 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    
    return 0;
}