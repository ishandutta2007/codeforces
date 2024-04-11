#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll k;
    cin >> k;
    vector<int> ans(10, 1);
    string cf = "codeforces";
    
    int ci = 0;
    ll cur = 1;
    while (cur < k) {
        cur /= ans[ci];
        ++ans[ci];
        cur *= ans[ci];
        ci = (ci + 1) % 10;
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < ans[i]; ++j) {
            cout << cf[i];
        }
    }
    cout << "\n";
    
    return 0;
}