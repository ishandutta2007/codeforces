#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <map>
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

int n, m;

int a[1505][1505];
int b[1505][1505];

int col_order[1505];

int needs[1505];
bool unblocked[1505];

bool get_order(void)
{
    queue<int> todo;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i < n; i++) {
            if (a[i][j] > a[i+1][j]) needs[j]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!needs[i]) todo.push(i);
    }
    int nxt = 1;
    while (!todo.empty()) {
        int cur = todo.front(); todo.pop();
        for (int i = 1; i < n; i++) {
            if (a[i][cur] < a[i+1][cur] && !unblocked[i]) {
                unblocked[i] = true;
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] > a[i+1][j]) {
                        needs[j]--;
                        if (needs[j] == 0) todo.push(j);
                    }
                }
            }
        }
        col_order[nxt] = cur; nxt++;
        //printf("use %d\n", cur);
    }
    return nxt == m + 1;
}

struct Tree {
    map<int, Tree*> nxt;
    vector<int> rows;
};

Tree* root;

int main()
{
    root = new Tree;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        Tree* cur = root;
        for (int j = 1; j <= m; j++) {
            scanf("%d", &(b[i][j]));
            if (!cur->nxt.count(b[i][j])) {
                cur->nxt[b[i][j]] = new Tree;
            }
            cur = cur->nxt[b[i][j]];
        }
        cur->rows.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        Tree* cur = root;
        for (int j = 1; j <= m; j++) {
            scanf("%d", &(a[i][j]));
            if (!cur->nxt.count(a[i][j])) {
                printf("-1"); return 0;
            }
            cur = cur->nxt[a[i][j]];
        }
        if (cur->rows.empty()) {
            printf("-1"); return 0;
        }
        a[i][m + 1] = cur->rows[0];
        cur->rows.erase(cur->rows.begin());
    }
    //for (int i = 1; i <= n; i++) printf("%d\n", b[i][m + 1]);
    m++;
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }*/
    if (!get_order()) {
        printf("-1"); return 0;
    }
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        if (col_order[i] == m) break;
        ans.push_back(col_order[i]);
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}