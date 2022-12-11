#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool solve() {
    int n, m; scanf("%d %d", &n, &m);
    map<int, int> blockades;
    for (int i = 0; i < m; ++i) {
        int r, c; scanf("%d %d", &r, &c);
        blockades[c] |= (1 << (r - 1)); // 1 taas 2 baba
    }
    blockades[n+1] = 3; // check that the wall at the end is flat
    int lastKnownAfter = 0;
    /*
     *    X
     *    >>
     * LKA^
     */
    int lastKnownType = 0; // 0: flat, 1: nakausli yung taas, -1: nakausli yung baba
    for (auto [x, type] : blockades) {
        if (type == 3) {
            if (lastKnownType != 0) return false;
            lastKnownAfter = x;
        } else if (lastKnownType == 0) {
            lastKnownAfter = x;
            lastKnownType = (type == 1 ? 1 : -1);
        } else {
            int outType = (type == 1 ? 1 : -1);
            if (lastKnownType == outType && (x - lastKnownAfter) % 2 == 0) return false;
            if (lastKnownType != outType && (x - lastKnownAfter) % 2 == 1) return false;
            lastKnownAfter = x;
            lastKnownType = 0;
        }
    }
    return true;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) printf("%s\n", solve() ? "YES" : "NO");
}