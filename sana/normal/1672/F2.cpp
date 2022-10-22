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


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

typedef string str;


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

void go() {
    int n; cin >> n;
    vi a(n), b(n);
    REP(i,n) {
        cin >> a[i]; a[i]--;
    }
    REP(i,n) {
        cin >> b[i]; b[i]--;
    }
    
    map<int, vi> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }
    
    int bstcnt = a[0];
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (sz(it->second) > sz(mp[bstcnt])) bstcnt = it->first;
    }
    
    vector< vi > g(2*n);
    
    for (int i = 0; i < n; i++) {
        g[i].push_back(n+b[i]);
    }
    
    for (int i = 0; i < n; i++) if (i != bstcnt) {
        for (int x : mp[i]) {
            g[n+i].push_back(x);
        }
    }
    
    scc(g, [&](vi& v) { });
    
    ps(ncomps == 2*n ? "AC" : "WA");
}

void solve()
{
    int t;
    for (cin >> t; t; t--) go();
    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}