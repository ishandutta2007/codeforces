#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 3e5 + 13;
const int LOGN = 20;

void solve() {
    int n, x, t;
    cin >> n >> x >> t;

    int d = t / x;
    li ans = 0;
    if(n >= d)
        ans = (n - d) * 1ll * d + d * 1ll * (d - 1) / 2;
    else
        ans = n * 1ll * (n - 1) / 2;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}