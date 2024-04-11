#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> count(21, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < 21; ++j) {
            if (a % 2 == 1) {
                ++count[j];
            }
            a /= 2;
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll cur = 0;
        for (int j = 20; j >= 0; --j) {
            cur *= 2;
            if (count[j] > 0) {
                --count[j];
                ++cur;
            }
        }
        ans += cur * cur;
    }
    
    cout << ans << "\n";
    
    return 0;
}