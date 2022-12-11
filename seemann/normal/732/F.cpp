#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 5e5 + 100;

struct edge {
    int to, n;
};

vector<edge> e[MAXN];
int timer = 0;
bool used[MAXN];
bool bridge[MAXN];
int tin[MAXN], fup[MAXN];
void findb (int v, int p) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (auto ed : e[v]) {
		if (ed.to == p)
		    continue;
		if (used[ed.to])
			fup[v] = min (fup[v], tin[ed.to]);
		else {
			findb(ed.to, v);
			fup[v] = min (fup[v], fup[ed.to]);
			if (fup[ed.to] > tin[v]) {
				bridge[ed.n] = true;
			}
		}
	}
}
vector<edge> ec[MAXN];

int colors = 0;
int color[MAXN];
int st[MAXN], en[MAXN];
void findc(int v, int c) {
    used[v] = true;
    color[v] = c;
	for (auto ed : e[v]) {
		if (used[ed.to]) {
		    if (st[ed.n] != v) {
		        swap(st[ed.n], en[ed.n]);
		    }
		    continue;
		}
		if (bridge[ed.n]) {
		    int nc = colors++;
		    ec[c].push_back({nc, ed.n});
		    ec[nc].push_back({c, ed.n});
		    findc(ed.to, nc);
		} else {
		    if (st[ed.n] != v) {
		        swap(st[ed.n], en[ed.n]);
		    }
		    findc(ed.to, c);
		}
	}
}

int p[MAXN];
int d[MAXN];
int csz[MAXN];
struct cmp {
    bool operator()(int a, int b) {
        if (d[a] != d[b]) {
            return d[a] < d[b];
        }
        if (csz[a] != csz[b]) {
            return csz[a] < csz[b];
        }
        return a < b;
    }
};



int main() {
#ifdef LOCAL
    freopen("f.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        st[i] = u;
        en[i] = v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
 
    clr(used);
    forn(i, n)
		if (!used[i])
			findb(i, -1);
    clr(used);
	forn(i, n) {
	    if (!used[i])
	        findc(i, colors++);
	}
	forn(i, n) {
	    csz[color[i]]++;
	}
	set<int, cmp> s;
	int mx = 0;
	forn(i, colors) {
	    d[i] = ec[i].size();
	    s.insert(i);
	    mx = max(mx, csz[i]);
	}
	clr(used);
	while (!s.empty()) {
	    int v = *s.begin();
	    used[v] = true;
	    s.erase(s.begin());
	    for (auto ed : ec[v]) {
	        if (!used[ed.to]) {
	            s.erase(ed.to);
	            d[ed.to]--;
	            s.insert(ed.to);
	            if (color[st[ed.n]] != v)
	                swap(st[ed.n], en[ed.n]);
	        }
	    }
	}
	printf("%d\n", mx);
	forn(i, m) {
	    printf("%d %d\n", st[i] + 1, en[i] + 1);
	}
    return 0;
}