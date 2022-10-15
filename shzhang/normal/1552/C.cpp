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

bool used[205];

void work()
{
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= 2 * n; i++) used[i] = false;
    vector<pair<int, int> > edges;
    for (int i = 1; i <= k; i++) {
        int u, v; scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        edges.push_back(make_pair(u, v));
        used[u] = used[v] = true;
    }
    vector<int> left, right;
    for (int i = 1; i <= 2 * n; i++) {
        if (!used[i]) {
            if (left.size() >= n - k) {
                right.push_back(i);
            } else {
                left.push_back(i);
            }
        }
    }
    for (int i = 0; i < n - k; i++) {
        edges.push_back(make_pair(left[i], right[i]));
    }
    int ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        //printf("%d %d\n", edges[i].first, edges[i].second);
        for (int j = 0; j < i; j++) {
            if (edges[i].first < edges[j].first && edges[j].first < edges[i].second && edges[i].second < edges[j].second) ans++;
            if (edges[j].first < edges[i].first && edges[i].first < edges[j].second && edges[j].second < edges[i].second) ans++;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}