#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    for (int _ = 0; _ < q; ++_) {
        int j;
        cin >> j;
        --j;
        int i = 0;
        while (i < h) {
            if (a[i][j] == 1) {
                a[i][j] = 2;
                ++j;
            }
            else if (a[i][j] == 2) {
                ++i;
            }
            else {
                a[i][j] = 2;
                --j;
            }
        }
        cout << j + 1 << (_ < q - 1 ? ' ' : '\n');

    }


    return 0;
}