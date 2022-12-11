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

struct pt {
    ld x, y;
    pt() {}
    pt(ld xx, ld yy) {
        x = xx;
        y = yy;
    }
    ld len() const {
        return sqrtl(x * x + y * y);
    }
    pt operator - (const pt &a) const {
        return pt(x - a.x, y - a.y);
    }
};

pt a[N];
int n;
ld ans = 1e18;
ld A, B, C, d;

int main() {
    init();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    a[n] = a[0];
    a[n + 1] = a[1];
    for (int i = 0; i < n; i++) {
        ans = min(ans, (a[i] - a[i + 1]).len() * 0.5);
    }

    for (int i = 1; i <= n; i++) {
        A = a[i - 1].y - a[i + 1].y;
        B = a[i + 1].x - a[i - 1].x;
        C = -A * a[i - 1].x - B * a[i - 1].y;
        d = fabsl(A * a[i].x + B * a[i].y + C) / sqrtl(A * A + B * B);
        ans = min(ans, d * 0.5);
    }

    cout.precision(10);
    cout << fixed << ans;

    return 0;
}