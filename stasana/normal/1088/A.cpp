// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve() {
    int x;
    cin >> x;
    for (int a = 1; a <= x; ++a) {
        for (int b = 1; b <= x; ++b) {
            if (a % b == 0 && a * b > x && a / b < x) {
                cout << a << " " << b;
                return;
            }
        }
    }
    cout << -1;
}

int main() {
    start();
    solve();
    return 0;
}