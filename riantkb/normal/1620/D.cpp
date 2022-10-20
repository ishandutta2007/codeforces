// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 1000000007;
const long long LM = 1LL << 60;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ma = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ma = max(ma, a[i]);
        }
        if (ma % 3 == 0) {
            bool f = true;
            for (auto& i : a) {
                f &= i % 3 == 0;
            }
            cout << (f ? ma / 3 : ma / 3 + 1) << '\n';
        }
        else if (ma % 3 == 1) {
            bool f1 = true;
            bool f2 = true;
            for (auto& i : a) {
                f1 &= i % 3 != 2;
                f2 &= i != ma - 1 && i != 1;
            }
            cout << (f1 || f2 ? ma / 3 + 1 : ma / 3 + 2) << '\n';
        }
        else {
            bool f = true;
            for (auto& i : a) {
                f &= i % 3 != 1;
            }
            cout << (f ? ma / 3 + 1 : ma / 3 + 2) << '\n';
        }
    }
    return 0;
}