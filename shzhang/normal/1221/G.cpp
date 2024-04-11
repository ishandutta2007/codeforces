#include <cstdio>
//
using namespace std;

#define ll long long
#define lowbit(x) (x&(-(x)))

bool graph[45][45];
int uf[45];

bool indep_left[1050005];
bool indep_right[1050005];
int right_subset[1050005];
int log_2[1050005];

ll count_indset(void)
{
    indep_left[0] = true;
    for (int i = 1; i < (1 << 20); i++) {
        if (!indep_left[i ^ lowbit(i)]) continue;
        int lbit = log_2[lowbit(i)];
        bool good = true;
        for (int j = 0; j < 20; j++) {
            if (graph[lbit][j] && (i & (1 << j))) {
                good = false; break;
            }
        }
        indep_left[i] = good;
    }
    indep_right[0] = true;
    for (int i = 1; i < (1 << 20); i++) {
        if (!indep_right[i ^ lowbit(i)]) continue;
        int lbit = log_2[lowbit(i)];
        bool good = true;
        for (int j = 0; j < 20; j++) {
            if (graph[lbit+20][j+20] && (i & (1 << j))) {
                good = false; break;
            }
        }
        indep_right[i] = good;
    }
    int allow_set[25];
    for (int i = 0; i < 20; i++) {
        allow_set[i] = 0;
        for (int j = 20; j < 40; j++) {
            if (!graph[i][j]) allow_set[i] |= (1 << (j - 20));
        }
    }
    for (int i = 0; i < (1 << 20); i++) {
        right_subset[i] = indep_right[i];
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < (1 << 20); j++) {
            if (j & (1 << i)) right_subset[j] += right_subset[j^(1 << i)];
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1 << 20); i++) {
        if (!indep_left[i]) continue;
        int allow_mask = (1 << 20) - 1;
        for (int j = 0; j < 20; j++) {
            if (i & (1 << j)) {
                allow_mask &= allow_set[j];
            }
        }
        ans += right_subset[allow_mask];
    }
    return ans;
}

bool has_edge[45];
bool vis[45]; bool color[45];

int comps, bipartite_choices; bool is_bipartite = true;

void dfs(int node, bool clr)
{
    vis[node] = true; color[node] = clr;
    for (int nxt = 0; nxt < 40; nxt++) {
        if (!graph[node][nxt]) continue;
        if (!vis[nxt]) dfs(nxt, !clr);
        if (color[nxt] == clr) {
            is_bipartite = false;
        }
    }
    //return retv;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= 20; i++) log_2[1<<i] = i;
    if (m < 3) {
        printf("0"); return 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        has_edge[u-1] = has_edge[v-1] = true;
        graph[u-1][v-1] = true; graph[v-1][u-1] = true;
    }
    int no_edge_nodes = 0;
    for (int i = 0; i < 40; i++) if (!has_edge[i]) no_edge_nodes++;
    for (int i = 0; i < 40; i++) {
        if (!vis[i]) {
            comps++; dfs(i, false);
        }
    }
    /* ans40 = (1 << 40) - no_0s - no_1s - no_2s + only_0s + only_1s + only_2s */
    ll indsets = count_indset();
    //printf("%d", bipartite_choices);
    ll ans40 = (1LL << 40LL) - indsets * 2LL - (1LL << (ll)comps)
        + (2LL << (ll)no_edge_nodes)
        + (is_bipartite ? 1LL << (ll)comps : 0);
    ll ans = (ans40 >> (40LL - n));
    printf("%lld", ans);
    return 0;
}