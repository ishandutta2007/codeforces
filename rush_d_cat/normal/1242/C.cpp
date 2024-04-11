#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n, k;
LL a[20][5002], c[20], vis[N], done[N];
pair<LL,LL> p[N];
LL sum[20];

map<LL,LL> mp, id;
LL nex[N];
vector< pair<LL,LL> > it[1<<15];

void dfs(int u) {
    int now = u, mask = 0;
    vector< pair<LL,LL> > tmp;
    //printf("dfs %d\n", u);
    //printf("############\n");
    vector<int> used;
    bool M[20] = {0};

    while (now) {
        vis[now] = 1; used.push_back(now);
        if (M[ p[now].first ] == 1) return ;
        M[ p[now].first ] = 1;
        //printf("now = %d\n", now);
        mask |= 1<<(p[now].first - 1);
        tmp.push_back(p[now]);
        now = nex[now];
        if (vis[now] == 1) {
            if (now == u) {
                if (!done[mask]) {
                    //printf("!!!!\n");
                    done[mask] = 1;
                    it[mask] = tmp;
                    //printf("%d\n", mask);
                    //printf("# %d\n", tmp.size());
                }
            } 
            for(auto x: used) vis[x] = 0;
            return;
        }
    }
}

int dp[1<<15], pre[1<<15];
pair<int,int> ans[N];
void solve() {
    dp[0] = 1;
    for(int mask=1;mask<1<<n;mask++) {
        for(int sub=mask;;sub=(sub-1)&mask) {
            if (dp[sub] && done[mask ^ sub]) {
                dp[mask] = 1; pre[mask] = sub;
            }
            if (!sub) break;
        }
    }
    if (!dp[(1<<n) - 1]) {
        printf("No\n"); return;
    }
    printf("Yes\n");
    int now = (1<<n) - 1;
    while (now) {
        int tmp = now ^ pre[now];
        now = pre[now];
        reverse(it[tmp].begin(), it[tmp].end());
        int sz = it[tmp].size();
        for (int i=0;i<sz;i++) {
            //printf("%d %d\n", a[ it[tmp][i].first ][ it[tmp][i].second ], it[tmp][(i+1)%sz].first);
            ans[ it[tmp][i].first ] = make_pair( a[ it[tmp][i].first ][ it[tmp][i].second ], it[tmp][(i+1)%sz].first);
        }
    }
    for (int i = 1; i <= n; i ++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}

int main() {
    scanf("%d", &n);
    LL s=0; int rk = 0;
    for(int i=1;i<=n;i++){ 
        scanf("%lld",&c[i]);
        for(int j=1;j<=c[i];j++){
            scanf("%lld",&a[i][j]);  id[a[i][j]] = ++rk; p[rk] = make_pair(i, j);
            mp[a[i][j]] = i; s += a[i][j]; sum[i] += a[i][j];
        }
    }
    if (s%n != 0) {
        return !printf("No\n");
    }
    s /= n;
    //printf("%lld\n", s);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c[i];j++){
            LL need = s - (sum[i] - a[i][j]);
            if (mp[need]) {
                if (need != a[i][j] && mp[need] == i) continue;
                nex[id[a[i][j]]] = id[need];
                //printf("nex %d = %d\n", id[a[i][j]], id[need]);
            }
        }
    }
    for(int i=1;i<=rk;i++){
        dfs(i);
    }
    solve();
    return 0;
}