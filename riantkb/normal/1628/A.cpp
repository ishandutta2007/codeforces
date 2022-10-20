// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 998244353;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<queue<int>> qs(n + 9);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            qs[a[i]].push(i);
        }
        vector<int> b;
        int l = 0;
        while (l < n) {
            int ma = l;
            for (int i = 0; i < n + 9; ++i) {
                while (!qs[i].empty() && qs[i].front() < l) {
                    qs[i].pop();
                }
                if (!qs[i].empty()) {
                    ma = max(ma, qs[i].front());
                }
                else {
                    b.push_back(i);
                    break;
                }
            }
            l = ma + 1;
        }
        cout << b.size() << '\n';
        for (int i = 0; i < (int)b.size(); ++i) {
            cout << b[i] << (i < (int)b.size() - 1 ? ' ' : '\n');
        }

    }

    return 0;
}