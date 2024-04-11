#include <bits/stdc++.h>
using namespace std;
 
#define all(x) (x).begin(), (x).end()
 
 
signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.push_back(s[i] - 'a');
    }
    int ans = 0;
    for (int i = 25; i > 0; --i) {
        bool st = true;
        while (st) {
            st = false;
            n = v.size();
            for (int j = 0; j < n; ++j) {
                if (v[j] == i) {
                    bool can = false;
                    if (j > 0 && v[j - 1] + 1 == v[j]) {
                        can = true;
                    }
                    if (j + 1 < n && v[j + 1] + 1 == v[j]) {
                        can = true;
                    }
                    if (can) {
                        st = true;
                        v.erase(v.begin() + j);
                        ++ans;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
}