#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
int a[N], p[N], res[N], n, m, x;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
        p[x] = i;
    }
    bool fail = false;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (a[x] == 0) {
            cout << "Impossible";
            return 0;
        }
        if (a[x] > 1)
            fail = true;
        if (a[x] == 1)
            res[i] = p[x] + 1;

    }
    if (fail)
        cout << "Ambiguity";
    else {
        cout << "Possible\n";
        for (int i = 0; i < m; i++)
            cout << res[i] << " ";
    }
}