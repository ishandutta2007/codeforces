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

int n;
int x[100005], y[100005], c[100005];
int seq[100005];
int tmp[100005];

int x2[100005], y2[100005], c2[100005];

bool cmp(int a, int b)
{
    return x[a] < x[b];
}

bool cmp2(int a, int b)
{
    return y[a] < y[b];
}

void permute(int* arr)
{
    for (int i = 1; i <= n; i++) tmp[i] = arr[i];
    for (int i = 1; i <= n; i++) arr[i] = tmp[seq[i]];
}

void sort_by_x()
{
    for (int i = 1; i <= n; i++) seq[i] = i;
    sort(seq + 1, seq + n + 1, cmp);
    permute(x); permute(y); permute(c);
}

void sort_by_y()
{
    for (int i = 1; i <= n; i++) seq[i] = i;
    sort(seq + 1, seq + n + 1, cmp2);
    for (int i = 1; i <= n; i++) {
        x2[i] = x[seq[i]];
        y2[i] = y[seq[i]];
        c2[i] = c[seq[i]];
    }
    /*for (int i = 1; i <= n; i++) {
        printf("%d %d %d\n", x2[i], y2[i], c2[i]);
    }*/
}

bool check_t(int clr1, int cnt)
{
    if (cnt == 0) return true;
    int c1num = 0;
    int last = 0;
    while (c1num < cnt) {
        last++; if (c[last] == clr1) c1num++;
    }
    while (last < n && x[last + 1] == x[last]) last++;
    for (int clr2 = 1; clr2 <= 3; clr2++) {
        if (clr2 == clr1) continue;
        int clr3 = 1;
        while (clr3 == clr1 || clr3 == clr2) clr3++;
        int clr3_cnt = 0;
        for (int i = last + 1; i <= n; i++) {
            if (c[i] == clr3) clr3_cnt++;
        }
        int clr2_cur = 0, clr3_cur = 0;
        for (int i = 1; i <= n; i++) {
            if (x2[i] <= x[last]) continue;
            if (c2[i] == clr2) clr2_cur++;
            if (c2[i] == clr3) clr3_cur++;
            if (i == n || y2[i] < y2[i+1]) {
                if (clr2_cur >= cnt && clr3_cnt - clr3_cur >= cnt) return true;
            }
        }
    }
    return false;
}

int solve_t()
{
    sort_by_x();
    sort_by_y();
    int ans = 0;
    for (int clr1 = 1; clr1 <= 3; clr1++) {
        int l = 0, r = n / 3;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            if (check_t(clr1, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, l);
    }
    return ans;
}

bool check_p(int clr1, int cnt)
{
    if (cnt == 0) return true;
    int c1num = 0;
    int last = 0;
    while (c1num < cnt) {
        last++; if (c[last] == clr1) c1num++;
    }
    while (last < n && x[last + 1] == x[last]) last++;
    for (int clr2 = 1; clr2 <= 3; clr2++) {
        if (clr2 == clr1) continue;
        int clr3 = 1;
        while (clr3 == clr1 || clr3 == clr2) clr3++;
        int clr2_cur = 0, clr3_cur = 0;
        int clr3_cnt = 0;
        for (int i = last + 1; i <= n; i++) {
            if (c[i] == clr3) clr3_cnt++;
        }
        for (int i = last + 1; i <= n; i++) {
            if (c[i] == clr2) clr2_cur++;
            if (c[i] == clr3) clr3_cur++;
            if (i == n || x[i] < x[i+1]) {
                if (clr2_cur >= cnt && clr3_cnt - clr3_cur >= cnt) return true;
            }
        }
    }
    return false;
}

int solve_p()
{
    sort_by_x();
    int ans = 0;
    for (int clr1 = 1; clr1 <= 3; clr1++) {
        int l = 0, r = n / 3;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            if (check_p(clr1, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, l);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", x + i, y + i, c + i);
    int ans = max(solve_t(), solve_p());
    for (int i = 1; i <= n; i++) x[i] = -x[i];
    ans = max(ans, solve_t());
    for (int i = 1; i <= n; i++) swap(x[i], y[i]);
    ans = max(ans, max(solve_t(), solve_p()));
    for (int i = 1; i <= n; i++) x[i] = -x[i];
    ans = max(ans, solve_t());
    printf("%d", ans * 3);
    return 0;
}