#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        cout << ((min(a, b) >= m && a + b >= n + m) ? "Yes" : "No") << '\n';
    }
}