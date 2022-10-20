#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        int ok = 0, ng = n + 1;
        while (ok < ng - 1) {
            int k = (ok + ng) / 2;
            int c = 0;
            for (int i = 0; i < n && c < k; ++i) {
                if (a[i] >= k - c - 1 && b[i] >= c) {
                    ++c;
                }
            }
            if (c >= k) {
                ok = k;
            }
            else {
                ng = k;
            }
        }
        cout << ok << '\n';
    }
    return 0;
}