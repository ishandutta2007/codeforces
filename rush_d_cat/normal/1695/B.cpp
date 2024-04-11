#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 10000 + 10;
int a[42][42];
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i ++) cin >> a[i];
        if (n % 2 == 1) {
            cout << "Mike\n"; 
        } else {
            const ll inf = 1e18;
            long long g1 = inf, g2 = inf;
            for (int i = 0; i < n; i ++) {
                if (i % 2 == 0) {
                    g1 = min(g1, 1ll * a[i] * 100 + i);
                } else {
                    g2 = min(g2, 1ll * a[i] * 100 + i);
                }
            }
            cout << (g1 < g2 ? "Joe" : "Mike") << "\n";
        }
    }
}