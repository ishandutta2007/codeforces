#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

void solve() {
    int k;
    scanf("%d", &k);
    int a[7];
    int c = 0;
    for (int i = 0; i < 7; ++i) {
        scanf("%d", a + i);
        c += a[i];
    }

    int ans = (int)1.1e9;
    for (int ii = 0; ii < 7; ++ii) {
        if (a[0]) {
            int cw = (k % c == 0 ? k / c - 1 : k / c);
            int rem = k - cw * c;
            int cans = cw * 7;
            for (int i = 0; i < 7; ++i) {
                ++cans;
                if (a[i]) {
                    --rem;
                    if (rem == 0)
                        break;
                }
            }
            ans = min(ans, cans);
        }
        rotate(a, a + 1, a + 7);
    }
    printf("%d\n", ans);
}

int main()
{
#ifdef ONPC
    freopen("g.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}