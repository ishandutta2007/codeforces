#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 998244353;

ll am(ll a, ll b) {
    return (a + b) % MOD;
}

ll mm(ll a, ll b) {
    return (a * b) % MOD;
}

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f1 = s.size();
    int l0 = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            l0 = i;
        } else if (f1 == s.size()) {
            f1 = i;
        }
    }
    for (int i = 0; i < f1; ++i) {
        cout << s[i];
    }
    for (int i = f1; i <= l0; ++i) {
        if (s[i] == '0' && s[i - 1] == '1') {
            cout << '0';
            break;
        }
    }
    for (int i = l0 + 1; i < s.size(); ++i) {
        cout << s[i];
    }
    cout << "\n";
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