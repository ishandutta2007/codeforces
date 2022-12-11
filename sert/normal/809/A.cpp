#include <bits/stdc++.h>

using namespace std;
#define TASKNAME "waytooloud"
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

const int N = (int)1e6 + 34;
const ll md = (int)1e9 + 7;

int n;
ll a[N];

ll step(ll a, ll st) {
    if (st == 0) return 1;
    if (st % 2) return (a * (step(a, st - 1))) % md;
    ll q = step(a, st / 2);
    return (q * q) % md;
}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", a + i);
    sort(a, a + n);
    ll l, r, ans = 0;
    ans = 0;

    for (int i = 0; i < n; i++) {
        l = step(2, i) - 1;
        r = step(2, n - i - 1) - 1;
        ans = (ans + (l - r) * a[i] + md * md) % md;
    }

    printf("%I64d\n", ans);

    return 0;
}