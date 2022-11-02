#include <bits/stdc++.h>
using namespace std;
int cnt;
int gas;
#define N 101000
vector<int> v[N];
int col[N], vis[N], deg[N], redeg[N], redeg1[N];

struct cmp {
    bool operator ()(const int &i, const int &j) const{
        long long xx = 1ll * redeg1[i] * deg[j];
        long long yy = 1ll * redeg1[j] * deg[i];
        if(xx != yy) return xx < yy;
        return i < j;
    }
};

set<int, cmp> S;
set<int, cmp> :: iterator it;

int n;
#define ep 1e-8

bool can(double val) {
    S.clear();
    for(int i = 1; i <= n; i ++) if(!vis[i]) {
        redeg1[i] = redeg[i];
        S.insert(i);
    }
    while(1) {
        if(S.empty()) return false;
        it = S.begin();
        int x = *it;
        if(1.0 * redeg1[x] / deg[x] > val - ep) return true;
        it = S.end();
        it --;
        int y = *it;
        if(1.0 * redeg1[y] / deg[y]  < val - ep) return false;
        S.erase(x);
        for(int i = 0; i < v[x].size(); i ++) {
            y = v[x][i];
            if(vis[y]) continue;
            it = S.find(y);
            if(it == S.end()) continue;
            S.erase(it);
            redeg1[y] --;
            S.insert(y);
        }
    }
}


int ans[N];
int b[N];
int main() {
    //freopen("1.in", "r", stdin);
    int m, K, x, y;
    scanf("%d%d%d", &n, &m, &K);
    int num = 0;
    for(int i = 1; i <= K; i ++) scanf("%d", &b[i]), vis[b[i]] = 1;
    for(int i = 1; i <= m; i ++) {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
        deg[y] ++;
        deg[x] ++;
    }
    for(int i = 1; i <= n; i ++) redeg[i] = deg[i];
    for(int i = 1; i <= K; i ++) {
        x = b[i];
        for(int j = 0; j < v[x].size(); j ++) {
            y = v[x][j];
            redeg[y] --;
        }
    }
    gas = n - K;
    bool ok = true;
    for(int i = 1; i <= n; i ++) if(!vis[i]) {
        if(deg[i] != redeg[i]) {
            ok = false;
            break;
        }
    }
    if(ok) {
        printf("%d\n", n - K);
        for(int i = 1; i <= n; i ++) if(!vis[i]) printf("%d ", i);
        puts("");
        return 0;
    }
    double st = 0;
    S.clear();
    for(int i = 1; i <= n; i ++) redeg1[i] = redeg[i];
    for(int i = 1; i <= n; i ++) if(!vis[i]){
        S.insert(i);
    }
    while(1) {
        if(S.empty()) break;
        it = S.begin();
        int x = *it;
        double xx = 1.0 * redeg1[x] / deg[x];
        if(xx > st + ep) st = xx;
        S.erase(x);
        for(int i = 0; i < v[x].size(); i ++) {
            y = v[x][i];
            it = S.find(y);
            if(it == S.end()) continue;
            S.erase(it);
            redeg1[y] --;
            S.insert(y);
        }
    }
    can(st);
    gas = 0;
    for(it = S.begin(); it != S.end(); it ++) {
        ans[gas ++] = *it;
    }
    sort(ans, ans + gas);
    printf("%d\n", gas);
    for(int i = 0; i < gas; i ++) printf("%d ", ans[i]);
    puts("");
    return 0;

}