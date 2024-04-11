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

bool eq[105][105][105];
vector<int> eqclass[105][105];
int clscnt[105];

char tmp[105];

vector<int> graph[105];
bool vis[105];

int edgecnt = 0;

int n;

int uf[105];

int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b)
{
    a = fin(a); b = fin(b);
    if (a == b) return;
    uf[a] = b;
}

void dfs1(int node, int prt)
{
    edgecnt++;
    un(node, prt);
    graph[node].push_back(prt);
    graph[prt].push_back(node);
    vis[node] = true;
    int clsid = -1;
    for (int cls = 0; cls < clscnt[node]; cls++) {
        for (int i = 0; i < eqclass[node][cls].size(); i++) {
            if (eqclass[node][cls][i] == prt) {
                clsid = cls; goto loop_end;
            }
        }
    }
loop_end:
    for (int i = 0; i < eqclass[node][clsid].size(); i++) {
        int nxt = eqclass[node][clsid][i];
        if (!vis[nxt]) {
            dfs1(nxt, node);
        }
    }
}

int depth[105][105];

void dfs2(int source, int node, int pre)
{
    depth[source][node] = depth[source][pre] + 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt != pre)
            dfs2(source, nxt, node);
    }
}

void work()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            scanf("%s", tmp + 1);
            for (int k = 1; k <= n; k++) {
                eq[i][i+j][k] = eq[i+j][i][k] = (tmp[k] == '1');
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool found = false;
            for (int k = 0; k < clscnt[i]; k++) {
                if (eq[eqclass[i][k].back()][j][i]) {
                    eqclass[i][k].push_back(j);
                    found = true; break;
                }
            }
            if (!found) {
                eqclass[i][clscnt[i]].push_back(j);
                clscnt[i]++;
            }
        }
    }

    bool good = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < clscnt[i]; j++) {
            for (int k = 0; k < eqclass[i][j].size(); k++) {
                for (int l = 0; l < clscnt[i]; l++) {
                    for (int m = 0; m < eqclass[i][l].size(); m++) {
                        if (j == l && k == m) continue;
                        bool eq1 = eq[eqclass[i][j][k]][eqclass[i][l][m]][i];
                        bool eq2 = (j == l);
                        if (eq1 != eq2) good = false;
                    }
                }
                //if (!eq[eqclass[i][j][k]][eqclass[i][j][k-1]][i]) good = false;
            }
        }
    }

    if (!good) {
        printf("No\n"); return;
    }

    for (int i = 0; i < clscnt[1]; i++) {
        edgecnt = 0;
        for (int j = 1; j <= n; j++) graph[j].clear();
        for (int j = 1; j <= n; j++) vis[j] = false;
        for (int j = 1; j <= n; j++) uf[j] = j;
        vis[1] = true;
        for (int j = 0; j < eqclass[1][i].size(); j++) {
            if (eqclass[1][i][j] != 1)
                dfs1(eqclass[1][i][j], 1);
        }
        good = true;
        if (edgecnt != n - 1) continue;
        for (int j = 2; j <= n; j++) {
            if (fin(j) != fin(1)) good = false;
        }
        if (!good) continue;
        for (int j = 1; j <= n; j++) {
            dfs2(j, j, 0);
        }

        for (int j = 1; j <= n; j++) {
            vector<int> deps;
            for (int k = 0; k < clscnt[j]; k++) {
                for (int l = 1; l < eqclass[j][k].size(); l++) {
                    if (depth[j][eqclass[j][k][l]] !=
                        depth[j][eqclass[j][k][l-1]]) good = false;
                }
                deps.push_back(depth[j][eqclass[j][k][0]]);
            }
            sort(deps.begin(), deps.end());
            for (int k = 1; k < deps.size(); k++) {
                if (deps[k] == deps[k-1]) good = false;
            }
        }
        if (good) {
            printf("Yes\n");
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < graph[j].size(); k++) {
                    int nxt = graph[j][k];
                    if (nxt > j) {
                        printf("%d %d\n", j, nxt);
                    }/* else {
                        printf("!%d %d\n", j, nxt);
                    }*/
                }
            }
            return;
        }
    }
    printf("No\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        work();
        for (int j = 1; j <= n; j++) {
            graph[j].clear();
            clscnt[j] = 0;
            for (int k = 0; k <= n; k++) {
                eqclass[j][k].clear();
            }
        }
    }
    return 0;
}