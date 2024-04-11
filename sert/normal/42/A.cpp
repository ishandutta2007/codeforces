#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld EPS = 1e-10;
const ld INF = 10000;
const int N = 10000;

void ret(int x) {
    cout << x;
    exit(0);
}

ld a[N], b[N];
ld v, k = 1e18, sum;
int n;

int main() {
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        k = min(k, b[i] / a[i]);
    }

    cout.precision(10);
    cout << fixed << min(v, k * sum);

    return 0;
}