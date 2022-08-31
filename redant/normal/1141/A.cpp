#include <iostream>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    const int mx = 100;
    int r = mx;
    for (int c2 = 0, p2 = 1; c2 < 30; c2++, p2 *= 2)
        for (int c3 = 0, p3 = 1; c3 < 20; c3++, p3 *= 3) {
            if (1ll * n * p2 * p3 == m) {
                r = min(r, c2 + c3);
            }
        }
    cout << (r == mx ? -1 : r) << endl;
    return 0;
}