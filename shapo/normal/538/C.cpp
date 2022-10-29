#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int m, n;
    cin >> n >> m;
    int px, py;
    cin >> px >> py;
    int max_val = py + px - 1;
    bool ok = true;
    for (int i = 2; i <= m; ++i) {
        int cx, cy;
        cin >> cx >> cy;
        if (!ok) {
            continue;
        }
        if (abs(cy - py) > cx - px) {
            ok = false;
        } else {
            int rev = (cx - px) - abs(cy - py);
            max_val = max(max_val, max(cy, py) + rev / 2);
        }
        px = cx, py = cy;
    }
    if (ok) {
        max_val = max(max_val, py + n - px);
        cout << max_val << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}