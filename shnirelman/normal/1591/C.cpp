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
    int n, k;
    cin >> n >> k;

    vector<int> a(1, 0), b(1, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x < 0)
            a.push_back(-x);
        else
            b.push_back(x);
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    li ans = 0;

    for(int i = 0; i < a.size(); i += k) {
        ans += a[i] * 2;
    }

    for(int i = 0; i < b.size(); i += k) {
        ans += b[i] * 2;
    }

    ans -= max(a[0], b[0]);

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