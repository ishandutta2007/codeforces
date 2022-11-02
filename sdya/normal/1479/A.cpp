#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int maxN = 110000;
int a[maxN], n;

void check(int i) {
    if (i < 1 || i > n) {
        return;
    }
    if (a[i] < min(a[i - 1], a[i + 1])) {
        cout << "! " << i << endl;
        exit(0);
    }
}

void ask(int i) {
    if (a[i] == -1) {
        cout << "? " << i << endl;
        cin >> a[i];
    }
}

void solve(int l, int r) {
    if (l + 2 >= r) {
        for (int i = l; i <= r; ++i) {
            ask(i);
        }

        for (int i = 1; i <= n; ++i) {
            check(i);
        }

        cerr << "BAD" << endl;
        exit(1);
    } else {
        int m = (l + r) / 2;
        for (int i = m - 1; i <= m + 1; ++i) {
            ask(i);
        }
        check(m - 1);
        check(m);
        check(m + 1);

        if (a[m - 1] > a[m] && a[m] > a[m + 1]) {
            solve(max(l, m - 1), r);
        } else {
            solve(l, min(m + 1, r));
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;

    a[0] = n + 1;
    for (int i = 1; i <= n; ++i) {
        a[i] = -1;
    }
    a[n + 1] = n + 1;

    if (n == 1) {
        check(1);
        return 0;
    }

    ask(1);
    ask(2);
    ask(n - 1);
    ask(n);

    check(1);
    check(2);
    check(n - 1);
    check(n);

    solve(1, n);

    return 0;
}