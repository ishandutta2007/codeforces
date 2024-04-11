#include <bits/stdc++.h>
using namespace std;

#define TASKNAME "epic"
void init() {
#if __gnu_linux__ == 1
    assert(freopen("a.in", "r", stdin));
    //assert(freopen("a.out", "w", stdout));
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}

typedef unsigned long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;

int a, b;

bool is_cube(ll x) {
    ll l = 0;
    ll r = N;
    ll m;

    while (r - l > 1) {
        m = (l + r) / 2;
        if (m * m * m <= x)
            l = m;
        else
            r = m;
    }

    return (l * l * l == x);
}

int main() {
    init();

    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        ll aa = a;
        ll bb = b;
        if (!is_cube(aa * bb)) {
            cout << "No\n";
            continue;
        }

        ll g = __gcd(aa, bb);

        aa /= g;
        bb /= g;

        if (g % (aa * bb) == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}