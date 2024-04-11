//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;
const int B = 300;
const int K = 400;
const int LOGN = 20;



/*
*/

void solve() {
    int n, k;
    cin >> n >> k;

    k++;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(10, 1);
    for(int i = 1; i < 10; i++) {
        p[i] = p[i - 1] * 10;
    }

    li ans = 0;
    for(int i = 0; i < n; i++) {
        int x = min(k, i == n - 1 ? INF : p[a[i + 1] - a[i]] - 1);
        ans += x * 1ll * p[a[i]];
        k -= x;
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}