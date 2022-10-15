#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long

int x[505];
int n, k;

pair<int, int> query(void)
{
    printf("? ");
    for (int i = 1; i <= k; i++) printf("%d ", x[i]);
    fflush(stdout);
    int pos, apos;
    scanf("%d%d", &pos, &apos);
    return make_pair(pos, apos);
}

bool same(bool a, bool b)
{
    return a == b;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++) x[i] = i;
    pair<int, int> base = query();
    x[base.first] = k + 1;
    pair<int, int> newres = query();
    bool is_greater = newres.second > base.second;
    x[base.first] = base.first;
    int ans = k;
    for (int i = 1; i <= k; i++) {
        if (i == base.first) continue;
        int old = x[i];
        x[i] = k + 1;
        pair<int, int> res = query();
        x[i] = old;
        bool greater = same(res.first == base.first, is_greater);
        if (greater) ans--;
    }
    printf("! %d\n", ans);
    return 0;
}