// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
        for (int i = 0; i < n; ++i) {
            --cnt[s[i] - 'a'];
            if (cnt[s[i] - 'a'] == 0) {
                cout << s.substr(i) << '\n';
                break;
            }
        }
    }
    return 0;
}