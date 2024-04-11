#include <iostream>
#include <cstdio>

using namespace std;

int n, m, mn, mx, t;
bool imx, imn;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m >> mn >> mx;
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (t == mn) imn = true;
        if (t == mx) imx = true;
        if (t < mn || t > mx) {
            cout << "Incorrect\n";
            return 0;
        }
    }
    if (m + !imn + !imx > n && mn != mx)
        cout << "Incorrect\n";
    else
        cout << "Correct\n";
    return 0;
}