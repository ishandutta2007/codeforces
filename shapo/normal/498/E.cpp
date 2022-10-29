#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int MD = 1000000007;

typedef vector< vector< int > > vt;

vt base[8];
int ans[256];
int tmp[256];

bool
ok(int l, int r, int im, int cnt)
{
    int len[cnt];
    for (int i = 0; i < cnt; ++i) {
        len[i] = 4;
    }
    len[0]--;
    len[cnt - 1]--;
    for (int i = 0; i < cnt; ++i) {
        len[i] -= l & 1;
        l /= 2;
        len[i] -= r & 1;
        r /= 2;
    }
    for (int i = 0; i < cnt - 1; ++i) {
        len[i] -= im & 1;
        len[i + 1] -= im & 1;
        im /= 2;
    }
    for (int i = 0; i < cnt; ++i) {
        if (!len[i]) {
            return false;
        }
    }
    return true;
}

void
construct_base(int pow2)
{
    int cnt = (1 << pow2);
    base[pow2].assign(cnt, vector< int >(cnt, 0));
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            for (int k = 0; k < (1 << (pow2 - 1)); ++k) {
                if (ok(i, j, k, pow2)) {
                    base[pow2][i][j]++;
                }
            }
        }
    }
}

vt
mult_base(const vt &a, const vt &b)
{
    int n = a.size(), m = a[0].size(), k = b[0].size();
    vt c;
    c.assign(n, vector< int >(k, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            c[i][j] = 0;
            for (int tm = 0; tm < m; ++tm) {
                c[i][j] = (c[i][j] + 1ll * a[i][tm] * b[tm][j]) % MD;
            }
        }
    }
    return c;
}

vt
get_pow(vt x, int pow)
{
    int n = x.size();
    vt res(n, vector< int >(n, 0));
    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    while (pow) {
        if (pow & 1) {
            res = mult_base(res, x);
        }
        pow /= 2;
        x = mult_base(x, x);
    }
    return res;
}

int
main()
{
    for (int i = 1; i <= 7; ++i) {
        construct_base(i);
    }
    vector< int > m(8);
    for (int i = 1; i <= 7; ++i) {
        cin >> m[i];
        base[i] = get_pow(base[i], m[i]);
    }
    for (int i = 0; i < 256; ++i) {
        ans[i] = 0;
    }
    ans[1] = 1;
    for (int id = 1; id <= 7; ++id) {
        int cnt = (1 << id);
        for (int i = 0; i < cnt; ++i) {
            tmp[i] = 0;
            for (int j = 0; j < cnt; ++j) {
                tmp[i] = (tmp[i] + 1ll * ans[j] * base[id][i][j]) % MD;
            }
        }
        for (int i = 0; i < cnt; ++i) {
            ans[i] = 0;
        }
        for (int i = 0; i < cnt; ++i) {
            ans[i + cnt] = tmp[i];
        }
    }
    cout << ans[255] << '\n';
    return 0;
}