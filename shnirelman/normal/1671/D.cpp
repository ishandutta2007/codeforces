#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const ld eps = 1e-4;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    int mn = INF, mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    li ans = 0;
    for(int i = 0; i < n - 1; i++)
        ans += abs(a[i] - a[i + 1]);


    if(mn > 1) {
        int res = min(a[0] - 1, a[n - 1] - 1);
        for(int i = 0; i < n - 1; i++)
            res = min(res, a[i] - 1 + a[i + 1] - 1 - abs(a[i] - a[i + 1]));
        ans += res;
    }

    if(mx < x) {
        int res = min(x - a[0], x - a[n - 1]);
        for(int i = 0; i < n - 1; i++)
            res = min(res, x - a[i] + x - a[i + 1] - abs(a[i] - a[i + 1]));
        ans += res;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}