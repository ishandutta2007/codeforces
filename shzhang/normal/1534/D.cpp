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
int dist[2005];

set<pair<int, int> > edges;

void ask(int node)
{
    printf("? %d\n", node);
    fflush(stdout);
    for (int i = 1; i <= n; i++) {
        scanf("%d", dist + i);
        if (dist[i] == 1) {
            int x = node, y = i;
            if (x > y) swap(x, y);
            edges.insert(make_pair(x, y));
        }
    }
}

int main()
{
    scanf("%d", &n);
    ask(1);
    vector<int> odds, evens;
    for (int i = 2; i <= n; i++) {
        if (dist[i] % 2) {
            odds.push_back(i);
        } else {
            evens.push_back(i);
        }
    }
    vector<int>& vec = (odds.size() < evens.size() ? odds : evens);
    for (int i = 0; i < vec.size(); i++) {
        ask(vec[i]);
    }
    printf("!\n");
    while (!edges.empty()) {
        printf("%d %d\n", edges.begin()->first, edges.begin()->second);
        edges.erase(edges.begin());
    }
    return 0;
}