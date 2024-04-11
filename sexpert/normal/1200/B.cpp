#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(int i = 0; i < n - 1; i++) {
        if(v[i] >= v[i + 1] - k)
            m += v[i] - max(v[i + 1] - k, 0);
        else {
            m -= (v[i + 1] - k - v[i]);
            if(m < 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}