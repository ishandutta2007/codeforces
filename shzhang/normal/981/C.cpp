#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>
#include <random>
#include <chrono>

using namespace std;

#define ll long long

int n;
int deg[100005];
vector<int> graph[100005];
vector<pair<int, int> > ans;

int hcnt = 0; int hnode = 1;

void dfs(int node, int prt)
{
    if (node != hnode && deg[node] == 1) {
        ans.push_back(make_pair(hnode, node));
    }
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (child == prt) continue;
        dfs(child, node);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        deg[a]++; deg[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) {
            hcnt++; hnode = i;
        }
    }
    if (hcnt > 1) {
        printf("No"); return 0;
    }
    printf("Yes\n");
    dfs(hnode, 0);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}