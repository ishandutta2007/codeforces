#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    
    if (a + b < n + m) {
        cout << "No\n";
        return;
    }
    ll mi = min(a, b);
    ll ma = max(a, b);
    ll del;
    del = min(ma - mi, n);
    ma -= del;
    n -= del;
    if (ma > mi) {
        if (mi < m) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    } else {
        del = min({n, m, ma});
        n -= del;
        m -= del;
        ma -= del;
        if (n == 0 && ma < m) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}

int main() {
   int t;
   cin >> t;
   for (int i = 0; i < t; ++i) {
       solve();
   }
   
   return 0;
}