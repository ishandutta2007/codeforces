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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<li> p(n + 1, 0);
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }

    li ans = 0;
    for(int i = 1; i <= n; i++) {
//        int l = 0, r = 1e9 + 13;
        ans += max(0ll, (x - p[i] + i) / i);
//        cout << i << ' ' << (x - p[i] + i) / i << endl;
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