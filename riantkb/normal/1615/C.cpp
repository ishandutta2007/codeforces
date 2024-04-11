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
        string a, b;
        cin >> n >> a >> b;
        int c00 = 0;
        int c01 = 0;
        int c10 = 0;
        int c11 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '0' && b[i] == '0') {
                ++c00;
            }
            if (a[i] == '0' && b[i] == '1') {
                ++c01;
            }
            if (a[i] == '1' && b[i] == '0') {
                ++c10;
            }
            if (a[i] == '1' && b[i] == '1') {
                ++c11;
            }
        }
        int mi = M;
        if (c10 == c01) {
            mi = min(mi, c10 + c01);
        }
        if (c10 > 0) {
            int nc00 = c10 - 1;
            int nc01 = c11;
            int nc10 = c00 + 1;
            int nc11 = c01;
            if (nc01 == nc10) {
                mi = min(mi, nc01 + nc10 + 1);
            }
        }
        if (c11 > 0) {
            int nc00 = c10;
            int nc01 = c11 - 1;
            int nc10 = c00;
            int nc11 = c01 + 1;
            if (nc01 == nc10) {
                mi = min(mi, nc01 + nc10 + 1);
            }
        }
        cout << (mi == M ? -1 : mi) << '\n';
    }

    return 0;
}