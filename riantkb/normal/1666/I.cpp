// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int M = 1000000007;

int ask(int i, int j) {
    cout << "SCAN " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

int dig(int i, int j) {
    cout << "DIG " << i + 1 << ' ' << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int h, w;
        cin >> h >> w;
        int d0 = ask(0, 0);
        int dh = ask(h - 1, 0);
        int x1, x2;
        {
            int k = (h - 1 - (dh - d0) / 2) / 2;
            int dk = ask(k, 0);
            x1 = (d0 - dk) / 2;
            x2 = h - 1 - (dh - dk) / 2;
        }
        int dw = h * 2 + w * 2 - 2 * 2 - dh;
        int y1, y2;
        {
            int k = (w - 1 - (dw - d0) / 2) / 2;
            int dk = ask(0, k);
            y1 = (d0 - dk) / 2;
            y2 = w - 1 - (dw - dk) / 2;
        }
        int t = dig(x1, y1);
        if (t) {
            dig(x2, y2);
        }
        else {
            dig(x1, y2);
            dig(x2, y1);
        }
    }

    return 0;
}