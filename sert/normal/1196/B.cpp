#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18 + 41;
const int N = (int)1e5;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int odd = 0;
    for (int &x : a) {
        cin >> x;
        odd += x % 2;
    }
    if (k % 2 != odd % 2 || odd < k) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i + 1 < n; i++) {
            if (k > 1 && a[i] % 2 == 1) {
                k--;
                cout << i + 1 << " ";
            }
        }
        cout << n << "\n";
   }
}

int main() {
    //freopen("a.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;   
}