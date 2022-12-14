#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        if (k > (n + 1) / 2) {
            cout << "-1\n";
        }
        else {
            for (int i = 0; i < n; i += 1) {
                for (int j = 0; j < n; j += 1) {
                    if (i == j and i % 2 == 0 and i / 2 < k) cout << 'R';
                    else cout << ".";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}