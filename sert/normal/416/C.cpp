#include <cstdio>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 34;

struct group {
    int c, n, num;
};

bool cmp(const group &a, const group &b) {
    return a.c > b.c;
}

group g[N];
int ans[N], sum, kol, n, m, x;
set <pair<int, int> > s;
set <pair<int, int> > :: iterator it;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &g[i].n, &g[i].c);
        g[i].num = i;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        s.insert(make_pair(x, i + 1));
    }
    sort(g, g + n, cmp);

    //std::cerr << "ok\n";

    for (int i = 0; i < n; i++) {
        x = g[i].n;
        it = s.lower_bound(make_pair(x, -1));
        if (it == s.end())
            continue;
        ans[g[i].num] = it->second;
        sum += g[i].c;
        kol++;
        s.erase(it);
    }
    printf("%d %d\n", kol, sum);
    for (int i = 0; i < n; i++)
        if (ans[i])
            printf("%d %d\n", i + 1, ans[i]);
}