#include <cstdio>
#include <vector>
#include <utility>
//
using namespace std;

vector<int> graph[150005];
int ancestor[150005][20];
int depth[150005];
int weight[150005];
int subtree_dist[150005];
int subtree_same[150005];
int ans[150005];
int wtprod[150005];

pair<int, int> buffer[1200];

int n, q;

#define ll long long

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, int exponent)
{
    int Ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) Ans = mul(Ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return Ans;
}

void dfs(int node, int parent)
{
    depth[node] = depth[parent] + 1;
    ancestor[node][0] = parent;
    weight[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i] != parent) {
            dfs(graph[node][i], node);
            weight[node] += weight[graph[node][i]];
        }
    }
}

void dfs2(int node)
{
    ans[node] += subtree_same[node];
    if (ans[node] >= MOD) ans[node] -= MOD;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (child == ancestor[node][0]) continue;
        subtree_same[child] += mul(weight[child], subtree_dist[node]);
        if (subtree_same[child] >= MOD) subtree_same[child] -= MOD;
        subtree_same[child] += subtree_same[node];
        if (subtree_same[child] >= MOD) subtree_same[child] -= MOD;
        dfs2(child);
    }
    subtree_dist[node] = subtree_same[node] = 0;
}

int main()
{
    scanf("%d%d", &n, &q);
    int n_inv = fpow(n, MOD-2);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    for (int pwr = 1; pwr <= 17; pwr++) {
        for (int i = 1; i <= n; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
    int total_add = 0;
    while (q) {
        int cnt = min(q, 1100);
        int buffer_next = 0;
        for (int qry = 1; qry <= cnt; qry++) {
            int op = 0, v = 0, d = 0;
            scanf("%d%d", &op, &v);
            if (op == 1) {
                scanf("%d", &d);
                total_add += d;
                if (total_add >= MOD) total_add -= MOD;
                buffer[buffer_next] = make_pair(v, d);
                wtprod[buffer_next] = mul(d, n - weight[v]);
                buffer_next++;
            } else {
                ll subval = 0;
                //int curadd = total_add;
                for (int i = 0; i < buffer_next; i++) {
                    int modifynode = buffer[i].first;
                    int depthdiff = depth[v] - depth[modifynode];
                    int oldv = v;
                    if (v == modifynode) continue;
                    if (depthdiff > 0) {
                        depthdiff--;
                        for (int x = 0; (1 << x) <= depthdiff; x++) {
                            if (depthdiff & (1 << x)) v = ancestor[v][x];
                        }
                        //printf("add %lld\n", mul(buffer[i].second, weight[v]));
                        if (ancestor[v][0] == modifynode) {
                            subval += (ll)buffer[i].second * (ll)weight[v];
                            v = oldv; continue;
                        }
                        v = oldv;
                    }
                    //printf("add %lld\n", mul(buffer[i].second, n - weight[modifynode]));
                    subval += wtprod[i];
                }
                subval %= MOD;
                printf("%lld\n", ((total_add - mul(ans[v] + subval, n_inv)) % MOD + MOD) % MOD);
            }
        }
        q -= cnt;
        int whole_add = 0;
        for (int i = 0; i < buffer_next; i++) {
            pair<int, int> curmodify = buffer[i];
            whole_add += mul(curmodify.second, n - weight[curmodify.first]);
            if (whole_add >= MOD) whole_add -= MOD;
            subtree_dist[curmodify.first] += curmodify.second;
            subtree_dist[curmodify.first] %= MOD; subtree_dist[curmodify.first] += MOD;
            subtree_dist[curmodify.first] %= MOD;
            subtree_same[curmodify.first] -= mul(curmodify.second, n - weight[curmodify.first]);
            subtree_same[curmodify.first] %= MOD; subtree_same[curmodify.first] += MOD;
            subtree_same[curmodify.first] %= MOD;
        }
        dfs2(1);
        for (int i = 1; i <= n; i++) {
            ans[i] += whole_add;
            if (ans[i] >= MOD) ans[i] -= MOD;
        }
    }
    //for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}