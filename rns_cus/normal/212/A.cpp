#include <bits/stdc++.h>
using namespace std;

struct dat{
    int x, rev, f, cap, cost;
    dat(int x = 0, int rev = 0, int f = 0, int cap = 0, int cost = 0):x(x), rev(rev), f(f), cap(cap), cost(cost) {}
};

#define N 5100
vector<dat> v[N];

void add(int s, int t, int ca, int co) {
    int n = v[s].size();
    int m = v[t].size();
    v[s].push_back(dat(t, m, 0, ca, co));
    v[t].push_back(dat(s, n, 0, 0, -co));
}
#define inf 1e9
typedef pair<int, int> pi;
priority_queue<pi> q;
pi pa[N];
int pot[N], vis[N], A[N * 10], dist[N], col[N][N], a[N], b[N], deg[N], deg1[N], fl[N];
int mx = 0;
int doit(int de) {
  int mxx = 0;
    for(int i = 0; i <= de; i ++) pot[i] = 0;
    pot[0] = 0;
	while(1) {
        for(int i = 0; i <= de; i ++) fl[de] = 0;
        for(int i = 0; i <= de; i ++) dist[i] = inf;
        dist[0] = 0;
        while(!q.empty()) q.pop();
        q.push(pi(0, 0));
        fl[0] = inf;
        while(!q.empty()) {
            pi aa = q.top();
            q.pop();
            int x = aa.second;
            if(-aa.first != dist[x]) continue;
            for(int i = 0; i < v[x].size(); i ++) {
                dat bb = v[x][i];
                if(bb.f == bb.cap) continue;
                int y = bb.x;
                int xx = dist[x] + bb.cost + pot[x] - pot[y];
                if(dist[y] > xx) {
                    dist[y] = xx;
                    q.push(pi(-dist[y], y));
                    pa[y] = pi(x, i);
                    fl[y] = min(fl[x], bb.cap - bb.f);
                }
            }
        }
        if(!fl[de]) break;
        mxx += fl[de];
        for(int i = 0; i <= de; i ++) pot[i] += dist[i];
        int x = de;
        while(1) {
            pi aa = pa[x];
            int y = aa.first;
            int id = aa.second;
            v[y][id].f += fl[de];
            v[x][v[y][id].rev].f -= fl[de];
            if(!y) break;
            x = y;
        }
	}
	return mxx;
}

int main() {
    //freopen("1.in", "r", stdin);
    int n, m, K, T;
    scanf("%d%d%d%d", &n, &m, &K, &T);
    for(int i = 1; i <= K; i ++) {
        scanf("%d%d", &a[i], &b[i]);
        deg[a[i]] ++;
        deg1[b[i]] ++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) ans += (deg[i] % T) > 0;
    for(int i = 1; i <= m; i ++) ans += (deg1[i] % T) > 0;
    printf("%d\n", ans);
    int so = 0;
    int de = m + n + 1;
    mx = 0;
    for(int i = T; i; i --) {
        for(int j = 0; j <= de; j ++) v[j].clear();
        for(int j = 1; j <= K; j ++) if(!col[a[j]][b[j]]) {
            add(a[j], b[j] + n, 1, 0);
        }
        int kt = 0;
        for(int j = 1; j <= n; j ++) {
            add(so, j, deg[j] / i, 0);
            kt += deg[j] / i;
            if(deg[j] % i) add(so, j, 1, 1);
        }
        int kt1 = 0;
        for(int j = 1; j <= m; j ++) {
            add(j + n, de, deg1[j] / i, 0);
            if(deg1[j] % i) add(j + n, de, 1, 1);
        }
        int mm = doit(de);
        mx += mm;
        for(int j = 1; j <= n; j ++) {
            for(int k = 0; k < v[j].size(); k ++) {
                dat aa = v[j][k];
                if(aa.x == so) continue;
                if(aa.f == 1) {
                    int y = aa.x;
                    if(y > n && y <= n + m) {
                        col[j][y - n] = i;
                        deg[j] --, deg1[y - n] --;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= K; i ++) printf("%d ", col[a[i]][b[i]]);
    puts("");

}