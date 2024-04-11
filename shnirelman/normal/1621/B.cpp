#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

int l[N], r[N], c[N];

void solve() {
    int n;
    cin >> n;

    int mn = 0, mx = 0;
    int all = 0;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> c[i];

        if(l[i] < l[mn] || l[i] == l[mn] && c[i] < c[mn])
            mn = i;
        if(r[i] > r[mx] || r[i] == r[mx] && c[i] < c[mx])
            mx = i;
        if(l[all] > l[mn] || r[all] < r[mx])
            all = -1;
        if(l[mn] == l[i] && r[mx] == r[i] && (all == -1 || c[all] > c[i]))
            all = i;

        cout << min(c[mn] + c[mx], all != -1 ? c[all] : INF) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}