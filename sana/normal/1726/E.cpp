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
 

#define tcT template<class T


typedef string str;
typedef long long ll;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


template<int MOD> struct mint {
	
	int v;  // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	
	
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};


using mi = mint<998244353>;

mi fac[1100000];
mi ifac[1100000];
mi pacomb[1100000];

mi C(int n, int k) {
    return fac[n] * ifac[n-k] * ifac[k];
}

void go() {
    ints(n);
    
    //mi ans = pacomb[n];
    mi ans = 0;
    for (int pairs = 0; pairs <= n/2; pairs+=2) {
        mi form_pairs = C(n - pairs, pairs);
        ans += pacomb[n - pairs*2] * form_pairs * fac[pairs] / fac[pairs/2];
        dbg(n,pairs,ans);
    }
    
    ps(ans);
}

void solve()
{
    fac[0] = 1;
    for (int i = 1; i <= 1000000; i++) fac[i] = fac[i-1]*i;
    ifac[1000000] = inv(fac[1000000]);
    for (int i = 999999; i >= 0; i--) ifac[i] = ifac[i+1]*(i+1);
    
    pacomb[0] = pacomb[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        pacomb[i] = pacomb[i-1];
        pacomb[i] += pacomb[i-2] * (i-1);
    }
    
    int t;
    for (cin >> t; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}