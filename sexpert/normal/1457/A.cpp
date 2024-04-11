#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        auto di = [&](int x1, int y1, int x2, int y2){ return abs(x1 - x2) + abs(y1 - y2); };
        cout << max({di(r, c, 1, 1), di(r, c, n, 1), di(r, c, 1, m), di(r, c, n, m)}) << '\n';
    }
}