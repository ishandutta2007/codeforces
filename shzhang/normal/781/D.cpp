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

uint32_t can_go[505][60][2][16]; /* 0 -> P first, 1 -> B first */
uint32_t can_come[505][60][2][16]; /* 0 -> P first, 1 -> B first */

int n, m;

bool cur_possible[505];
bool new_possible[505];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        can_go[u][0][t][v / 32] |= (1 << (v % 32));
        can_come[v][0][t][u / 32] |= (1 << (u % 32));
    }
    for (int pwr = 1; pwr < 60; pwr++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int kind = 0; kind <= 1; kind++) {
                    bool found = false;
                    for (int group = 0; group < 16; group++) {
                        if (can_go[i][pwr-1][kind][group] & can_come[j][pwr-1][1-kind][group]) {
                            found = true; break;
                        }
                    }
                    if (found) {
                        can_go[i][pwr][kind][j / 32] |= (1 << (j % 32));
                        can_come[j][pwr][kind][i / 32] |= (1 << (i % 32));
                    }
                }
            }
        }
    }
    ll ans = 0;
    int need_b = 0;
    cur_possible[1] = true;
    for (int pwr = 59; pwr >= 0; pwr--) {
        bool any_good = false;
        for (int i = 1; i <= n; i++) new_possible[i] = false;
        for (int i = 1; i <= n; i++) {
            if (!cur_possible[i]) continue;
            for (int j = 1; j <= n; j++) {
                if (can_go[i][pwr][need_b][j / 32] & (1 << (j % 32))) {
                    new_possible[j] = true; any_good = true;
                }
            }
        }
        if (any_good) {
            for (int i = 1; i <= n; i++) cur_possible[i] = new_possible[i];
            ans += (1LL << (ll)pwr);
            need_b = 1 - need_b;
        }
    }
    if (ans > 1000000000000000000) {
        printf("-1");
    } else {
        printf("%lld", ans);
    }
    return 0;
}