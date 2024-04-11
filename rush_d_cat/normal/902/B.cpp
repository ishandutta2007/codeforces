#include <iostream>
#include <vector>
using namespace std;
const int N = 10000+10;
int n, x, res = 1;
vector<int> G[N];
int c[N];
void dfs(int x, int p) {
    for (int i=0;i<G[x].size(); i ++) {
        if (G[x][i] == p) continue;
        if (c[x] != c[G[x][i]]) res ++;
        dfs(G[x][i], x);
    }
}
int main() {
    scanf("%d", &n);
    for (int i=2;i<=n;i++) {
        scanf("%d", &x);
        G[x].push_back(i);
    }
    for (int i=1;i<=n;i++) {
        scanf("%d", &c[i]);
    }
    dfs(1, -1);
    printf("%d\n", res);
}