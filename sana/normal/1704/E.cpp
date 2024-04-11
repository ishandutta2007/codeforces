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


typedef long long ll;

typedef vector<int> vi;
 

template<int MOD> struct mint {
	
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	
	
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	
	
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	
};

using mi = mint<998244353>;

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), ret;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	queue<int> q; // use priority_queue for lexic. largest ans.
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int i = q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (int x : gr[i])
			if (--indeg[x] == 0) q.push(x);
	}
	return ret;
}


void go() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<vi> g(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
    }
    
    vi topsort = topoSort(g);
    
    vector<mi> pot(n);
    pot[topsort[n-1]] = 1;
    for (int i = n-2; i >= 0; i--) {
        int v = topsort[i];
        for (int x : g[v]) pot[v] += pot[x];
    }
    
    
    for (int t = 0; t <= 1000; t++) {
        bool found = false;
        for (int i = n-1; i >= 0; i--) {
            int v = topsort[i];
            if (a[v]) {
                found = true;
                a[v]--;
                for (int x : g[v]) a[x]++; 
            }
        }
        
        if (!found) {
            cout << t << '\n';
            return;
        }
    }
    
    mi ans = 1001;
    for (int i = n-1; i >= 0; i--) {
        int v = topsort[i];
        ans += pot[v] * a[v];
    }
    cout << (int)ans << '\n';
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