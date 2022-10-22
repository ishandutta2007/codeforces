#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    string s;
    cin >> s;
    
    ll sum = 0;
    int lastmin = 0;
    int minu = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '+') {
            --minu;
        } else {
            ++minu;
            if (lastmin < minu) {
                lastmin = minu;
                sum += i + 1;
            }
        }
    }
    
    cout << sum + s.size() << "\n";
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