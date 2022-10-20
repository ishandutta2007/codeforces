// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        string s;
        cin >> s;
        int n = s.size();
        if (s[n - 1] != 'B') {
            cout << "NO\n";
            continue;
        }
        int ac = 0;
        int bc = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                ++ac;
            }
            else {
                ++bc;
                if (ac < bc) {
                    cout << "NO\n";
                    goto A;
                }
            }
        }
        cout << "YES\n";
        A: continue;
    }

    return 0;
}