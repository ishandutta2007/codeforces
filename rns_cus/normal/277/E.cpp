#include <bits/stdc++.h>
using namespace std;
#define ep 1e-9
#define inf 1e9
double fab(double x) {
    return x < -ep? -x:x;
}

typedef pair<double, int> pd;
typedef pair<int, int> pi;
priority_queue<pd> q;
#define N 1100
struct dat{
    int x, rev, f, cap;
    double cost;
    dat(int x = 0, int rev = 0, int f = 0, int cap = 0, double cost = 0):x(x), rev(rev), f(f), cap(cap), cost(cost){}
};

vector<dat> v[N];

void add(int x, int y, int cap, double co) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, cap, co));
    v[y].push_back(dat(x, n, 0, 0, -co));
}

int x[N], y[N], n;
double dis[N][N], dist[N], pot[N], A[N * 2];
pi pa[N];
int fl[N], gas[N * 2], vis[N];

int main() {
    //freopen("1.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d%d", &x[i], &y[i]);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) {
        dis[i][j] = 1.0 * (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        dis[i][j] = sqrt(dis[i][j]);
    }
    for(int i = 1; i <= n; i ++) gas[y[i] + 1000] ++;
    for(int i = 2000; i >= 0; i --) if(gas[i]) {
        if(gas[i] > 1) {
            puts("-1");
            return 0;
        }
        int num = 2;
        for(int j = i - 1; j >= 0; j --) if(gas[j]) {
            if(gas[j] > num) {
                puts("-1");
                return 0;
            }
            num += gas[j];
        }
        break;
    }
    int so = 0;
    int de = n * 2 + 1;
    for(int i = 1; i <= n; i ++) add(0, i, 2, 0);
    for(int i = 1; i <= n; i ++) add(i + n, de, 1, 0);
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) if(y[i] > y[j]) {
        add(i, j + n, 1, dis[i][j]);
    }
    for(int i = 0; i <= de; i ++) pot[i] = inf;
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
			double ndist = pot[u] + e.cost;
			if (pot[vv] > ndist + ep) {
				pot[vv] = ndist;
				if (!vis[vv]) {
					vis[vv] = true;
					A[qt++ % nodes] = vv;
				}
			}
		}
	}
	double ans = 0;
	while(1) {
        for(int i = 0; i <= de; i ++) dist[i] = inf, fl[i] = 0;
        dist[0] = 0, fl[0] = inf;
        while(!q.empty()) q.pop();
        q.push(pd(0, 0));
        while(!q.empty()) {
            pd ab = q.top();
            q.pop();
            int x = ab.second;
            double di = ab.first;
            if(di > dist[x] + ep) continue;
            for(int i = 0; i < v[x].size(); i ++) {
                dat aa = v[x][i];
                int y = aa.x;
                if(aa.f == aa.cap) continue;
                double d = dist[x] + aa.cost + pot[x] - pot[y];
                if(d < dist[y] - ep) {
                    dist[y] = d;
                    pa[y] = pi(x, i);
                    fl[y] = min(fl[x], aa.cap - aa.f);
                    q.push(pd(-dist[y], y));
                }
            }
        }
        if(!fl[de]) break;
        int x = de;
        while(1) {
            pi aa = pa[x];
            int y = aa.first;
            int id = aa.second;
            v[y][id].f += fl[de];
            v[x][v[y][id].rev].f -= fl[de];
            ans = ans + v[y][id].cost * fl[de];
            if(!y) break;
            x = y;
        }
	}
	printf("%.10lf\n", ans);

}