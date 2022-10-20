// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int M = 1000000007;

int ask(int w) {
    cout << "? " << w << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int ng = 0, ok = n * 2010;
    while (ng + 1 < ok) {
        int m = (ng + ok) / 2;
        int res = ask(m);
        if (res == 1) {
            ok = m;
        }
        else {
            ng = m;
        }
    }
    int ans = ok;
    for (int i = 2; i <= n; ++i) {
        int r = (ok - 1) / i;
        int l = ok / i;
        if (l <= r && l > 0) {
            int t = ask(l);
            if (t != 0)
                ans = min(ans, t * l);
        }
    }
    cout << "! " << ans << '\n';


    return 0;
}