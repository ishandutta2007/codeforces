#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
*/

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    bool fl = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        if(abs(a[i] - a[i - 1]) > 1)
            fl = true;
    }

    if(fl) {
        cout << 0 << endl;
        return;
    }

    int ans = min(y + x, 2 * y);

    for(int i = 1; i < n; i++) {
        if(abs(a[i] - a[i - 1]) == 1) {
            ans = min(ans, y);
            ans = min(ans, x);
        }
    }

    cout << ans << endl;
}


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

}