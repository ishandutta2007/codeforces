#include <bits/stdc++.h>

using namespace std;

bool pr(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector <int> color(n + 2, 0);
    bool fl = 0;
    for (int i = 2; i <= n + 1; i++) {
        if (pr(i)) {
            color[i] = 1;
        } else {
            color[i] = 2;
            fl = 1;
        }
    }
    if (fl) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
    for (int i = 2; i <= n + 1; i++) {
        cout << color[i] << " ";
    }
}