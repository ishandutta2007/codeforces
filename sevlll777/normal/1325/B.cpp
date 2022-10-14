#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> lol;
        for (int i = 0; i < n; i++) {
            int y;
            cin >> y;
            lol.insert(y);
        }
        cout << lol.size() << '\n';
    }
}