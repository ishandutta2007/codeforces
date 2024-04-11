#include <bits/stdc++.h>
using namespace std;
struct dat{
    int x, rev, f, cap, cos, id;
    dat(int x = 0, int rev = 0, int f = 0, int cap = 0, int cos = 0, int id = 0):x(x), rev(rev), f(f), cap(cap), cos(cos), id(id) {}
};
#define inf (1e9) + 100
typedef pair<int, int> pi;

priority_queue<pi> q;
#define N 3110
vector<dat> v[N];

void add(int x, int y, int ca, int co, int id) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, ca, co, id));
    v[y].push_back(dat(x, n, 0, 0, -co, id));
}

int a[N], b[N], vis[N], val[N], gas[N], fl[N];
pi pa[N];
int st[N], t[N], c[N];
int pot[N], dist[N];

int A[N * N];
int B[N * 2];
int main() {
    //freopen("2.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d%d%d", &st[i], &t[i], &c[i]);
    int cnt = 0;
    for(int i = 1; i <= n; i ++) B[cnt ++] = st[i], B[cnt ++] = st[i] + t[i];
    sort(B, B + cnt);
    cnt = unique(B, B + cnt) - B;
    add(0, 1, m, 0, 0);
    for(int i = 1; i <= n; i ++) {
        int x = lower_bound(B, B + cnt, st[i]) - B;
        int y = lower_bound(B, B + cnt, st[i] + t[i]) - B;
        add(x + 1, y + 1, 1, -c[i], i);
    }
    for(int i = 1; i <= cnt; i ++) add(i, i + 1, m, 0, 0);
    int so = 0;
    int de = cnt + 1;
    for(int i = 0; i <= de; i ++) pot[i] = inf;
    pot[0] = 0;
	int qt = 0;
	A[qt++] = 0;
	int nodes = de + 1;
	for(int i = 0; i <= de; i ++) vis[i] = 0;
	for (int qh = 0; (qh - qt) % nodes != 0; qh++) {
		int u = A[qh % nodes];
		vis[u] = false;
		for (int i = 0; i < (int) v[u].size(); i++) {
			dat e = v[u][i];
			if (e.cap == e.f) continue;
			int vv = e.x;
			int ndist = pot[u] + e.cos;
			if (pot[vv] > ndist) {
				pot[vv] = ndist;
				if (!vis[vv]) {
					vis[vv] = true;
					A[qt++ % nodes] = vv;
				}
			}
		}
	}

    int ans = 0;
    int mx = 0;
    while(1) {
        for(int i = 0; i <= de; i ++) fl[i] = 0;
        for(int i = 0; i <= de; i ++) dist[i] = inf;
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
                int xx = dist[x] + aa.cos + pot[x] - pot[y];
                if(dist[y] > xx) {
                    dist[y] = xx;
                    fl[y] = min(fl[x], aa.cap - aa.f);
                    pa[y] = pi(x, i);
                    q.push(pi(-dist[y], y));
                }
            }
        }
        if(!fl[de]) break;
        mx += fl[de];
        for(int i = 0; i <= de; i ++) pot[i] += dist[i];
        int xx = de;
        while(1) {
            pi aa = pa[xx];
            int y = aa.first;
            int id = aa.second;
            v[y][id].f += fl[de];
            v[xx][v[y][id].rev].f -= fl[de];
            ans += v[y][id].cos * fl[de];
            if(y == 0) break;
            xx = y;
        }
    }
    ans = -ans;
    for(int i = 1; i <= cnt; i ++) {
        for(int j = 0; j < v[i].size(); j ++) {
            dat aa = v[i][j];
            if(aa.f <= 0) continue;
            if(aa.cos >= 0) continue;
            if(aa.x <= i) continue;
            vis[aa.id] = 1;
        }
    }
    for(int i = 1; i <= n; i ++) printf("%d ", vis[i]);
    puts("");
    return 0;

}