#include <bits/stdc++.h>
using namespace std;

int n, s1, s2, t1, t2, d1[105], d2[105], a[105];

int main() {
    cin >> n >> s1 >> s2;
    for (int i = n - 1; i >= 0; i--) {
        cout << "+ " << (i > 2 ? i : i % 2 + 1) << endl;
        t1 = s1; t2 = s2; cin >> s1 >> s2;
        d1[i] = s1 - t1; d2[i] = s2 - t2;
    }
    a[1] = sqrt(d1[0] * 2);
    a[3] = d2[0] - d2[2] - 1;
    a[2] = d2[2] / (a[3] + 1);
    a[4] = d2[1] / (a[3] + 1) - a[1] - 2;
    for (int i = 5; i <= n; i++) {
        a[i] = (d2[i - 2] - a[i - 4] * a[i - 3]) / (a[i - 1] + 1) - a[i - 3] - 1;
    }
    cout << "!"; a[n]++;
    for (int i = 1; i <= n; i++) { cout << " " << a[i]; }
    cout << endl;
    return 0;
}