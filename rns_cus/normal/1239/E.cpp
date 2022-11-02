#include <bits/stdc++.h>
using namespace std;

#define N 55
#define M 2200120

int n, x[N], dp[M], pa[M][N];
bool vis[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i ++) scanf("%d", &x[i]);
    sort(x, x + 2 * n);
    int rlt = 0;
    rlt += x[0] + x[1];
    dp[0] = 1;

    for (int i = 2; i < 2 * n; i ++) {
        for (int s = M - x[i] - 1; ~s; s --) if (dp[s]) {
            for (int p = n - 2; ~p; p --) if (dp[s] >> p & 1) {
                if (dp[s+x[i]] >> p + 1 & 1);
                else dp[s+x[i]] |= (1 << p + 1), pa[s+x[i]][p+1] = i;
            }
        }
    }

    int S = 0;
    for (int i = 2; i < 2 * n; i ++) S += x[i];
    S = S + 1 >> 1;
    int k;
    for (k = S; ; k ++) if (dp[k] >> n - 1 & 1) break;
    vector <int> vec;
    int c = n - 1;
    while (c) {
        vec.push_back(pa[k][c]);
        k -= x[pa[k][c]], c --;
    }
    for (auto p : vec) vis[p] = 1; vis[0] = vis[1] = 1;
    vector <int> rem;
    for (int i = 0; i < 2 * n; i ++) if (!vis[i]) rem.push_back(i);
    assert(vec.size() == n - 1);
    assert(rem.size() == n - 1);
    sort(vec.begin(), vec.end(), greater <int> () );
    sort(rem.begin(), rem.end());
    printf("%d", x[0]);
    for (int i = 1; i < n; i ++) printf(" %d", x[rem[i-1]]); puts("");
    for (int i = 1; i < n; i ++) printf("%d ", x[vec[i-1]]); printf("%d\n", x[1]);
}