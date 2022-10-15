#include <cstdio>
#include <vector>

using namespace std;

#define MOD 998244353
#define ll long long
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
#define add(var, val) (var) += (val); if ((var) >= MOD) (var) -= MOD
#define sub(var, val) (var) -= (val); if ((var) < 0) (var) += MOD

/* 0 - top excluded, 1 - top included but not fully satisfied
   2 - top included and satisfied

   f[i][0] = prod{f[child][0 or 2]}
   f[i][1] = sum{f[child][1 or 2] * f[all others][0 or 2]}
   f[i][2] = sum{f[subset >= 2][1 or 2] * f[all others][0 or 2]}
   */
int n;
int f[200005][3];
vector<int> tree[200005];

void dfs(int node)
{
    if (tree[node].size() == 0) {
        f[node][2] = 1; return;
    }
    int f_total = 1;
    f[node][0] = 1;
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i];
        dfs(child);
        f_total = mul(f_total, (f[child][0] + f[child][2]) % MOD + (f[child][1] + f[child][2]) % MOD);
        f[node][0] = mul(f[node][0], f[child][0] + f[child][2]);
    }

    vector<int> pprod(tree[node].size()), sprod(tree[node].size());
    int tmp = 1;
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i];
        pprod[i] = tmp; tmp = mul(tmp, f[child][0] + f[child][2]);
    }
    tmp = 1;
    for (int i = (int)(tree[node].size()) - 1; i >= 0; i--) {
        int child = tree[node][i];
        sprod[i] = tmp; tmp = mul(tmp, f[child][0] + f[child][2]);
    }
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i];
        add(f[node][1], mul(f[child][1] + f[child][2], mul(pprod[i], sprod[i])));
    }
    f[node][2] = f_total;
    sub(f[node][2], f[node][0]); sub(f[node][2], f[node][1]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        tree[p].push_back(i);
    }
    dfs(1);
    printf("%d", (f[1][0] + f[1][2]) % MOD);
    return 0;
}