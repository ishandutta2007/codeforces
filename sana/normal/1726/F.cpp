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
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif


using namespace std;
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


#define tcT template<class T

#define tcTUU tcT, class ...U
 

typedef string str;
typedef long long ll;

typedef vector<int> vi;

 
#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


struct light {
    ll g, c;
};

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    vector<T> value;
 
    U noop;
    vector<bool> dirty;
    vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }
 
    
    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
    void rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
    void propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
 
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
 
                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }
 
    void upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
    T query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

const int INF = 1000000000;

struct node {
    int mn = INF;
    
    node operator+(node ot) {
        ot.mn = min(ot.mn, mn);
        return ot;
    }
};

struct upd {
    int delta = INF;
    
    node operator()(node ot) {
        ot.mn = min(ot.mn, delta);
        return ot;
    }
    
    upd operator+(upd ot) {
        ot.delta = min(ot.delta, delta);
        return ot;
    }
};

void solve()
{
    ints(n, t);
    vector<light> l(n);
    
    for (int i = 0; i < n; i++) {
        re(l[i].g, l[i].c);
    }
    
    vector<ll> pos(n);
    for (int i = 1; i < n; i++) {
        int d; re(d);
        pos[i] = pos[i-1] + d;
    }
    for (int i = 0; i < n; i++) l[i].c = (l[i].c + pos[i]) % t;
    
    vector<int> crits;
    
    vi close(n), open(n);
    for (int i = 0; i < n; i++) {
        close[i] = (l[i].g + t - l[i].c) % t;
        open[i] = (t - l[i].c) % t;
        crits.push_back(close[i]);
        crits.push_back(open[i]);
    }
    crits.push_back(0);
    crits.push_back(t);
    sort(all(crits));
    crits.erase(unique(all(crits)), crits.end());
    
    seg_tree_lazy<node, upd> seg(sz(crits));
    
    vector<ll> tot_time(n);
    for (int i = n-1; i >= 0; i--) {
        int leave_idx = lower_bound(all(crits), open[i]) - crits.begin();
        int stop_at = seg.query(leave_idx, leave_idx).mn;
        
        if (stop_at != INF) {
            tot_time[i] = open[stop_at] - open[i];
            if (tot_time[i] < 0) tot_time[i] += t;
            tot_time[i] += tot_time[ stop_at ];
        }
        dbg(i,stop_at,tot_time[i]);
        
        int tsx = lower_bound(all(crits), close[i]) - crits.begin();
        int tex = lower_bound(all(crits), open[i]) - crits.begin();
        if (tex == 0) tex = sz(crits)-1;
        
        if (tsx > tex) {
            seg.upd(tsx, sz(crits)-1, upd{i});
            seg.upd(0, tex-1, upd{i});
        }
        else {
            seg.upd(tsx, tex-1, upd{i});
        }
    }
    
    ll ans = 1000000000000000000;
    for (int i = 0; i < sz(crits)-1; i++) {
        int stop_at = seg.query(i, i).mn;
        
        if (stop_at == INF) {
            ans = 0;
            break;
        }
        
        ll th = open[stop_at] - (crits[i+1]-1);
        if (th < 0) th += t;
        
        ans = min(ans, th + tot_time[stop_at]);
        dbg(i,ans);
    }
    
    ps(ans + pos[n-1]);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}