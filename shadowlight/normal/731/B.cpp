#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool fl = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0 && fl) {
            cout << "NO";
            return 0;
        }
        if (x % 2 == 1) {
            fl ^= 1;
        }
    }
    if (fl) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}