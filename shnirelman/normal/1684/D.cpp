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
const int M = 1e9 + 7;
//const int M = 998244353;
const int N = 100 + 13;
const int LOGN = 30;

/*
*/

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        b[i] = n - i - 1 - a[i];

        sum += a[i];
    }

    sort(b.begin(), b.end());

    for(int i = 0; i < n; i++) {
        b[i] -= i;
    }

    for(int i = 0; i < k && b[i] < 0; i++) {
        sum += b[i];
    }

    cout << sum << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}