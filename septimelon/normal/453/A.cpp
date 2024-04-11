#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

void solve() {
    int m, n;
    cin >> m >> n;
    ld ans = m;
    for (int i = m - 1; i > 0; --i) {
        ld d = i;
        d /= m;
        ans -= pow(d, n);
    }
    cout << setprecision(10) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}