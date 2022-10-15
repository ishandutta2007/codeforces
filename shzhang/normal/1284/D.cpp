#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

int n;
int l1[100005], r1[100005];
int tmp1[100005]; int tmp2[100005]; int tmp3[100005]; int tmp4[100005];
int l2[100005], r2[100005];
int idx[100005];
int rmq1[300005][17];
int rmq2[300005][17];

int prev2pwr[300005];

bool cmp(int a, int b)
{
    return r1[a] < r1[b];
}

bool work(void)
{
    for (int i = 1; i <= n; i++) idx[i] = i;
    sort(idx + 1, idx + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        tmp1[i] = l1[idx[i]];
        tmp2[i] = l2[idx[i]];
        tmp3[i] = r1[idx[i]];
        tmp4[i] = r2[idx[i]];
    }
    for (int i = 1; i <= n; i++) {
        l1[i] = tmp1[i];
        l2[i] = tmp2[i];
        r1[i] = tmp3[i];
        r2[i] = tmp4[i];
    }
    /*for (int i = 1; i <= n; i++) {
        printf("%d %d %d %d\n", l1[i], r1[i], l2[i], r2[i]);
    }*/
    for (int i = 1; i <= n; i++) rmq1[i][0] = r2[i];
    for (int pwr = 1; pwr <= 16; pwr++) {
        for (int i = 1; i <= n; i++) {
            rmq1[i][pwr] = min(rmq1[i][pwr-1], rmq1[i + (1<<(pwr-1))][pwr-1]);
        }
    }
    for (int i = 1; i <= n; i++) rmq2[i][0] = l2[i];
    for (int pwr = 1; pwr <= 16; pwr++) {
        for (int i = 1; i <= n; i++) {
            rmq2[i][pwr] = max(rmq2[i][pwr-1], rmq2[i + (1<<(pwr-1))][pwr-1]);
        }
    }
    for (int pwr = 0; pwr <= 16; pwr++) {
        for (int i = (1 << pwr); i < (1 << (pwr+1)); i++) {
            prev2pwr[i] = pwr;
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l < r) {
            int mid = (l + r) / 2;
            if (r1[mid] >= l1[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int first_overlap = l;
        /* need minimum r2 and maximum l2 of region first_overlap...i-1 */
        if (first_overlap == i) continue;
        int intv_pwr2 = prev2pwr[i-first_overlap];
        int minr2 = min(rmq1[first_overlap][intv_pwr2], rmq1[i-(1<<intv_pwr2)][intv_pwr2]);
        int maxl2 = max(rmq2[first_overlap][intv_pwr2], rmq2[i-(1<<intv_pwr2)][intv_pwr2]);
        //printf("%d: %d %d\n", i, minr2, maxl2);
        if (minr2 < l2[i] || maxl2 > r2[i]) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d%d", l1 + i, r1 + i, l2 + i, r2 + i);
    }
    bool res1 = work();
    for (int i = 1; i <= n; i++) {
        int t = l1[i]; l1[i] = l2[i]; l2[i] = t;
        t = r1[i]; r1[i] = r2[i]; r2[i] = t;
    }
    bool res2 = work();
    printf("%s", res1 && res2 ? "YES" : "NO");
    return 0;
}