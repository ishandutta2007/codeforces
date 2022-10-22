#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mn = INF, mx = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] != -1 && (i > 0 && a[i - 1] == -1 || i < n - 1 && a[i + 1] == -1)) {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
    }

    int k = (mn + mx) / 2;
    for(int i = 0; i < n; i++)
        a[i] = (a[i] == -1 ? k : a[i]);

    int res = 0;
    for(int i = 1; i < n; i++) {
        res = max(res, abs(a[i] - a[i - 1]));
    }

    cout << res << ' ' << k << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}