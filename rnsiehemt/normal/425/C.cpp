#include <cstdio>
#include <algorithm>
#include <vector>

const int inf = 999999999;

int A, B, S, E;
int a[100005];
int b[100005];
std::vector<int> next[100005];
int best[305];
int ans;

int main()
{
    scanf("%d%d%d%d", &A, &B, &S, &E);
    for (int i = 0; i < A; i++) scanf("%d", &a[i]);
    for (int i = 0; i < B; i++) scanf("%d", &b[i]);

    for (int i = 0; i < B; i++) next[b[i]].push_back(i);

    std::fill(best, best+303, inf);
    best[0] = -1;

    for (int i = 0; i < A; i++) {
        for (int k = 301; k >= 0; k--) {
            int j = std::upper_bound(next[a[i]].begin(), next[a[i]].end(), best[k]) - next[a[i]].begin();
            if (j != next[a[i]].end() - next[a[i]].begin()) {
                if (next[a[i]][j] < best[k+1]) {
                    best[k+1] = next[a[i]][j];
                    if (E*(k+1) + (i+1) + (next[a[i]][j] + 1) <= S) {
                        ans = std::max(ans, k+1);
                    }
                }
            }
        }
    }

    printf("%d\n", ans);
}