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


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

typedef string str;
typedef long long ll;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

// cf1452F, kind of a guess
// 1) efficiency of operating on i <= x is 1 per operation
// 2) efficiency of converting at least half of 2^i into x is 1 per operation (but less flexible)
// 3) efficiency of converting part of i > x is less than 1 per operation
// greedy strategy: do all 2) first then all 1). If not enough, we are forced to do a 3), then recurse
ll go(vector<ll> a, int x, ll k) {
    ll type_1 = 0;
    for (int i = 0; i <= x; i++) {
        type_1 += ((1LL<<i) - 1) * a[i];
        k -= a[i];
    }
    dbg(type_1);
    
    if (k <= 0) return 0;
    
    ll ops = 0;
    
    auto add_type1 = [&](int x, ll makes, ll cnt) {
        if (cnt > 0) {
            ll opp = (1LL<<x) - 1;
            ll mak = makes * cnt;
            if (k / mak < opp) type_1 = k;
            else type_1 = min(k, type_1 + mak * opp);
        }
    };
    
    auto proc = [&](int i, ll makes, ll ops_per_makes, bool ha = false) {
        ll full = min(a[i], k / makes);
        k -= full * makes;
        a[x] += full * makes;
        a[i] -= full;
        if (ha) a[i-1] += full;
        ops += full * ops_per_makes;
        
        add_type1(x, makes, full);
    };
    
    
    for (int i = x+1; i < sz(a); i++) {
        ll makes = (1LL<<(i-x));
        proc(i, makes, makes-1);
    }
    
    dbg(a,ops,k,type_1);
    if (k <= type_1) return ops + k;
    
    int f = -1;
    for (int i = x+1; i < sz(a); i++) if (a[i]) {
        a[i-1] += 2;
        a[i]--;
        ops++;
        f = i;
        break;
    }
    
    if (f == -1) return -1;
    
    for (int i = f-1; i >= x+1; i--) {
        ll makes = (1LL<<(i-x));
        proc(i, makes, makes-1);
        
        if (k <= type_1) return ops + k;
        a[i]--;
        a[i-1] += 2;
        ops++;
    }
    
    return ops;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    REP(i,n) cin >> a[i];
    
    for (; q; q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos, val; cin >> pos >> val;
            a[pos] = val;
        }
        else {
            int x;
            long long k;
            cin >> x >> k;
            dbg("query",a,x,k);
            ps(go(a, x, k));
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}