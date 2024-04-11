#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

#define LLD "%lld"

const int MAXN = 100500;
const int MAXK = 1000;

typedef long long ll;

int val[MAXN];
bool one[MAXK];
int bl_v[MAXK];
ll add_val[MAXK], sum_seg[MAXK];
ll part_add[MAXN];
int n, m, k;
int l[MAXK], r[MAXK];

int
main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        val[i] = i + 1;
        part_add[i] = 0;
    }
    k = min(n, 2 * int(sqrt(n + 10.)));
    int cnt_blocks = (n + k - 1) / k;
#ifdef LOCAL
    cout << "k = " << k << " cnt = " << cnt_blocks << endl;
#endif
    for (int i = 0; i < cnt_blocks; ++i) {
        l[i] = i * k, r[i] = min(n - 1, (i + 1) * k - 1);
        one[i] = false;
        add_val[i] = 0;
        sum_seg[i] = 0;
        bl_v[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int type, lp, rp, x;
        scanf("%d%d%d", &type, &lp, &rp);
        --lp, --rp;
        if (type == 1) {
            scanf("%d", &x);
            for (int cur_b = 0; cur_b < cnt_blocks; ++cur_b) {
                if (max(l[cur_b], lp) > min(r[cur_b], rp)) {
                    continue;
                }
                if (lp <= l[cur_b] && rp >= r[cur_b]) {
                    if (one[cur_b]) {
                        add_val[cur_b] += abs(x - bl_v[cur_b]);
                    } else {
                        for (int id = l[cur_b]; id <= r[cur_b]; ++id) {
                            sum_seg[cur_b] += abs(val[id] - x);
                            part_add[id] += abs(val[id] - x);
                            val[id] = x;
                        }
                    }
                    one[cur_b] = true;
                    bl_v[cur_b] = x;
                } else {
                    for (int id = l[cur_b]; id <= r[cur_b]; ++id) {
                        part_add[id] += add_val[cur_b];
                        sum_seg[cur_b] += add_val[cur_b];
                        if (one[cur_b]) {
                            val[id] = bl_v[cur_b];
                        }
                    }
                    add_val[cur_b] = 0;
                    for (int id = max(lp, l[cur_b]); id <= min(rp, r[cur_b]); ++id) {
                        part_add[id] += abs(val[id] - x);
                        sum_seg[cur_b] += abs(val[id] - x);
                        val[id] = x;
                    }
                    one[cur_b] = false;
                }
            }
        } else {
            ll res = 0LL;
            for (int cur_b = 0; cur_b < cnt_blocks; ++cur_b) {
                if (max(l[cur_b], lp) > min(r[cur_b], rp)) {
                    continue;
                }
                if (lp <= l[cur_b] && rp >= r[cur_b]) {
                    res += sum_seg[cur_b] + 1ll * (r[cur_b] - l[cur_b] + 1) * add_val[cur_b];
                } else {
                    for (int id = max(lp, l[cur_b]); id <= min(rp, r[cur_b]); ++id) {
                        res += part_add[id] + add_val[cur_b];
                    }
                }
            }
            printf(LLD "\n", res);
        }
    }
    return 0;
}