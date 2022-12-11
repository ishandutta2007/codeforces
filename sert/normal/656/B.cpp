#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ld me = 0, tot = 0;
    int p = 0, m[20], r[20], n;
    bool ok = false;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> m[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    while (clock() < 1900) {
        ok = false;
        tot += 1.0;
        p++;
        for (int i = 0; i < n && !ok; i++)
            if (p % m[i] == r[i])
                ok = true;
        if (ok)
            me += 1.0;
    }
    cout.precision(10);
    cout << fixed << me / tot;




    return 0;
}