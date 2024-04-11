#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int N = 1e6 + 34;

int n, m, k, x, y, a[2000][2000];

int f(int x, int y) {
    return a[x][y] * a[x + 1][y] * a[x][y + 1] * a[x + 1][y + 1];
}

int main() {
   // freopen("a.in", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        a[x][y] = 1;
        if (f(x - 1, y - 1) + f(x - 1, y) + f(x, y - 1) + f(x, y)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}