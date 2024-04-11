#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
const int MAX = 1000000009;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool is_pal(const string& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s;
    cin >> s;
    int n = s.size();
    
    bool eq = true;
    for (int i = 0; i < n; ++i) {
        if (n % 2 == 1 && i == n / 2) {
            continue;
        }
        if (s[i] != s[0]) {
            eq = false;
        }
    }
    if (eq) {
        cout << "Impossible\n";
        return 0;
    }
    
    for (int li = 1; li < n; ++li) {
        string s2 = s.substr(li, n - li) + s.substr(0, li);
        if (s2 != s && is_pal(s2)) {
            cout << "1\n";
            return 0;
        }
    }
    cout << "2\n";
    
    return 0;
}