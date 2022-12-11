#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 41;
typedef long long ll;


void solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << (b - a + 9) / 10 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
    t = 4;
#else

#endif
    cin >> t;
    while (t--) {
        solve();
    }
}