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

int l, r;

vector<pair<int, int> > graph[40];

int nxtnode = 2; int m = 0;

void add(int f, int t, int len)
{
    //printf("%d %d %d\n", f, t, len);
    graph[f].push_back(make_pair(t, len)); m++;
}

int start = 1;

int build(int x)
{
    if (x == 0) return nxtnode - 1;
    if (x == 1) {
        int from = build(0);
        int n1 = nxtnode;
        add(from, n1, 1);
        nxtnode++;
        return n1;
    }
    if (x == 2) {
        int from = build(0);
        int n1 = nxtnode;
        int n2 = nxtnode + 1;
        add(from, n1, 1);
        add(n1, n2, 1);
        add(from, n2, 1);
        nxtnode += 2;
        return n2;
    }
    if (x == 3) {
        int from = build(0);
        int n1 = nxtnode;
        int n2 = nxtnode + 1;
        int n3 = nxtnode + 2;
        add(from, n1, 1);
        add(n1, n2, 1);
        add(n2, n3, 1);
        add(from, n2, 1);
        add(from, n3, 1);
        nxtnode += 3;
        return n3;
    }
    if (x == 4) {
        int from = build(0);
        int n1 = nxtnode;
        int n2 = nxtnode + 1;
        int n3 = nxtnode + 2;
        add(from, n1, 1);
        add(n1, n2, 1);
        add(n2, n3, 2);
        add(from, n2, 1);
        add(from, n3, 1);
        add(n1, n3, 1);
        nxtnode += 3;
        return n3;
    }
    if (x % 4 == 1 || x % 4 == 2) {
        int from = build(x / 4);
        int k = (x / 4 == 0 ? 1 : x / 4);
        int n1 = nxtnode + 1;
        int n2 = nxtnode;
        int n3 = nxtnode + 2;
        add(from, n1, 1);
        add(from, n2, k + 1);
        add(from, n3, 1);
        add(n1, n3, k);
        add(n2, n1, k);
        add(n2, n3, k);
        add(start, n3, 1);
        if (x % 4 == 2) {
            add(start, n1, 3 * k + 2);
        }
        nxtnode += 3;
        return n3;
    } else if (x % 4 == 0) {
        int from = build((x - 4) / 4);
        int k = ((x - 4) / 4 == 0 ? 1 : (x - 4) / 4);
        int n1 = nxtnode + 1;
        int n2 = nxtnode;
        int n3 = nxtnode + 2;
        add(from, n1, 2);
        add(from, n2, k + 3);
        add(from, n3, 1);
        add(n1, n3, k);
        add(n2, n1, k + 1);
        add(n2, n3, k);
        add(start, n3, 1);
        add(start, n1, 2);
        add(start, n2, k + 3);
        nxtnode += 3;
        return n3;
    } else {
        int from = build(x / 4);
        int k = (x / 4 == 0 ? 1 : x / 4);
        int n1 = nxtnode + 1;
        int n2 = nxtnode;
        int n3 = nxtnode + 2;
        add(from, n1, 1);
        add(from, n2, k);
        add(from, n3, 1);
        add(n1, n3, k);
        add(n2, n1, k + 3);
        add(n2, n3, k + 2);
        add(start, n3, 1);
        add(start, n2, k);
        nxtnode += 3;
        return n3;
    }
}

int main()
{
    scanf("%d%d", &l, &r);
    if (l > 1) {
        add(1, 2, l - 1);
        nxtnode++; start = 2;
    }
    build(r - l + 1);
    int  n = nxtnode - 1;
    printf("YES\n%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            printf("%d %d %d\n", i, graph[i][j].first, graph[i][j].second);
        }
    }
    return 0;
}