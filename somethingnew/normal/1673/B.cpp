//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i] - 'a']++;
    }
    vector<int> cnt2 = cnt;
    cnt.assign(26, 0);
    vector<vector<int>> bt(26, vector<int>(26));
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i] - 'a']++;
        int mn = s.size(), mx = 0;
        for (int j = 0; j < 26; ++j) {
            if (cnt2[j] == 0)
                continue;
            mn = min(mn, cnt[j]);
            mx = max(mx, cnt[j]);
            for (int k = 0; k < 26; ++k) {
                if (cnt2[k] == 0)
                    continue;
                if (cnt[j] > cnt[k])
                    bt[j][k] = 1;
            }
        }
        if (abs(mn - mx) > 1) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt2[i] == 0)
            continue;
        for (int j = 0; j < i; ++j) {
            if (cnt2[j] == 0)
                continue;
            if (bt[i][j] and bt[j][i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}