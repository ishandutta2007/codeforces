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

int a[1005][1005];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &(a[i][j]));
        }
    }
    vector<pair<int, int> > vec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < n) {
                if ((i % 4 == 0 && j % 4 == 0) ||
                    (i % 4 == 2 && j % 4 == 2)) {
                    vec.push_back(make_pair(i, j));
                }
            } else {
                int u = n - i; int v = n - j;
                if ((u % 4 == 1 && v % 4 == 3) ||
                    (u % 4 == 3 && v % 4 == 1)) {
                    vec.push_back(make_pair(i, j));
                }
            }
        }
    }
    int len = (int)vec.size();
    for (int i = 0; i < len; i++) {
        vec.push_back(make_pair(n - 1 - vec[i].second, vec[i].first));
    }
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        ans ^= a[vec[i].first][vec[i].second];
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}