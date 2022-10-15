#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

char s[5005];

typedef int I;
#define rep(var, to) for (I var = 1; var <= (to); var++)
#define repv(vec, var) for (I var = 0; var < (vec).size(); var++)
#define repf(var, from, to) for (I var = (from); var <= (to); var++)
#define repd(var, from, to) for (I var = (from); var >= (to); var--)

vector<int> children[100005];
double f[100005];
int weight[100005];

void dfs1(int node)
{
    weight[node] = 1;
    repv(children[node], i) {
        dfs1(children[node][i]);
        weight[node] += weight[children[node][i]];
    }
}

void dfs2(int node)
{
    repv(children[node], i) {
        int child = children[node][i];
        f[child] = f[node] + 1.0 + (weight[node] - 1 - weight[child]) / 2.0;
        dfs2(child);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    repf(i, 2, n) {
        int p;
        scanf("%d", &p);
        children[p].push_back(i);
    }
    f[1] = 1.0;
    dfs1(1);
    dfs2(1);
    rep(i, n) printf("%.10f ", f[i]);
    return 0;
}