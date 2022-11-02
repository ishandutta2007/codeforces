#include <bits/stdc++.h>
using namespace std;
#define N 201000
typedef pair<int, int> pi;
vector<int> v[N];
vector<pi> edv[N];
pi arr[N], in[N];
int num, tot, cnt, gas;
int dis[N], low[N], vis[N], pa[N];
int Vis[N];
void dfs(int x, int p) {
    dis[x] = ++cnt;
    Vis[x] = 1;
    low[x] = cnt;
    for(int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if(y == p) continue;
        if(dis[y] < dis[x]) arr[num ++] = pi(x, y);
        if(dis[y]) {
            low[x] = min(low[x], dis[y]);
        } else {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if(low[y] >= dis[x]) {
                edv[++tot].clear();
                while(1) {
                    edv[tot].push_back(arr[num - 1]);
                    num --;
                    if(arr[num] == pi(x, y)) break;
                }
            }
        }
    }
}

void dfs1(int x, int p) {
    if(num) return ;
    vis[x] = 1;
    for(int i = 0; i < v[x].size(); i ++) {
        int y = v[x][i];
        if(y == p) continue;
        if(vis[y]) {
            in[num ++] = pi(x, y);
            return ;
        }
        pa[y] = x;
        dfs1(y, x);
    }
}

int a[N], cir[N], cir2[N], cir1[N];

void make_circle() {
    num = 0;
    gas = 0;
    pa[a[0]] = 0;
    dfs1(a[0], 0);
    if(!num) {
        return ;
    }
    int x = in[0].first;
    int y = in[0].second;
    for(int j = 0; j < cnt; j ++) vis[a[j]] = 0;
    int xx = x;
    int yy = y;
    while(xx) {
        vis[xx] = 1;
        xx = pa[xx];
    }
    while(yy) {
        if(vis[yy]) break;
        yy = pa[yy];
    }
    num = 0;
    xx = x;
    int cnt1 = 0;
    int cnt2 = 0;
    while(xx != yy) {
        cir1[cnt1 ++] = xx;
        xx = pa[xx];
    }
    int y1 = y;
    while(1) {
        cir2[cnt2 ++] = y1;
        if(y1 == yy) break;
        y1 = pa[y1];
    }
    for(int j = 0; j < cnt1; j ++) cir[gas ++] = cir1[j];
    for(int j = cnt2 - 1; j >= 0; j --) cir[gas ++] = cir2[j];
    for(int j = 0; j < cnt; j ++) vis[a[j]] = 0;
    for(int j = 0; j < gas; j ++) vis[cir[j]] = 1;
}

queue<int> q;
int A[N], ans[N];
int nex[N];

int main() {
    //freopen("1.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int I = 1; I <= n; I ++) if(!Vis[I]) {
        tot = num = cnt = 0;
        dfs(I, 0);
        bool ca = 0;
        for(int i = 1; i <= tot; i ++) {
            cnt = 0;
            for(int j = 0; j < edv[i].size(); j ++) {
                pi aa = edv[i][j];
                a[cnt ++] = aa.first;
                a[cnt ++] = aa.second;
            }
            sort(a, a + cnt);
            cnt = unique(a, a + cnt) - a;
            for(int j = 0; j < cnt; j ++) {
                int x = a[j];
                v[x].clear();
                vis[x] = 0;
            }
            for(int j = 0; j < edv[i].size(); j ++) {
                pi aa = edv[i][j];
                int x = aa.first;
                int y = aa.second;
                v[x].push_back(y);
                v[y].push_back(x);
            }
            make_circle();
            if(!gas) continue;
            for(int i = 0; i < gas - 1; i ++) nex[cir[i]] = cir[i + 1];
            nex[cir[gas - 1]] = cir[0];
            int st = -1;
            for(int j = 0; j < cnt; j ++) {
                int x = a[j];
                if(!vis[x]) continue;
                if(v[x].size() > 2) {
                    st = x;
                    break;
                }
            }
            if(st == -1) continue;
            for(int j = 0; j < cnt; j ++) pa[a[j]] = 0;
            while(!q.empty()) q.pop();
            int en = -1;
            q.push(st);
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                for(int j = 0; j < v[x].size(); j ++) {
                    int y = v[x][j];
                    if(y == pa[x]) continue;
                    if(pa[y]) continue;
                    if(!vis[y]) {
                        pa[y] = x; q.push(y);
                        continue;
                    }
                    if(x == st) {
                        if(y == nex[x] || nex[y] == x) continue;
                    }
                    pa[y] = x;en = y;
                    break;
                }
                if(en != -1) break;
            }
            if(en == -1) while(1);
            cnt = 0;
            int en1 = en;
            while(en != st) {
                ans[cnt ++] = en;
                en = pa[en];
            }
            ans[cnt ++] = st;
            puts("YES");
            printf("%d", cnt);
            for(int j = cnt - 1; j >= 0; j --) printf(" %d", ans[j]);
            puts("");
            en = en1;
            for(int j = 0; j < gas; j ++) {
                if(cir[j] == st) {
                    st = j;
                    break;
                }
            }
            for(int j = 0; j < gas; j ++) {
                if(cir[j] == en) {
                    en = j;
                    break;
                }
            }
            if(st > en) {
                printf("%d", st - en + 1);
                for(int j = st; j >= en; j --) printf(" %d", cir[j]);
                puts("");
                printf("%d", gas - (st - en - 1));
                for(int j = st; j < gas; j ++) printf(" %d", cir[j]);
                for(int j = 0; j <= en; j ++) printf(" %d", cir[j]);
                puts("");
            } else {
                printf("%d", en -st + 1);
                for(int j = st; j <= en; j ++) printf(" %d", cir[j]);
                puts("");
                printf("%d", gas - (en - st - 1));
                for(int j = st; j >= 0; j --) printf(" %d", cir[j]);
                for(int j = gas - 1; j >= en; j --) printf(" %d", cir[j]);
                puts("");
            }
            return 0;
        }
    }
    puts("NO");
    return 0;
}