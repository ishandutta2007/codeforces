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
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

void solve() {
    int w, h;
    cin >> w >> h;

    li ans = 0;

    for(int ind = 0; ind < 2; ind++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];


        int m;
        cin >> m;

        vector<int> b(m);
        for(int i = 0; i < m; i++)
            cin >> b[i];

        ans = max(ans, h * 1ll * max(a[n - 1] - a[0], b[m - 1] - b[0]));

        swap(w, h);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}