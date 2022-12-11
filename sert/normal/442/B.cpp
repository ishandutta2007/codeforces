#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld eps = 1e-12;

ld a[123], p0, p1, ans = 0, n0, n1;
int n;

void check() {
    p0 = 1;
    p1 = 0;
    for (int i = 0; i < n && p0 + p1 > ans + eps; i++) {
        n0 = p0 * (1.0 - a[i]);
        n1 = p1 * (1.0 - a[i]) + p0 * a[i];
        p0 = n0;
        p1 = n1;
        ans = max(ans, n1);
    }
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a + n);
    check();
    reverse(a, a + n);
    check();
    while (clock() < 1800) {
        random_shuffle(a, a + n);
        check();
    }
    cout.precision(12);
    cout << fixed << ans;
}