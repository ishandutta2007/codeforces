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
int a[1005][505];
bool valid[1005];

int freq[505];

vector<int> ans;

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)


int uf[500005];

int fin(int A)
{
    if (uf[A] == A) return A;
    return uf[A] = fin(uf[A]);
}

void un(int A, int b)
{
    A = fin(A); b = fin(b);
    if (A == b) return;
    uf[A] = b;
}

int fpow(int base, int exponent)
{
    int Ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) Ans = mul(Ans, cur);
        cur = mul(cur, cur);
        exponent >>= 1;
    }
    return Ans;
}

bool graph[1005][1005];
bool vis[1005];

void work()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) freq[j] = 0;
        for (int j = 1; j <= 2 * n; j++) {
            if (valid[j]) freq[a[j][i]]++;
        }
        for (int j = 1; j <= n; j++) {
            if (freq[j] == 1) {
                int loc = 0;
                for (int k = 1; k <= 2 * n; k++) {
                    if (valid[k] && a[k][i] == j) loc = k;
                }
                valid[loc] = false;
                for (int k = 1; k <= 2 * n; k++) {
                    if (!valid[k]) continue;
                    for (int l = 1; l <= n; l++) {
                        if (a[k][l] == a[loc][l]) {
                            valid[k] = false;
                        }
                    }
                }
                ans.push_back(loc);
                work(); return;
            }
        }
    }
    for (int i = 1; i <= 2 * n; i++) uf[i] = i;
    for (int i = 1; i <= 2 * n; i++) {
        if (!valid[i]) continue;
        for (int j = i + 1; j <= 2 * n; j++) {
            if (!valid[j]) continue;
            for (int k = 1; k <= n; k++) {
                if (a[i][k] == a[j][k]) {
                    un(i, j); graph[i][j] = graph[j][i] = true;
                }
            }
        }
    }
    int comps = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (valid[i] && fin(i) == i) comps++;
    }

    for (int i = 1; i <= 2 * n; i++) {
        if (vis[i]) continue;
        if (!valid[i]) continue;
        queue<int> que;
        que.push(i); vis[i] = true;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            bool good = true;
            for (int j = 0; j < ans.size(); j++) {
                int seq = ans[j];
                for (int k = 1; k <= n; k++) {
                    if (a[seq][k] == a[cur][k]) {
                        good = false; break;
                    }
                }
                if (!good) break;
            }
            if (good) ans.push_back(cur);
            for (int x = 1; x <= 2 * n; x++) {
                if (graph[cur][x] && !vis[x]) {
                    que.push(x);
                    vis[x] = true;
                }
            }
        }
    }
    printf("%d\n", fpow(2, comps));
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int d = 1; d <= t; d++) {
        ans.clear();
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) vis[i] = false;
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                graph[i][j] = false;
            }
        }
        for (int i = 1; i <= 2 * n; i++) {
            valid[i] = true;
            for (int j = 1; j <= n; j++) {
                scanf("%d", &(a[i][j]));
            }
        }
        work();
    }
    return 0;
}