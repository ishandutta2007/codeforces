#include <iostream>

using namespace std;

int cur, sum, x, y, n, m, mx = 1, k;

int go() {
    if (x + mx == -1 || x + mx == m) {
        mx = -mx;
        y++;
    } else
        x += mx;
}

int main() {
    cin >> m >> n >> k;
    x = y = 0;
    for (int i = 0; i < k - 1; i++) {
        cout << "2 ";
        cout << x + 1 << " " << y + 1 << " ";
        go();
        cout << x + 1 << " " << y + 1 << "\n";
        go();
    }
    cout << 2 + n * m - k * 2 << " " << x + 1 << " " << y + 1;
    for (int i = -1; i < n * m - k * 2; i++) {
        go();
        cout << " " << x + 1 << " " << y + 1;
    }
    return 0;
}