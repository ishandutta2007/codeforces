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
typedef long long ll;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

template<int MOD> struct mint {
	
	int v;  // explicit -> don't silently convert to int
	
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	
	
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	
	
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	
};

const int mod = 1000000007;
typedef mint<mod> mi;

mi count(ll b, ll q, ll y, ll c, ll r, ll z, ll ar) {
    if (lcm(q,ar) != r) return 0;
    return mi(r/ar) * mi(r/ar);
}

void go() {
    ll b, br, bn;
    ll c, cr, cn;
    cin >> b >> br >> bn >> c >> cr >> cn;
    
    if (cr % br != 0) {
        ps(0);
        return;
    }
    
    if (c < b) {
        ps(0);
        return;
    }
    
    if (c + cr * (cn-1) > b + br * (bn-1)) {
        ps(0);
        return;
    }
    
    ll bm = ((b%br)+br)%br;
    ll cm = ((c%br)+br)%br;
    if (bm!=cm) {
        ps(0);
        return;
    }
    
    if (c - cr < b || c + cr * cn > b + br * (bn-1)) {
        ps(-1);
        return;
    }
    
    mi ans = 0;
    for (ll ar = 1; ar*ar <= cr; ar++) if (cr % ar == 0) {
        ans += count(b,br,bn,c,cr,cn,ar);
        if (cr / ar != ar) ans += count(b,br,bn,c,cr,cn,cr/ar);
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