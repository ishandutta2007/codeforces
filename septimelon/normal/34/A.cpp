#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
const int MAX = 1000000009;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mind = MAX;
    int mini;
    for (int i = 0; i < n; ++i) {
        if (abs(a[i] - a[(i + 1) % n]) < mind) {
            mind = abs(a[i] - a[(i + 1) % n]);
            mini = i;
        }
    }
    cout << mini + 1 << " " << (mini + 1) % n + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}