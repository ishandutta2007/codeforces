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
const int N = 15;//1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

void solve() {
    int n;
    cin >> n;

    int f = 1;
    for(int i = 1; i <= n; i++) {
        f = f * 1ll * i % M;
    }

    int pw2 = 1;
    for(int i = 0; i < n - 1; i++) {
        pw2 = pw2 * 2ll % M;
    }

    int ans = (f + M - pw2) % M;

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}