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
 

typedef string str;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

void go() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    set<int> empty;
    for (int i = 0; i <= n; i++) empty.insert(i);
    
    vector<long long> ppa(n+1), ppb(n+1);
    for (int i = 0; i < n; i++) {
        ppa[i+1] = ppa[i] + a[i];
        ppb[i+1] = ppb[i] + b[i];
    }
    
    vector<int> ok(n+1);
    for (int i = 0; i <= n; i++) if (ppa[i] == ppb[i]) {
        ok[i] = 1;
        empty.erase(i);
    }
    
    vector< int > endp(m);
    vector< pair<int, int> > inter(m);
    vector< vector<int> > g(n+1);
    
    vector< int > done_ints;
    
    for (int i = 0; i < m; i++) {
        cin >> inter[i].first >> inter[i].second;
        inter[i].first--;
        
        endp[i] += ok[inter[i].first];
        endp[i] += ok[inter[i].second];
        g[inter[i].first].push_back(i);
        g[inter[i].second].push_back(i);
        if (endp[i] == 2) {
            done_ints.push_back(i);
        }
    }
    
    while (!done_ints.empty()) {
        int cur = done_ints.back();
        done_ints.pop_back();
        
        auto it = empty.lower_bound(inter[cur].first);
        
        vector<int> rem;
        while (it != empty.end() && *it < inter[cur].second) {
            ok[*it] = 1;
            for (int x : g[*it]) {
                if (++endp[x] == 2) done_ints.push_back(x);
            }
            
            auto nxt = next(it);
            empty.erase(it);
            it = nxt;
        }
    }
    
    bool ans = true;
    for (int i = 0; i <= n; i++) ans = ans && ok[i];
    ps(ans ? "YES" : "NO");
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