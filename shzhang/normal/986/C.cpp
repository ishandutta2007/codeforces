#include <cstdio>
#include <queue>

using namespace std;

bool inset[4200000];
bool vis[4200000];
bool vissub[4200000];

int n, m;

void find_nxt(int mask, queue<int>& bfs)
{
    if (vissub[mask]) return;
    vissub[mask] = true;
    if (inset[mask] && !vis[mask]) {
        //printf("%d ", mask);
        vis[mask] = true; bfs.push(mask);
    }
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            find_nxt(mask ^ (1 << i), bfs);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int val; scanf("%d", &val);
        inset[val] = true;
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (!inset[i]) continue;
        if (vis[i]) continue;
        //printf("%d ", i);
        vis[i] = true;
        queue<int> bfs;
        bfs.push(i);
        while (!bfs.empty()) {
            int val = bfs.front();
            bfs.pop();
            find_nxt((1 << n) - 1 - val, bfs);
        }
        ans++;
        //printf("\n");
    }
    printf("%d", ans);
    return 0;
}