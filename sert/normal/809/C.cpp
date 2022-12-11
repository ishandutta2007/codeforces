#include <bits/stdc++.h>

using namespace std;
#define TASKNAME "waytooloud"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;

const int N = (int)1e6 + 34;
const ll md = (int)1e9 + 7;
const ll deg30 = (ll)(1ll << 30ll);

int x1, x2, y1, y2, k;

ll go(ll st, int deg, int a1, int a2, int b1, int b2) {
    if (a1 >= x2 || x1 >= a2 || b1 >= y2 || y1 >= b2 || st > k) return 0;

    ll wid = -1;

    if (x1 <= a1 && a2 <= x2) wid = min(b2, y2) - max(b1, y1);
    if (y1 <= b1 && b2 <= y2) wid = min(a2, x2) - max(a1, x1);

    if (wid != -1) {
        //cerr << a1 << " " << a2 << " " << b1 << " " << b2 << " wid=" << wid << "\n";
        ll sd = (1 << deg);
        ll num = min(sd, k - st + 1);
        ll cur = (((st * num + (num * (num - 1)) / 2) % md) * wid) % md;
        return cur;
    }

    int ma = (a1 + a2) / 2;
    int mb = (b1 + b2) / 2;
    deg--;
    ll side = (1 << deg);

    /*if (a1 + 1 == a2) {
        return (go(st, deg, a1, a2, b1, mb) + go(st + side, deg, a1, a2, mb, b2)) % md;
    } else {
        return (go(st, deg, a1, ma, b1, b2) + go(st + side, deg, ma, a2, b1, b2)) % md;
    }*/

    return (
        go(st, deg, a1, ma, b1, mb) +
        go(st + side, deg, a1, ma, mb, b2) +
        go(st + side, deg, ma, a2, b1, mb) +
        go(st, deg, ma, a2, mb, b2)
    ) % md;
}

int main() {
    init();

    //cerr << deg30;
    //return 0;

    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        x1--;
        y1--;
        printf("%I64d\n", go(1, 30, 0, deg30, 0, deg30));
    }

    return 0;
}