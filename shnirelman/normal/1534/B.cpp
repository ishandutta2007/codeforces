#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2, 0);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    li ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
            ans += a[i] - max(a[i - 1], a[i + 1]);
            a[i] = max(a[i - 1], a[i + 1]);
        }

        ans += max(0, a[i] - a[i - 1]);
        ans += max(0, a[i] - a[i + 1]);
    }

    cout << ans << endl;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}