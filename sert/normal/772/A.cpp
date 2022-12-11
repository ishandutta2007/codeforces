#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-10;

const int N = (int)1e6 + 34;

ld p, l, r, m;
ld a[N], b[N], sumb, suma;
int n;
int main() {
    init();
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sumb += b[i];
        suma += a[i];
    }

    if (p + EPS > suma) {
        cout << -1;
        return 0;
    }

    l = 0;
    r = 1e18;
    ld t;
    for (int iq = 0; iq < 100; iq++) {
        m = (l + r) * 0.5;
        t = 0;
        for (int i = 0; i < n; i++) {
            t += max((ld)0.0, (m * a[i] - b[i]) / p);
        }
        if (t < m)
            l = m;
        else
            r = m;
    }
    cout.precision(12);
    cout << fixed << l;

    return 0;
}