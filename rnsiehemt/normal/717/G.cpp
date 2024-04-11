#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

namespace MCF {
	#define MAXN 100010
	#define MAXM 100010
	#define wint int
	#define cint int
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	const cint cEPS = 0;
	const cint cINF = 1001001001;
	int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
	wint capa[MAXM], tof;
	cint cost[MAXM], toc, d[MAXN], pot[MAXN];
	int vis[MAXN], pree[MAXN];
	void init(int _n) {
		n = _n; m = 0; memset(ptr, ~0, n << 2);
	}
	void ae(int u, int v, wint w, cint c) {
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w; cost[m] = +c; ++m;
		next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
	}
	bool spRep(int src, int ink, wint flo = wINF) {
		wint f;
		cint c, cc;
		int i, u, v;
		memset(pot, 0, n * sizeof(cint));
		for (bool cont = 1; cont; ) {
			cont = 0;
			for (u = 0; u < n; ++u) for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
				if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
					pot[zu[i]] = pot[u] + cost[i]; cont = 1;
				}
			}
		}
		for (toc = 0, tof = 0; tof + wEPS < flo; ) {
			typedef pair<cint,int> node;
			priority_queue< node,vector<node>,greater<node> > q;
			for (u = 0; u < n; ++u) { d[u] = cINF; vis[u] = 0; }
			for (q.push(make_pair(d[src] = 0, src)); !q.empty(); ) {
				c = q.top().first; u = q.top().second; q.pop();
				if (vis[u]++) continue;
				for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
					cc = c + cost[i] + pot[u] - pot[v = zu[i]];
					if (d[v] > cc) { q.push(make_pair(d[v] = cc, v)); pree[v] = i; }
				}
			}
			if (!vis[ink]) return 0;
			f = flo - tof;
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; f = min(f,capa[i]); }
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
			tof += f;
			toc += f * (d[ink] - pot[src] + pot[ink]);
			for (u = 0; u < n; ++u) pot[u] += d[u];
		}
		return 1;
	}
}

int n, m;
string o;
string st[105]; int p[105];
int x;

int main() {
    cin >> n >> o >> m;
    FO(i,0,m) {
        cin >> st[i] >> p[i];
    }
    cin >> x;

    MCF::init(n+3);
    int s = n+1, t = n+2;
    MCF::ae(s, 0, x, 0);
    FO(i,0,n) MCF::ae(i,i+1,x,0);
    MCF::ae(n, t, x, 0);

    FO(i,0,m) {
        FO(j,0,n) {
            if (o.substr(j,st[i].size()) == st[i]) {
                MCF::ae(j, j+st[i].size(),1,-p[i]);
            }
        }
    }

    MCF::spRep(s,t);
    printf("%d\n", -MCF::toc);
}