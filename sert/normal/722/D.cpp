#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-12;
const ll md = (int)1e9 + 7;
const ll o_10e6 = 397802501;
const int N = (int)1e5 + 34;

unordered_set <int> s;
int a[N], x, n;

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0;
    int r = (int)1e9 + 34;
    int m;
    bool fail;

    while (r - l > 1) {
        s.clear();
        m = (l + r) / 2;
        for (int i = 0; i < n; i++) if (a[i] <= m) s.insert(a[i]);
        fail = false;
        for (int i = 0; !fail && i < n; i++) {
            if (a[i] <= m) continue;
            x = a[i];
            while (x > m) x /= 2;
            while (x > 0 && s.find(x) != s.end()) x /= 2;
            if (x == 0)
                fail = true;
            else
                s.insert(x);
        }
        if (fail)
            l = m;
        else
            r = m;
    }

    s.clear();
    for (int i = 0; i < n; i++) if (a[i] <= r) s.insert(a[i]);
    for (int i = 0; i < n; i++) {
        if (a[i] <= r) x = a[i];
        else {
            x = a[i];
            while (x > r) x /= 2;
            while (x > 0 && s.find(x) != s.end()) x /= 2;
            s.insert(x);
        }
        cout << x << " ";
    }

    return 0;
}