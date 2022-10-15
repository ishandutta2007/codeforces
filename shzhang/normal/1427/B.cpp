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

char s[200005];

void work()
{
    int n, k; scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    bool has_win = false;
    int win_cnt = 0;
    int in_a_row = 0;
    int blk_cnt = 0;
    vector<int> conn;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'W') {
            has_win = true; win_cnt++;
            if (in_a_row) {
                conn.push_back(in_a_row);
            }
            if (i == 1 || s[i] != s[i-1]) blk_cnt++;
            in_a_row = 0;
        } else {
            if (has_win) {
                in_a_row++;
            }
        }
    }
    if (win_cnt == 0) {
        printf("%d\n", max(0, 2 * k - 1));
        return;
    }
    sort(conn.begin(), conn.end());
    win_cnt += k;
    win_cnt = min(win_cnt, n);
    for (int i = 0; i < conn.size(); i++) {
        //printf("%d ", conn[i]);
        if (conn[i] <= k) {
            k -= conn[i]; blk_cnt--;
        }
    }
    printf("%d\n", 2 * win_cnt - blk_cnt);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
    }
    return 0;
}