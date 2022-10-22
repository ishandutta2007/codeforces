#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < n; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        if (u == 1) {
            if (v == 1) {
                c.push_back(t);
            } else {
                a.push_back(t);
            }
        } else if (v == 1) {
            b.push_back(t);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    
    int tott = 0;
    int an = min(a.size(), b.size());
    int cn = c.size();
    int ci = 0, ai = 0;
    for (int i = 0; i < k; ++i) {
        if (ci == cn && ai == an) {
            cout << "-1\n";
            return;
        }
        if (ci < cn && (ai == an || a[ai] + b[ai] > c[ci])) {
            tott += c[ci];
            ++ci;
        } else {
            tott += a[ai] + b[ai];
            ++ai;
        }
    }
    cout << tott << "\n";
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