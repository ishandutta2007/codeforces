#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "sum"
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
typedef long double ld;

const int N = (int)1e6 + 34;
const ll md = (int)1e9 + 7;

ll step(ll a, ll st) {
    if (st == 0) return 1;
    if (st % 2) return (a * step(a, st - 1)) % md;
    ll q = step(a, st / 2);
    return (q * q) % md;
}

char s[N];
int main() {
    init();

    gets(s);
    int n = strlen(s);

    ll ans = 0, a = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') a++;
        else ans = (ans + step(2, a) - 1) % md;
    }

    printf("%I64d", ans);

    return 0;
}