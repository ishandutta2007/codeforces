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
typedef long long ll;

typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

vector<long long> a;
vi p, bg, sm;
set<int> lives;

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void link(int a, int b) {
    dbg("link", a, b);
    a = find(a); b = find(b);
    
    if (a != b) {
        bg[b] = max(bg[b], bg[a]);
        sm[b] = min(sm[b], sm[a]);
        lives.erase(a);
        p[a] = b;
    }
}

ll prvsq(ll a) {
    ll t = (ll)sqrt(a);
    while ( (t+1)*1ll*(t+1) <= a) t++;
    while (t*1ll*t > a) t--;
    return t*1ll*t;
}

ll nxtsq(ll a) {
    ll t = (ll)sqrt(a);
    while ( t*1ll*t <= a) t++;
    while ( (t-1)*1ll*(t-1) > a) t--;
    return t*1ll*t;
}

ll go(int gr, ll k) {
    gr = find(gr);
    
    ll bg_ele = a[bg[gr]] + k;
    ll sm_ele = a[sm[gr]] + k;
    ll top = nxtsq( bg_ele );
    ll bt = prvsq( bg_ele );
    ll inc = 0;
    
    if (bg_ele - bt >= top - bg_ele || sm_ele - bt >= top - sm_ele) 
    {
        inc = max(inc, top - sm_ele);
    }
    if (sm_ele < bt) inc = max(inc, bt - sm_ele);
    
    return inc;
}

void solve()
{
    int n; cin >> n;
    
    a = vector<ll>(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    a.erase(unique(all(a)), a.end());
    n = sz(a);
    
    p = vi(n);
    bg = vi(n);
    sm = vi(n);
    lives.clear();
    for (int i = 0; i < n; i++) {
        p[i] = bg[i] = sm[i] = i;
    }
    
    
    ll k = 0;
    
    vector< pair<long long, int> > crosses;
    
    for (int i = 0; i+1 < n; i++) {
        int cross = (a[i+1] - a[i]) + 1;
        ll sq = cross * 1ll * cross;
        
        ll k_cross = sq - a[i+1];
        if (k_cross > 0) crosses.push_back({k_cross, i});
        else link(i, i+1);
    }
    
    for (int i = 0 ; i < n; i++) if (p[i]==i) lives.insert(i);
    
    sort(all(crosses));
    reverse(all(crosses));
    
    bool ok = false;
    while (!ok) {
        ok = true;
        
        if (sz(lives) == 1) {
            int x = find(*lives.begin());
            ll inc = go(x, k);
            k += inc;
            
            ll dif = a[bg[x]] - a[sm[x]];
            ll tgt = dif * 1ll * dif;
            if (a[sm[x]] + k < tgt) {
                k = tgt - a[sm[x]];
            }
            
            break;
        }
        
        vector<int> ff(all(lives));
        dbg(lives);
        for (int x : ff) {
            ll inc = go(x, k);
            
            dbg(x, k, a[bg[find(x)]] + k, a[sm[find(x)]] + k, inc);
            if (inc > 0) {
                ok = false;
                k += inc;
                while (!crosses.empty() && crosses.back().first <= k) {
                    link(crosses.back().second, crosses.back().second+1);
                    crosses.pop_back();
                }
            }
        }
    }
    
    ps(k);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}