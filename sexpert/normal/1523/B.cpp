#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto &x : v)
            cin >> x;
        cout << 6 * (n / 2) << '\n';
        for(int i = 1; i <= n; i += 2) {
            for(int it = 0; it < 2; it++) {
                cout << "2 " << i << " " << i + 1 << '\n';
                cout << "1 " << i << " " << i + 1 << '\n';
                cout << "2 " << i << " " << i + 1 << '\n';
            }
        }
    }
}