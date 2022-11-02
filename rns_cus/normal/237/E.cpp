#include <bits/stdc++.h>
using namespace std;

struct dat{
    int x, rev, f, cap, cost;
    dat(int x = 0, int rev = 0, int f = 0, int cap = 0, int cost = 0):x(x), rev(rev), f(f), cap(cap), cost(cost){}
};

#define N 300
typedef pair<int, int> pi;
pi pa[N];
priority_queue<pi> q;
vector<dat> v[N];
int pot[N], dist[N], A[N * 2], gas[30], fl[N], vis[N];
char s[N];
#define inf 1e9
void add(int x, int y, int ca, int co) {
    int n = v[x].size();
    int m = v[y].size();
    v[x].push_back(dat(y, m, 0, ca, co));
    v[y].push_back(dat(x, n, 0, 0, -co));
}


int main() {
    //freopen("1.in", "r", stdin);
    int n;
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i ++) {
        gas[s[i] - 'a' + 1] ++;
    }
    int Len = len;
    scanf("%d", &n);
    int so, de;
    so = 0;
    de = 27 + n;
    for(int i = 1; i <= 26; i ++) add(i, de, gas[i], 0);

    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%s", s);
        len = strlen(s);
        scanf("%d", &x);
        add(0, 26 + i, x, 0);
        for(int j = 0; j < len; j ++) {
            add(26 + i, s[j] - 'a' + 1, 1, i);
        }
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
			int ndist = pot[u] + e.cost;
			if (pot[vv] > ndist) {
				pot[vv] = ndist;
				if (!vis[vv]) {
					vis[vv] = true;
					A[qt++ % nodes] = vv;
				}
			}
		}
	}

    int mx = 0;
    int ans = 0;
	while(1) {
        for(int i = 0; i <= de; i ++) dist[i] = inf, fl[i] = 0;
        dist[0] = 0;
        fl[0] = inf;
        while(!q.empty()) q.pop();
        q.push(pi(0, 0));
        while(!q.empty()) {
            pi aa = q.top();
            q.pop();
            int x = aa.second;
            if(-aa.first != dist[x]) continue;
            for(int i = 0; i < v[x].size(); i ++) {
                dat bb = v[x][i];
                if(bb.f == bb.cap) continue;
                int y = bb.x;
                int di = dist[x] + bb.cost + pot[x] - pot[y];
                if(di < dist[y]) {
                    dist[y] = di;
                    q.push(pi(-dist[y], y));
                    fl[y] = min(fl[x], bb.cap - bb.f);
                    pa[y] = pi(x, i);
                }
            }
        }
        if(!fl[de]) break;
        mx += fl[de];
        for(int i = 0; i <= de; i ++) pot[i] += dist[i];
        int x = de;
        while(1) {
            pi aa = pa[x];
            int y = aa.first;
            int id = aa.second;
            ans = ans + v[y][id].cost * fl[de];
            v[y][id].f += fl[de];
            v[x][v[y][id].rev].f -= fl[de];
            if(!y) break;
            x = y;
        }
	}
	if(mx != Len) puts("-1");
	else printf("%d\n", ans);
	return 0;
}