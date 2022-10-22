#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    li ans = 0;

    int cur = 0;
    for(int i = 0; i < n; i++) {
        ans += (x[i] - cur) * 1ll * b;
        if(a < b * 1ll * (n - i - 1)) {
            ans += (x[i] - cur) * 1ll * a;
            cur = x[i];
        }
    }

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