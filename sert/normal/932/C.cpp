#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
#else
#endif
}

const int N = (int)1e6 + 34;

void go(int n, int a, int b, int na, int nb) {
    int cur = 1;
    for (int i = 0; i < na; i++) {
        int st = cur++;
        for (int j = 0; j < a - 1; j++) {
            cout << cur++ << " ";
        }
        cout << st << " ";
    }

    for (int i = 0; i < nb; i++) {
        int st = cur++;
        for (int j = 0; j < b - 1; j++) {
            cout << cur++ << " ";
        }
        cout << st << " ";
    }
}

int main() {
    init();

    int n, a, b;
    cin >> n >> a >> b;

    for (int na = 0; a * na <= n; na++) {
        if ((n - na * a) % b == 0) {
            go(n, a, b, na, (n - na * a) / b);
            return 0;
        }
    }

    cout << -1;

    return 0;
}