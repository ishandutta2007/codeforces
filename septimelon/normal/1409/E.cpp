#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const ll INF = 1000000000000000000LL;

ll sum(ll a, ll b) {
    ll ans = a + b;
    while (ans > MOD) {
        ans -= MOD;
    }
    return ans;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
    }
    sort(x.begin(), x.end());
    x.push_back(INF);

    vector<int> nex(n + 1);
    nex[0] = 1;
    for (int i = 0; i < n; ++i) {
        while (x[nex[i]] - x[i] <= k) {
            ++nex[i];
        }
        nex[i + 1] = nex[i];
    }

    int ans = 0;
    vector<int> maxs(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        maxs[i + 1] = max(maxs[i], maxs[i + 1]);
        maxs[nex[i]] = max(maxs[nex[i]], nex[i] - i);
        ans = max(ans, maxs[i] + nex[i] - i);
    }
    ans = max(ans, maxs[n]);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}