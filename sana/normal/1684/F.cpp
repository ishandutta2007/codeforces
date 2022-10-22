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
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


typedef string str;

typedef pair<int, int> pii;
typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

void go() {
    int n, m;
    cin >> n >> m;
    
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector< pii > segs(m);
    for (int i = 0; i < m; i++) {
        cin >> segs[i].first >> segs[i].second;
        segs[i].first--; segs[i].second--;
    }
    
    sort(all(segs), [](pii a, pii b) { return a.second < b.second; });
    
    set<int> left_boundary;
    vi prefix_max_right(n, -1);
    
    
    int cur_seg = 0;
    
    set< pair<int, int> > pows;
    
    vector< pii > ppow;
    
    vi rt(n,-1);
    map<int, vi> pos;
    
    map<int, int> la;
    for (int r = 0; r < n; r++) {
        pos[ a[r] ].push_back(r);
        
        /*if (la.count(a[r])) {
            lt[r] = la[ a[r] ];
            pows.insert({la[ a[r] ], r});
        }
        
        la[ a[r] ] = r;
        
        while (cur_seg < m && segs[cur_seg].second == r) {
            while (!pows.empty() && pows.rbegin()->first >= segs[cur_seg].first) {
                ppow.push_back(*pows.rbegin());
                pows.erase(--pows.end());
            }
            
            cur_seg++;
        }*/
    }
    
    for (int i = 0; i < m; i++) {
        rt[segs[i].first] = max(rt[segs[i].first], segs[i].second);
    }
    for (int i = 1; i < n; i++) rt[i] = max(i, max(rt[i], rt[i-1]));
    
    for (int i = 0; i < n; i++) {
        int p = lower_bound( all(pos[a[i]]), i) - pos[a[i]].begin();
        
        if (p+1 < sz(pos[a[i]]) && pos[a[i]][p+1] <= rt[i]) ppow.emplace_back(i, pos[a[i]][p+1]);
        
        int l = lower_bound( all(pos[a[i]]), rt[i]+1 ) - pos[a[i]].begin();
        l--;
        if (l > p+1) ppow.emplace_back(i, pos[a[i]][l]);
    }
    
    sort(all(ppow));
    
    if (ppow.empty()) {
        ps(0);
        return;
    }
    
    dbg(ppow);
    //return;
    int cur_r = ppow.back().first;
    int cur_l = ppow.front().first;
    int ans = cur_r - cur_l + 1;
    
    int min_second = 1000000000;
    int cur_pp = 0;
    
    while (cur_pp < sz(ppow) && ppow[cur_pp].first == cur_l) {
        while (cur_pp < sz(ppow) && ppow[cur_pp].first == cur_l) {
            cur_r = max(cur_r, ppow[cur_pp].second);
            min_second = min(min_second, ppow[cur_pp].second);
            cur_pp++;
        }
        
        cur_l = min_second;
        if (cur_pp < sz(ppow)) cur_l = min(cur_l, ppow[cur_pp].first);
        
        dbg(cur_l, cur_r, cur_pp, ppow);
        ans = min(ans, cur_r - cur_l + 1);
    }
    
    ps(ans);
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