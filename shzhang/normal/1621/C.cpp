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

int p[10005];
bool found[10005];

//int opcnt = 0;

int query(int pos)
{
    //opcnt++;
    printf("? %d\n", pos);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void work()
{
    int n; scanf("%d", &n);
    //opcnt = 0;
    for (int i = 1; i <= n; i++) found[i] = false;
    for (int i = 1; i <= n; i++) {
        if (found[i]) continue;
        set<int> vals; vector<int> cycle;
        while (true) {
            int val = query(i);
            if (vals.count(val)) break;
            vals.insert(val); cycle.push_back(val);
            found[val] = true;
        }
        for (int j = 0; j + 1 < cycle.size(); j++) {
            p[cycle[j]] = cycle[j+1];
        }
        p[cycle.back()] = cycle[0];
    }
    printf("! ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n"); fflush(stdout);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}