#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> X(n), Y(n);
        for (int i = 0; i < n; i++) cin >> X[i] >> Y[i];
        bool can = false;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (abs(X[i]-X[j])+abs(Y[i]-Y[j])>k) ok =false;
            }
            if (ok) can=true;
        }
        if (!can) cout << '-';
        cout << 1;
        cout << '\n';
    }
}