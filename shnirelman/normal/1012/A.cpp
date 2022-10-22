#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 200000 + 13;
const int M = 1e9 + 7;
const int B = 600;

/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n * 2);
    for(int i = 0; i < n * 2; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    li ans = (a[n - 1] - a[0]) * 1ll * (a[n * 2 - 1] - a[n]);
    for(int i = 1; i + n <= 2 * n; i++) {
        ans = min(ans, (a[i + n - 1] - a[i]) * 1ll * (a[n * 2 - 1] - a[0]));
    }

    cout << ans << endl;
}

signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}