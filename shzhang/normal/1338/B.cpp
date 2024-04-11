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

using namespace std;

#define ll long long

vector<int> graph[100005];
bool has_0, has_1;
int n;
int ans;

void dfs(int node, int parent, int depth)
{
    if (graph[node].size() == 1) {
        if (depth % 2 == 0) {
            has_0 = true;
        } else {
            has_1 = true;
        }
    } else {
        int leaves = 0;
        for (int i = 0; i < graph[node].size(); i++) {
            int child = graph[node][i];
            if (child == parent) continue;
            if (graph[child].size() == 1) leaves++;
            dfs(child, node, depth+1);
        }
        if (leaves) ans -= leaves - 1;
    }
}

int main()
{
    scanf("%d", &n);
    ans = n - 1;
    for (int i = 1; i < n; i++) {
        int a, b; scanf("%d%d", &a, &b);
        graph[a].push_back(b); graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() > 1) {
            dfs(i, 0, 0); break;
        }
    }
    if (has_0 && has_1) {
        printf("3 ");
    } else {
        printf("1 ");
    }
    printf("%d", ans);
    return 0;
}