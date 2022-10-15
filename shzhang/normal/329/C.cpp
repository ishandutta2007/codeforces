#include <cstdio>
#include <random>
#include <chrono>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int perm[100005];

set<int> nxt[100005];

int n, m;

int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        nxt[u].insert(v);
        nxt[v].insert(u);
    }
    for (int i = 1; i <= n; i++) perm[i] = i;
    for (int ty = 1; ty <= 350; ty++) {
        shuffle(perm + 1, perm + n + 1, rng);
        perm[n+1] = perm[1];
        bool good = true;
        for (int i = 1; i <= m; i++) {
            if (nxt[perm[i]].count(perm[i+1])) {
                good = false; break;
            }
        }
        if (!good) continue;
        for (int i = 1; i <= m; i++) {
            printf("%d %d\n", perm[i], perm[i+1]);
        }
        return 0;
    }
    printf("-1"); return 0;
}