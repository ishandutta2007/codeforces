#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        int x;
        cin >> x;
        if (x == 15) {
            cout << "DOWN";
        } else if (x == 0) {
            cout << "UP";
        } else {
            cout << -1;
        }
        return 0;
    }
    bool fl = 0;
    int prev_x, x;
    for (int i = 1; i < n; i++) {
        cin >> prev_x;
    }
    cin >> x;
    if (x == 0 || (x > prev_x && x != 15)) {
        cout << "UP";
    } else {
        cout << "DOWN";
    }
}