#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

vector< int > par, rnk;
int n, k;

void
link(int x, int y)
{
    if (rnk[x] >= rnk[y]) {
        par[y] = x;
    } else {
        par[x] = y;
    }
    if (rnk[x] == rnk[y]) {
        ++rnk[x];
    }
}

inline int
getPar(int x)
{
    if (par[x] != x) {
        par[x] = getPar(par[x]);
    }
    return par[x];
}

void
union_ver(int x, int y)
{
    x = getPar(x);
    y = getPar(y);
    if (x != y) {
        link(x, y);
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    par.assign(2 * (n + 2), 0);
    rnk.assign(2 * (n + 2), 0);
    for (int i = 0; i < 2 * (n + 2); ++i) {
        par[i] = i;
    }
    for (int i = 0; i < k; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        int min_val = max(1, abs(a - b) + 1), max_val = min(a + b - 1, 2 * n + 1 - a - b);
        while ((min_val + 1) % 2 != (a + b) % 2) ++min_val;
        while ((max_val + 1) % 2 != (a + b) % 2) --max_val;
        ++min_val, ++max_val;
        union_ver(2 * (min_val - 2), 2 * max_val + (c == 'o'));
        union_ver(2 * (min_val - 2) + 1, 2 * max_val + (c == 'x'));
    }
    vector< int > used(2 * (n + 2), 0);
    bool ok = true;
    for (int i = 0; i <= n + 1 && ok; ++i) {
        used[getPar(2 * i)] = 1;
        used[getPar(2 * i + 1)] = 1;
        if (getPar(2 * i) == getPar(2 * i + 1)) {
            ok = false;
        }
    }
    if (!ok) {
        cout << "0\n";
    } else {
        int cnt = 0;
        for (int i = 0; i < 2 * (n + 2); ++i) {
            cnt += used[i];
        }
        // val at position 0 and -1 (for odd) is always 0
        cnt = (cnt - 4) / 2;
        int res = 1;
        for (int i = 0; i < cnt; ++i) {
            res += res;
            while (res >= MOD) {
                res -= MOD;
            }
        }
        cout << res << '\n';
    }
    return 0;
}