#include <cstdio>
#include <vector>
#include <algorithm>
//
using namespace std;
#define ll long long

#define INF 1000000000000000000LL
#define C2_internal(val) (((val) * ((val) - 1LL)) / 2LL)
#define C2(val) C2_internal(((ll)(val)))

#define x(val) weight[val]
#define y(val) (weight[val] * weight[val] + weight[val] + 2LL * f[val])

int n;
ll f[500005];
ll minp = INF;
vector<int> graph[500005];
ll weight[500005];

bool cmp(int a, int b)
{
    return x(a) < x(b) || (x(a) == x(b) && y(a) < y(b));
}

double slope(int n1, int n2)
{
    if (x(n2) == x(n1)) return (double)INF;
    return (double)(y(n2) - y(n1)) / (double)(x(n2) - x(n1));
}

void dfs(int node, int prt)
{
    weight[node] = 1;
    if (node != 1 && graph[node].size() == 1) return;
    vector<int> children;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (nxt == prt) continue;
        dfs(nxt, node); children.push_back(nxt);
        weight[node] += weight[nxt];
    }
    sort(children.begin(), children.end(), cmp);
    f[node] = INF;
    for (int i = 0; i < children.size(); i++) {
        int child = children[i];
        f[node] = min(f[node], C2(weight[node] - weight[child]) + f[child]);
        minp = min(minp, C2(n - weight[child]) + f[child]);
    }
    vector<int> hull;
    for (int i = 0; i < children.size(); i++) {
        int child = children[i];
        /*for (int j = i + 1; j < children.size(); j++) {
            int c2 = children[j];
            minp = min(minp, C2(n - weight[c1] - weight[c2]) + f[c1] + f[c2]);
        }*/
        if (i) {
            ll W = n - weight[child];
            int l = 0, r = hull.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (mid == hull.size() - 1 || slope(hull[mid], hull[mid + 1]) > (double)(2LL * W)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int other = hull[l];
            minp = min(minp, C2(n - weight[child] - weight[other]) + f[child] + f[other]);
        }

        while (hull.size() >= 2 &&
            slope(hull[hull.size() - 2], hull[hull.size() - 1]) > slope(hull[hull.size() - 1], child)) {
            hull.pop_back();
        }
        hull.push_back(child);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld", (ll)n * (ll)(n-1) - minp);
    return 0;
}