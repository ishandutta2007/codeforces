#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
const ll md = 1e9 + 7;

set <int> p, m;
int kol, x, pr, nx;
int n, k, a, q;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> k >> a;
    p.insert(n + 1);
    m.insert(0);
    kol = (n + 1) / (a + 1);

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x;

        pr = -(*m.upper_bound(-x));
        nx = *p.upper_bound(x);

        kol -= (nx - pr) / (a + 1);
        kol += (x - pr) / (a + 1);
        kol += (nx - x) / (a + 1);

        //cerr << kol << "\n";

        if (kol < k) {
            cout << i + 1;
            return 0;
        }

        p.insert(x);
        m.insert(-x);
    }

    cout << -1;

    return 0;
}