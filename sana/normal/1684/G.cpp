#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()


typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	
};

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vi sm;
    vi bg;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > m/2) {
            ps(-1);
            return;
        }
        if (x > m/3) bg.push_back(x);
        else sm.push_back(x);
    }
    
    Dinic d(n+2);
    
    for (int i = 0; i < sz(sm); i++) {
        for (int j = 0; j < sz(bg); j++) {
            if (bg[j] % sm[i] == 0 && 2*bg[j] + sm[i] <= m) d.addEdge(j, sz(bg) + i, 1); 
        }
    }
    
    int s = n, t = n+1;
    for (int i = 0; i < sz(bg); i++) d.addEdge(s, i, 1);
    for (int i = 0; i < sz(sm); i++) d.addEdge(sz(bg) + i, t, 1);
    
    int f = d.calc(s, t);
    if (f < sz(bg)) {
        ps(-1);
        return;
    }
    
    
    vector< pii > ans;
    for (int i = 0; i < sz(bg); i++) {
        for (auto e : d.adj[i]) {
            if (e.to != s && e.flow() > 0) {
                int to_sm = e.to - sz(bg);
                
                ans.push_back({bg[i] + sm[to_sm], 2*bg[i] + sm[to_sm]});
                sm[ to_sm ] = -1;
            }
        }
    }
    
    for (int x : sm) if (x != -1) {
        ans.push_back({2*x, 3*x});
    }
    
    ps(sz(ans));
    for (auto [a,b]: ans) ps(a,b);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}