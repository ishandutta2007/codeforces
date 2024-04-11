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

int n, k;
int a[1200000];
bool used[1200000];
bool isodd[1200000];

int max_nxt[1200000];
set<pair<int, int> > max_set;

void update_max(int x)
{
    int maxv = -10000;
    for (int i = 0; i < n; i++) {
        int y = (x ^ (1 << i));
        if (used[y]) continue;
        maxv = max(maxv, a[x] + a[y]);
    }
    max_set.erase(make_pair(-max_nxt[x], x));
    max_nxt[x] = maxv;
    if (maxv != -10000) {
        max_set.insert(make_pair(-max_nxt[x], x));
    }
}

int odd_used[250], even_used[250];
int even_enter[250], odd_exit[250];
int match[1200000];
int odd_exit_node[1200000];

bool dfsvis[1200000];
int chosen[1200000];

int dfs(int node)
{
    int ans = -1000000000;
    dfsvis[node] = true;
    if (isodd[node]) ans = max(ans, odd_exit_node[node]);
    for (int i = 0; i < n; i++) {
        int nxt = (node ^ (1 << i));
        if (!used[nxt] || dfsvis[nxt]) continue;
        if (!isodd[node] && match[nxt] != node) continue;
        if (isodd[node] && nxt == match[node]) continue;
        int nans = dfs(nxt);
        if (nans > ans) {
            chosen[node] = nxt; ans = nans;
        }
    }
    return ans;
}

void dfsvis_cleanup(int round)
{
    for (int i = 1; i < round; i++) {
        dfsvis[even_used[i]] = dfsvis[odd_used[i]] = false;
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < (1 << n); i++) {
        scanf("%d", a + i);
        int popcnt = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) popcnt++;
        }
        if (popcnt % 2) isodd[i] = true;
    }
    if (k * 2 >= (1 << n)) {
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) ans += a[i];
        printf("%d", ans); return 0;
    }
    for (int i = 0; i < (1 << n); i++) {
        if (!isodd[i]) continue;
        int maxv = 0;
        for (int j = 0; j < n; j++) {
            maxv = max(maxv, a[i] + a[i ^ (1 << j)]);
        }
        max_nxt[i] = maxv;
        max_set.insert(make_pair(-maxv, i));
    }
    for (int round = 1; round <= k; round++) {
        int best_new = -1000000000;
        int best_x = -1, best_y = -1;
        bool is_path = false;
        if (!max_set.empty()) {
            pair<int, int> pr = *max_set.begin();
            best_new = -pr.first; best_x = pr.second;
            for (int i = 0; i < n; i++) {
                if (!used[best_x ^ (1 << i)] && a[best_x ^ (1 << i)] == best_new - a[best_x]) {
                    best_y = (best_x ^ (1 << i)); break;
                }
            }
            if (best_y == -1) abort();
        }
        for (int i = 1; i < round; i++) {
            odd_exit[i] = even_enter[i] = -1000000000;
            for (int j = 0; j < n; j++) {
                if (!used[odd_used[i] ^ (1 << j)]) {
                    odd_exit[i] = max(odd_exit[i], a[odd_used[i] ^ (1 << j)]);
                }
                if (!used[even_used[i] ^ (1 << j)]) {
                    even_enter[i] = max(even_enter[i], a[even_used[i] ^ (1 << j)]);
                }
            }
            odd_exit_node[odd_used[i]] = odd_exit[i];
        }
        for (int i = 1; i < round; i++) {
            int max_exit = dfs(even_used[i]);
            dfsvis_cleanup(round);
            if (best_new < even_enter[i] + max_exit) {
                best_new = even_enter[i] + max_exit;
                best_x = even_used[i]; is_path = true;
            }
        }
        if (is_path) {
            /*for (int i = 0; i < (1 << n); i++) {
                fprintf(stderr, "%d ", match[i]);
            }
            debug("%d %d", best_new, best_x);*/
            dfs(best_x);
            dfsvis_cleanup(round);
            /*for (int i = 0; i < (1 << n); i++) {
                fprintf(stderr, "%d ", chosen[i]);
            }*/
            int from = -1, to = -1;
            for (int i = 0; i < n; i++) {
                int nxt = (best_x ^ (1 << i));
                if (used[nxt]) continue;
                if (from == -1 || a[nxt] > a[from]) {
                    from = nxt;
                }
            }
            //debug("%d", from);
            match[from] = best_x;
            while (true) {
                if (isodd[best_x]) match[best_x] = chosen[best_x];
                best_x = chosen[best_x];
                if (isodd[best_x]) {
                    for (int i = 0; i < n; i++) {
                        int nxt = (best_x ^ (1 << i));
                        //if (nxt == 3) debug("HERE %d %d", a[nxt], a[from]);
                        if (used[nxt]) continue;
                        if (a[nxt] + a[from] == best_new) {
                            to = nxt; match[best_x] = nxt; goto loop_exit;
                        }
                    }
                }
            }
        loop_exit:
            best_x = from; best_y = to;
        } else {
            match[best_x] = best_y;
        }
        odd_used[round] = best_x;
        even_used[round] = best_y;
        used[best_x] = used[best_y] = true;
        for (int i = 0; i < n; i++) {
            if (!used[best_y ^ (1 << i)])
                update_max(best_y ^ (1 << i));
        }
        max_set.erase(make_pair(-max_nxt[best_x], best_x));
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (used[i]) ans += a[i];
        //printf("%d ", match[i]);
    }
    printf("%d", ans);
    return 0;
}