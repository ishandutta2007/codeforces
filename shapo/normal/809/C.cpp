#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

const int MOD = 1000000007;

typedef pair< int, int > pii;

int gl_cnt = 0;

pii
compute(int x1, int y1, int x2, int y2, int k)
{
    gl_cnt++;
    int res = 0;
    int cnt = 0;
    int w = 1;
    while (w < x2 || w < y2) {
        w *= 2;
    }
    if (x1 == 1 && x2 == w) {
        k = min(k, w);
        int l = y2 - y1 + 1;
        return mp(1ll * l * (1ll * k * (k + 1) / 2 % MOD) % MOD, 1ll * k * l % MOD);
    }
    if (y1 == 1 && y2 == w) {
        k = min(k, w);
        int l = x2 - x1 + 1;
        return mp(1ll * l * (1ll * k * (k + 1) / 2 % MOD) % MOD, 1ll * k * l % MOD);
    }
    // cerr << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << k << " -> " << res << ", " << cnt << endl;
    int w2 = w / 2;
    for (int lb : {1, w2 + 1}) {
        for (int rb : {1, w2 + 1}) {
            int add = int((lb == 1) ^ (rb == 1)) * w2;
            if (add < k && max(x1, lb) <= min(x2, lb + w2 - 1) && max(y1, rb) <= min(y2, rb + w2 - 1)) {
                int ares, acnt;
                tie(ares, acnt) = compute(
                        max(x1, lb) - lb + 1,
                        max(y1, rb) - rb + 1,
                        min(x2, lb + w2 - 1) - lb + 1,
                        min(y2, rb + w2 - 1) - rb + 1,
                        k - add);
                cnt = (cnt + acnt) % MOD;
                res = (res + ares + 1ll * acnt * add) % MOD;
            }
        }
    }
    return mp(res, cnt);
}

int
main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x1, x2, y1, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        int res, cnt;
        tie(res, cnt) = compute(x1, y1, x2, y2, k);
        // cout << res << ' ' << cnt << '\n';
        cout << res << '\n';
    }
    // cout << gl_cnt << '\n';
    return 0;
}