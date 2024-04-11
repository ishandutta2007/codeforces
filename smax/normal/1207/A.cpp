#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int b, p, f, h, c, ret;
        cin >> b >> p >> f >> h >> c;
        if (h > c) {
            ret = min(b / 2, p) * h;
            b -= min(b, 2 * p);
            ret += min(b / 2, f) * c;
        } else {
            ret = min(b / 2, f) * c;
            b -= min(b, 2 * f);
            ret += min(b / 2, p) * h;
        }
        cout << ret << "\n";
    }

    return 0;
}