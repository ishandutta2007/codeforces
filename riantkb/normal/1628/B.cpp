// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 998244353;


bool is_pal(const string& s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<string> s(n);
        bool ok = false;
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            if (is_pal(s[i])) {
                ok = true;
            }
            mp[s[i]].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            if (s[i].size() == 3) {
                {
                    string t({ s[i][2], s[i][1], s[i][0] });
                    if (mp[t].size() > 0 && (mp[t].front() < i || mp[t].back() > i)) {
                        ok = true;
                        break;
                    }
                }
                {
                    string t({ s[i][1], s[i][0] });
                    if (mp[t].size() > 0 && mp[t].back() > i) {
                        ok = true;
                        break;
                    }
                }
                {
                    string t({ s[i][2], s[i][1] });
                    if (mp[t].size() > 0 && mp[t].front() < i) {
                        ok = true;
                        break;
                    }
                }
            }
            else {
                {
                    string t({ s[i][1], s[i][0] });
                    if (mp[t].size() > 0 && (mp[t].front() < i || mp[t].back() > i)) {
                        ok = true;
                        break;
                    }
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}