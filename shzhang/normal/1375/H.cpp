#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <map>
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

#define GROUP_CNT 16

int n, q;
int a[5000];
int next_low[5000], next_high[5000];
int prev_low[5000], prev_high[5000];

map<pair<int, int>, int> block[20];

int nxt_op;
int from[20], to[20];
vector<pair<int, int> > op_seq;

int qry_ans[100000];
int prevblock[5000][20];
int nextblock[5000][20];

int add_op(int x, int y)
{
    op_seq.push_back(make_pair(x, y));
    nxt_op++; return nxt_op - 1;
}

void work(int val_l, int val_r, vector<int>& pos, map<pair<int, int>, int>& set_id)
{
    if (val_l == val_r) {
        set_id[make_pair(pos[0], pos[0])] = pos[0];
        return;
    }
    vector<int> low_pos, high_pos;
    map<pair<int, int>, int> low_set_id, high_set_id;
    for (int idx = 0; idx < pos.size(); idx++) {
        int i = pos[idx];
        if (a[i] <= (val_l + val_r) / 2) {
            low_pos.push_back(i);
        } else {
            high_pos.push_back(i);
        }
    }
    work(val_l, (val_l + val_r) / 2, low_pos, low_set_id);
    work((val_l + val_r) / 2 + 1, val_r, high_pos, high_set_id);
    for (int idx = 0; idx < pos.size(); idx++) {
        int i = pos[idx];
        if (a[i] <= (val_l + val_r) / 2) {
            prev_low[i] = i;
            prev_high[i] = (idx == 0 ? 0 : prev_high[pos[idx - 1]]);
        } else {
            prev_low[i] = (idx == 0 ? 0 : prev_low[pos[idx - 1]]);
            prev_high[i] = i;
        }
    }
    for (int idx = (int)pos.size() - 1; idx >= 0; idx--) {
        int i = pos[idx];
        if (a[i] <= (val_l + val_r) / 2) {
            next_low[i] = i;
            next_high[i] = (idx == ((int)pos.size() - 1) ? n + 1 : next_high[pos[idx + 1]]);
        } else {
            next_low[i] = (idx == ((int)pos.size() - 1) ? n + 1 : next_low[pos[idx + 1]]);
            next_high[i] = i;
        }
    }
    for (int idx1 = 0; idx1 < pos.size(); idx1++) {
        for (int idx2 = idx1; idx2 < pos.size(); idx2++) {
            int i = pos[idx1]; int j = pos[idx2];
            int l1 = next_low[i], r1 = prev_low[j];
            int l2 = next_high[i], r2 = prev_high[j];
            if (l1 <= r1 && l2 <= r2) {
                set_id[make_pair(i, j)] =
                    add_op(low_set_id[make_pair(l1, r1)],
                           high_set_id[make_pair(l2, r2)]);
            } else if (l1 <= r1) {
                set_id[make_pair(i, j)] = low_set_id[make_pair(l1, r1)];
            } else {
                set_id[make_pair(i, j)] = high_set_id[make_pair(l2, r2)];
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    nxt_op = n + 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int cur = 1;
    for (int i = 1; i <= GROUP_CNT; i++) {
        int blksiz = (n / GROUP_CNT) + ((i - 1 < n % GROUP_CNT) ? 1 : 0);
        if (!blksiz) continue;
        from[i] = cur;
        to[i] = cur + blksiz - 1;
        //debug("%d %d %d", i, from[i], to[i]);
        vector<int> pos_vec;
        for (int j = 1; j <= n; j++) {
            if (from[i] <= a[j] && a[j] <= to[i]) pos_vec.push_back(j);
        }
        work(from[i], to[i], pos_vec, block[i]);
        cur = to[i] + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= GROUP_CNT; j++) {
            if (from[j] <= a[i] && a[i] <= to[j]) {
                prevblock[i][j] = i;
            } else {
                prevblock[i][j] = prevblock[i-1][j];
            }
        }
    }
    for (int i = 1; i <= GROUP_CNT; i++) nextblock[n+1][i] = n + 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= GROUP_CNT; j++) {
            if (from[j] <= a[i] && a[i] <= to[j]) {
                nextblock[i][j] = i;
            } else {
                nextblock[i][j] = nextblock[i+1][j];
            }
        }
    }

    for (int qry = 1; qry <= q; qry++) {
        int l, r; scanf("%d%d", &l, &r);
        int curset = -1;
        for (int i = 1; i <= GROUP_CNT; i++) {
            int cur_l = nextblock[l][i];
            int cur_r = prevblock[r][i];
            if (cur_l <= cur_r) {
                //debug("query %d, value range %d: %d %d", qry, i, cur_l, cur_r);
                if (curset == -1) {
                    curset = block[i][make_pair(cur_l, cur_r)];
                } else {
                    curset = add_op(curset, block[i][make_pair(cur_l, cur_r)]);
                }
            }
        }
        qry_ans[qry] = curset;
    }

    printf("%d\n", nxt_op - 1);
    for (int i = 0; i < op_seq.size(); i++) {
        printf("%d %d\n", op_seq[i].first, op_seq[i].second);
    }
    for (int i = 1; i <= q; i++) {
        printf("%d ", qry_ans[i]);
    }
    return 0;
}