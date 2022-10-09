#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    vector<int> f(s.size() + 1);
    for (int i = 1; i < s.size(); i++) {
        int cand = f[i];
        while (cand > 0 && s[cand] != s[i]) {
            cand = f[cand];
        }
        if (s[cand] != s[i]) {
            f[i + 1] = 0;
        } else {
            f[i + 1] = cand + 1;
        }
    }
    int len = 0;
    for (int i = 1; i < s.size(); i++) {
        len = max(len, f[i]);
    }
    int cand = f[s.size()];
    while (cand > len) {
        cand = f[cand];
    }
    if (cand == 0) {
        cout << "Just a legend";
    } else {
        cout << s.substr(0, cand);
    }
}