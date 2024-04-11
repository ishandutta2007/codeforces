#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define encode(city, day) ((city-1)*d+(day))

int n, m, d;

vector<int> graph[5000005];
bool open[100005][55];
int scc[5000005];
int nextscc = 1;
int stk[5000005];
bool onstack[5000005];
int idx[5000005];
int minid[5000005];
int stktop = 0;
int nextidx = 1;
int museumcnt[5000005];
int f[5000005];

int origgraph[5000005][2];

vector<int> museums;

void tarjan(int node)
{
    onstack[node] = true;
    minid[node] = nextidx;
    stk[stktop] = node; stktop++;
    idx[node] = nextidx; nextidx++;
    for (int i = 0; i < graph[(node - 1)/d+1].size(); i++) {
        int other = encode(graph[(node - 1)/d+1][i], (node - 1)%d+1 == d ? 1 : (node - 1)%d+2);
        if (!idx[other]) {
            tarjan(other);
            minid[node] = min(minid[node], minid[other]);
        } else if (onstack[other]) {
            minid[node] = min(minid[node], idx[other]);
        }
    }
    if (minid[node] == idx[node]) {
        while (1) {
            stktop--; scc[stk[stktop]] = nextscc;
            if (open[(stk[stktop] - 1) / d + 1][(stk[stktop] - 1) % d + 1])
                museums.push_back((stk[stktop] - 1) / d + 1);
            onstack[stk[stktop]] = false;
            if (stk[stktop] == node) break;
        }
        sort(museums.begin(), museums.end());
        for (int i = 0; i < museums.size(); i++) {
            if (i == 0 || museums[i] != museums[i-1]) museumcnt[nextscc]++;
        }
        museums.clear();
        nextscc++;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        for (int j = 1; j <= d; j++) {
            //graph[encode(u, j)].push_back(encode(v, j == d ? 1 : j+1));
            origgraph[encode(i, j)][0] = encode(u, j);
            origgraph[encode(i, j)][1] = encode(v, j == d ? 1 : j+1);
        }
    }
    for (int i = 1; i <= n; i++) {
        char s[55];
        scanf("%s", s + 1);
        for (int j = 1; j <= d; j++) {
            if (s[j] == '1') open[i][j] = true;
        }
    }
    for (int i = 1; i <= n * d; i++) {
        if (!idx[i]) tarjan(i);
        //if (stktop) printf("!");
    }
    /*for (int i = 1; i <= n * d; i++) {
        printf("%d ", scc[i]);
    }
    printf("\n");
    for (int i = 1; i <= n * d; i++) {
        printf("%d ", museumcnt[i]);
    }
    printf("\n");*/
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
    }
    for (int i = 1; i <= m * d; i++) {
        if (scc[origgraph[i][0]] != scc[origgraph[i][1]]) {
            graph[scc[origgraph[i][0]]].push_back(scc[origgraph[i][1]]);
            //printf("%d %d\n", scc[origgraph[i][1]], scc[origgraph[i][0]]);
        }
    }
    for (int i = 1; i < nextscc; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            f[i] = max(f[i], f[graph[i][j]]);
        }
        f[i] += museumcnt[i];
        //printf("f[%d] = %d\n", i, f[i]);
    }
    printf("%d", f[scc[1]]);
    return 0;
}