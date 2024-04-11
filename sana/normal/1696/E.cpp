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

typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

template<int MOD> struct mint {
	
	int v;  // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	
	
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	
};

using mi = mint<1000000007>;

vector<mi> fac,ifac;
const int LIM = 510000;

mi C(int n, int k) {
    return fac[n]*ifac[k]*ifac[n-k];
}

mi count_k(int h, int w) {
    return C(h+w,w)-1;
}

void solve()
{
    int n; cin >> n; n++; // wtf
    
    fac = vector<mi>(LIM+1);
    fac[0] = 1;
    for (int i = 1; i <= LIM; i++) fac[i] = fac[i-1] * i;
    
    ifac = vector<mi>(LIM+1);
    ifac[LIM] = inv(fac[LIM]);
    for (int i = LIM-1; i >= 0; i--) ifac[i] = ifac[i+1] * (i+1);
     
    mi ans = 0;
    
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.push_back(0);
    
    for (int i = 0; i < n; i++) {
        ans += count_k(a[i], i+1) - count_k(a[i], i);
    }
    
    ps(ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}