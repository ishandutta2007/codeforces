#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;

const int N = 200000+10;
typedef pair<int, int> pii;

int n, m;
int a[N], b[N];
LL c[N], s[N];
int color[N];
vector<int> G[N], v[N];
map<pii, LL> mp;

int vis[N];
void dfs(int u, int p) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i ++) {
        if (vis[G[u][i]]) continue;
        color[G[u][i]] = - color[u];
        dfs(G[u][i], u);
        v[u].push_back(G[u][i]);
    }
}
void cac(int u, int p) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); i ++) {
        if (vis[G[u][i]]) continue;
        cac(G[u][i], u);
        mp[make_pair(G[u][i], u)] = mp[make_pair(u, G[u][i])] = c[G[u][i]]-s[G[u][i]];
        s[u] += c[G[u][i]]-s[G[u][i]];
        s[G[u][i]] += c[G[u][i]]-s[G[u][i]];
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &c[i]);
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", &a[i], &b[i]);
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    color[1] = 1;
    dfs(1, -1);
    LL sumL = 0, sumR = 0;
    for (int i = 1; i <= n; i ++) {
        if (color[i] == 1) sumL += c[i];
        if (color[i] == -1)sumR += c[i];
    }
    //printf("%lld %lld\n", sumL, sumR);
    if ((sumL-sumR)%2) {
        return 0*printf("NO\n");
    }
    bool gou = 0;
    for (int i = 1; i <= m; i ++) {
        if (color[a[i]] == color[b[i]]) {
            gou = 1;
            if (color[a[i]] == 1) {
                mp[make_pair(b[i], a[i])] = mp[make_pair(a[i], b[i])] = (sumL-sumR)/2;
                c[a[i]] += (sumR-sumL)/2;
                c[b[i]] += (sumR-sumL)/2;
                break;
            } else {
                mp[make_pair(b[i], a[i])] = mp[make_pair(a[i], b[i])] = (sumR-sumL)/2;    
                c[a[i]] += (sumL-sumR)/2;
                c[b[i]] += (sumL-sumR)/2;
                break;
            }            
        }
    }
    if (sumL!=sumR && !gou) {
        return 0*printf("NO\n");
    }

    for (int i = 1; i <= n; i ++) vis[i] = 0;
    cac(1, -1);
    printf("YES\n");
    for (int i = 1; i <= m; i ++) {
        printf("%lld\n", mp[make_pair(a[i], b[i])]);
    }
}