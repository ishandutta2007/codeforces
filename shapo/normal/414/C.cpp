#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

const int maxn = 2000000;

typedef long long ll;

int arr[maxn];
int cnt[maxn][30];
int n, m;
int q[maxn];
int tmp[maxn];
int tmp_pos[maxn];
int pos[maxn];
ll all_sum[30], cur_sum[30];

bool
input_data()
{
    if (scanf("%d", &n) != 1) {
        return false;
    }
    for (int i = 0; i < (1 << n); ++i) {
        scanf("%d", arr + i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", q + i);
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 1; j <= n; ++j) {
            cnt[i][j] = 0;
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        pos[i] = i;
    }
    for (int j = 1; j <= n; ++j) {
        all_sum[j] = cur_sum[j] = 0LL;
    }
    return true;
}

void
merge_sort(int from, int to, int lvl)
{
    if (from == to - 1) {
        return;
    }
    int mid = (from + to) / 2;
    merge_sort(from, mid, lvl - 1);
    merge_sort(mid, to, lvl - 1);
    // count_sort
    int t_p = from, t_q = mid;
    while (t_p != mid) {
        while (t_q < to && arr[t_q] < arr[t_p]) {
            ++t_q;
        }
        cnt[pos[t_p]][lvl] = t_q - mid;
        ++t_p;
    }
    t_q = mid, t_p = from;
    while (t_q != to) {
        while (t_p != mid && arr[t_p] < arr[t_q]) {
            ++t_p;
        }
        cnt[pos[t_q]][lvl] = t_p - from;
        ++t_q;
    }
    int p = from, q = mid, r = from;
    while (p != mid || q != to) {
        if (p != mid && (q == to || arr[p] <= arr[q])) {
            tmp[r] = arr[p];
            tmp_pos[r] = pos[p];
            ++r;
            ++p;
        } else {
            tmp[r] = arr[q];
            tmp_pos[r] = pos[q];
            ++r;
            ++q;
        }
    }
    for (int i = from; i < to; ++i) {
        arr[i] = tmp[i];
        pos[i] = tmp_pos[i];
    }
}

void
calc()
{
    merge_sort(0, (1 << n), n);
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 1; j <= n; ++j) {
            all_sum[j] += cnt[i][j];
            if (!(i & (1 << j - 1))) {
                cur_sum[j] += cnt[i][j];
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        ll res = 0LL;
        for (int j = 1; j <= q[i]; ++j) {
            cur_sum[j] = all_sum[j] - cur_sum[j];
        }
        for (int j = 1; j <= n; ++j) {
            res += cur_sum[j];
        }
        printf(LLD "\n", res);
    }
}

int
main()
{
#ifdef _DEBUG
    while (input_data()) {
#else
        input_data();
#endif
        calc();
#ifdef _DEBUG
    }
#endif
    return 0;
}