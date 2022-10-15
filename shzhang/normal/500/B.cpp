#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

#define ll long long
int n;
vector<int> graph[305];

char s[305];

int perm[305];
bool vis[305];

void dfs(vector<int>& comp, int cur)
{
    vis[cur] = true; comp.push_back(cur);
    for (int i = 0; i < graph[cur].size(); i++) {
        int nxt = graph[cur][i];
        if (!vis[nxt]) dfs(comp, nxt);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", perm + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            if (s[j] == '1') {
                graph[i].push_back(j);
            }
        }
    }
    for (int c = 1; c <= n; c++) {
        if (vis[c]) continue;
        vector<int> comp;
        dfs(comp, c);
        sort(comp.begin(), comp.end());
        vector<int> vals;
        for (int i = 0; i < comp.size(); i++) vals.push_back(perm[comp[i]]);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < comp.size(); i++) perm[comp[i]] = vals[i];
    }
    for (int i = 1; i <= n; i++) printf("%d ", perm[i]);
    return 0;
}