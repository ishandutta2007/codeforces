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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> last(m);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        --c;
        last[c].push_back(i);
    }
    
    int ans = 1;
    for (int q = 0; q < m; ++q) {
        int cl = 0;
        int curk = 0;
        for (int cr = 1; cr < last[q].size(); ++cr) {
            curk += last[q][cr] - last[q][cr - 1] - 1;
            while (curk > k) {
                curk -= last[q][cl + 1] - last[q][cl] - 1;
                ++cl;
            }
            ans = max(ans, cr - cl + 1);
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}