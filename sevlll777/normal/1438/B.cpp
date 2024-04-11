#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> B(n);
        for (int i = 0; i < n; i++) cin >> B[i];
        set<int> kek;
        for (auto x : B) kek.insert(x);
        if (kek.size() == n) {
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << '\n';
    }
}