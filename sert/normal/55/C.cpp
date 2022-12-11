#include <iostream>
#include <cstdio>

using namespace std;

int n, m, k, x, y, dst, cur;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> m >> n >> k;
    dst = n + m + 34;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        cur = min(min(x - 1, y - 1), min(m - x, n - y));
        dst = min(dst, cur);
    }
    if (dst < 5) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}