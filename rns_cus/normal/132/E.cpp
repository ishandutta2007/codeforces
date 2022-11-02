#include <bits/stdc++.h>
using namespace std;
struct dat{
    int x, rev, f, cap, cos;
    dat(int x = 0, int rev = 0, int f = 0, int cap = 0, int cos = 0):x(x), rev(rev), f(f), cap(cap), cos(cos){}
};
#define inf 2100000

typedef pair<int, int> pi;

priority_queue<pi> q;
#define N 710
vector<dat> v[N];
void add(int x, int y, int ca, int co) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, ca, co));
    v[y].push_back(dat(x, n, 0, 0, -co));
}

int Gas(int x) {
    int ans = 0;
    while(x) {
        if(x & 1) ans ++;
        x /= 2;
    }
    return ans;
}
int a[N], b[N], vis[N], val[N], gas[N], dist[N], fl[N];
pi pa[N];

int main() {
    //freopen("E.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) {
        int x = a[i];
        gas[i] = Gas(x);
    }
    for(int i = 0; i < n; i ++) b[i] = a[i + 1];
    sort(b, b + n);
    int K = unique(b, b + n) - b;
    for(int i = 1; i <= n; i ++) a[i] = lower_bound(b, b + K, a[i]) - b;
    int so = 0;
    int de = m + n * 2 + 1;
    for(int i = 1; i <= m; i ++) {
        add(so, i, 1, 0);
        add(i, de, 1, 0);
        for(int j = 1; j <= n; j ++) add(i, m + j, 1, gas[j]);
    }
    for(int j = 1; j <= n; j ++) for(int k = j + 1; k <= n; k ++) {
        if(a[j] == a[k]) add(m + n + j, m + k, 1, 0);
        else add(m + n + j, m + k, 1, gas[k]);
    }
    for(int j = 1; j <= n; j ++) {
        add(m + j, m + n + j, 1, -1000);
        add(m + n + j, de, 1, 0);
    }

    int ans = 0;
    while(1) {
        for(int i = 0; i <= de; i ++) dist[i] = inf, fl[i] = 0;
        dist[0] = 0;
        while(!q.empty()) q.pop();
        q.push(pi(0, 0));
        fl[0] = inf;
        while(!q.empty()) {
            pi ab = q.top();
            q.pop();
            int x = ab.second;
            int yy = -ab.first;
            if(yy != dist[x]) continue;
            for(int i = 0; i < v[x].size(); i ++) {
                dat aa = v[x][i];
                if(aa.f == aa.cap) continue;
                int y = aa.x;
                if(dist[y] > dist[x] + aa.cos) {
                    dist[y] = dist[x] + aa.cos;
                    fl[y] = min(fl[x], aa.cap - aa.f);
                    pa[y] = pi(x, i);
                    q.push(pi(-dist[y], y));
                }
            }
        }
        if(!fl[de]) break;
        int xx = de;
        while(1) {
            pi aa = pa[xx];
            int y = aa.first;
            int id = aa.second;
            v[y][id].f += fl[de];
            v[xx][v[y][id].rev].f -= fl[de];
            ans += v[y][id].cos * fl[de];
            if(y == so) break;
            xx = y;
        }
    }
    ans += 1000 * n;
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    for(int i = 1; i <= m; i ++) {
        for(int j = 0; j < v[i].size(); j ++) {
            dat aa = v[i][j];
            if(aa.f) {
                if(aa.x == de) continue;
                val[aa.x - m] = i;
                vis[aa.x - m] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < v[i + m + n].size(); j ++) {
            dat aa = v[i + m + n][j];
            int k = aa.x;
            k -= m;
            if(k <= i) continue;
            if(aa.f) {
                val[k] = val[i];
                if(a[i] != a[k]) vis[k] = 1;
            }
        }
    }
    int ans1 = 0;
    for(int i = 1; i <= n; i ++) ans1 += vis[i];
    printf("%d %d\n", ans1 + n, ans);
    for(int i = 1; i <= n; i ++) {
        if(vis[i]) {
            printf("%c=%d\n", val[i] - 1 + 'a', b[a[i]]);
        }
        printf("print(%c)\n", val[i] - 1 + 'a');
    }
    return 0;

}