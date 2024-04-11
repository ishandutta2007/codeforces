#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<int>> ost(2);
    for (int i = 0; i < n; ++i) {
        ost[a[i] % 2].push_back(i + 1);
    }
    if (ost[1].size() > 0 && ost[1].size() % 2 == 0) {
        ost[1].pop_back();
        ost[1].pop_back();
    } else if (ost[0].size() > 0 && ost[0].size() % 2 == 0) {
        ost[0].pop_back();
        ost[0].pop_back();
    }
    if (ost[0].size() % 2 == 1) {
        ost[0].pop_back();
        ost[1].pop_back();
    }
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < ost[i].size(); j += 2) {
            cout << ost[i][j] << " " << ost[i][j + 1] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }
    
    return 0;
}