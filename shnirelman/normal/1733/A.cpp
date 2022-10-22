#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const int M = 998244353;
const int N = 2e5 + 13;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> mx(k, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx[i % k] = max(mx[i % k], a[i]);
    }

    li ans = 0;
    for(int x : mx)
        ans += x;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}