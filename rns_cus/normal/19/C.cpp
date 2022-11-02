#include<bits/stdc++.h>
using namespace std;
#define N 110000
#define inf 100000000
bool vis[N];
int a[N], n, ans[N];
map<int, int>mp, MP[N];
vector<int >v[N];
typedef pair<int, int > pii;
pii  p[N];
int cnt;
int find(int x) {
    if(mp[x]) return mp[x];
    ++ cnt;
    return mp[x] = cnt;
}
int dfs(int x, int y) {
    if(MP[x][y]) return MP[x][y] - 1;
    if(x >= n || y >= n) {MP[x][y] = 1;return 0;}
    if(a[x] != a[y]) {MP[x][y] = 1;return 0;}
    MP[x][y] = dfs(x + 1,  y + 1) + 2;
    return MP[x][y] - 1;
}
bool cmp(pii a, pii b) {
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}
int main() {
   // freopen("C.in","r",stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        int id = find(x);
        v[id].push_back(i);
    }
    for(int i = 1; i <= cnt; i ++) {
        int sz = v[i].size();
        for(int j = 0; j < sz; j ++) {
            for(int k = j + 1; k < sz; k ++) {
                int jj = v[i][j], kk = v[i][k];
                int res = dfs(jj, kk);
                if(res >= kk - jj) {ans[jj] = kk - jj; break;}
            }
            if(ans[v[i][j]] == 0)ans[v[i][j]] = inf;
        }
    }
    cnt = 0;
    for(int i = 0; i < n; i ++) if(ans[i] < inf) p[cnt ++] = pii(i, ans[i]);
    sort(p, p + cnt, cmp);
    int pre = 0;
    for(int i = 0; i < n; i ++) {
        pii w = p[i];
        if(w.second == inf) continue;
        if(w.first < pre) continue;
        pre = w.first + w.second;
    }
    printf("%d\n", n - pre);
    for(int i = pre; i < n; i ++) printf("%d ", a[i]);
    puts("");
    return 0;
}