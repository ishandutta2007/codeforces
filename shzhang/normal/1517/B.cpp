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

struct pos {
    int val, x, y;
};

bool operator<(pos a, pos b)
{
    return a.val < b.val;
}

int a[105][105];
int runner[105][105];
bool unused[105];

void work()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            runner[i][j] = 0;
        }
    }
    vector<pos> vals;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &(a[i][j]));
            pos p; p.val = a[i][j]; p.x = i; p.y = j;
            vals.push_back(p);
        }
    }
    sort(vals.begin(), vals.end());
    for (int i = 0; i < m; i++) {
        runner[vals[i].x][vals[i].y] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            unused[j] = true;
        }
        for (int j = 1; j <= m; j++) {
            if (runner[i][j]) unused[runner[i][j]] = false;
        }
        vector<int> usable;
        for (int j = 1; j <= m; j++) {
            if (unused[j]) usable.push_back(j);
        }
        for (int j = 1; j <= m; j++) {
            if (!runner[i][j]) {
                runner[i][j] = usable.back();
                usable.pop_back();
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                if (runner[i][k] == j) {
                    printf("%d ", a[i][k]);
                }
            }
        }
        printf("\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}