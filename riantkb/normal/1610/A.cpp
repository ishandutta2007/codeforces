#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int h, w;
        cin >> h >> w;
        if (h == 1 && w == 1) {
            cout << 0 << '\n';
        }
        else if (h == 1 || w == 1) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }
    return 0;
}