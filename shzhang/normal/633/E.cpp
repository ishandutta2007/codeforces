#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int v[1000005];
int c[1000005];

int rmq_v[1000005][20];
int rmq_c[1000005][20];

int n, k;

void rmq_prep(int* seq, int rmq[1000005][20])
{
    bool use_max = (seq == v);
    for (int i = 1; i <= n; i++) rmq[i][0] = seq[i];
    for (int pwr = 1; pwr < 20; pwr++) {
        for (int i = 1; i <= n; i++) {
            if (use_max) {
                rmq[i][pwr] = max(rmq[i][pwr-1], (i + (1 << (pwr - 1)) <= n ? rmq[i + (1 << (pwr-1))][pwr-1] : 0));
            } else {
                rmq[i][pwr] = min(rmq[i][pwr-1], (i + (1 << (pwr - 1)) <= n ? rmq[i + (1 << (pwr-1))][pwr-1] : 10000000));
            }
        }
    }
}

int log_2[1000005];
double fact_log[1000005];

int rmq(int rmq[1000005][20], int l, int r)
{
    bool use_max = (rmq == rmq_v);
    int log2val = log_2[r - l + 1];
    if (use_max) {
        //printf("max %d %d: %d\n", l, r, max(rmq[l][log2val], rmq[r - (1 << log2val) + 1][log2val]));
        return max(rmq[l][log2val], rmq[r - (1 << log2val) + 1][log2val]);
    } else {
        //printf("min %d %d: %d\n", l, r, min(rmq[l][log2val], rmq[r - (1 << log2val) + 1][log2val]));
        return min(rmq[l][log2val], rmq[r - (1 << log2val) + 1][log2val]);
    }
}

double C(int x, int y)
{
    return fact_log[x] - fact_log[y] - fact_log[x-y];
}

int score_seq[1000005];

int main()
{
    fact_log[0] = 0.0;
    for (int i = 1; i <= 1000000; i++) {
        fact_log[i] = fact_log[i-1] + log(i);
    }
    scanf("%d%d", &n, &k);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if ((1 << (cur + 1)) <= i) cur++;
        log_2[i] = cur;
        //printf("%d ", log_2[i]);
    }
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    rmq_prep(v, rmq_v);
    rmq_prep(c, rmq_c);
    for (int i = 1; i <= n; i++) {
        int l = i;
        int r = n;
        while (r - l >= 2) {
            int mid = (l + r) / 2;
            int v_val = rmq(rmq_v, i, mid) * 100;
            int c_val = rmq(rmq_c, i, mid);
            if (v_val == c_val) {
                l = r = mid;
            } else if (v_val < c_val) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int l_score = min(rmq(rmq_v, i, l) * 100, rmq(rmq_c, i, l));
        int r_score = min(rmq(rmq_v, i, r) * 100, rmq(rmq_c, i, r));
        score_seq[i] = max(l_score, r_score);
    }
    sort(score_seq + 1, score_seq + n + 1);
    double ans = 0.0;
    for (int i = 1; i <= n - k + 1; i++) {
        ans += (double)score_seq[i] * exp(C(n - i, k - 1) - C(n, k));
    }
    printf("%.12f", ans);
    return 0;
}