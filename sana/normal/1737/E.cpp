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
 

typedef string str;
typedef long long ll;


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
		
	
	friend mint operator+(mint a, const mint& b) { return a += b; }
	
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	
};


using mi = mint<1000000007>;

void go() {
    int n; cin >> n;
    
    vector<mi> p2(n+1), ip2(n+1);
    p2[0] = 1; 
    ip2[0] = 1; ip2[1] = inv(mi(2));
    for (int i = 1; i <= n; i++) p2[i] = p2[i-1]+p2[i-1];
    for (int i = 2; i <= n; i++) ip2[i] = ip2[i-1] * ip2[1];
    
    vector<mi> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int have = n-i;
        
        dp[i] = dp[i-1];
        if (have <= i) dp[i] -= dp[i - have] * ip2[min(i-1, have)];
        if ( (have+1) <= i) dp[i] -= dp[i - (have + 1)] * ip2[min(i-1, have+1)];
    }
    
    for (int i = 0; i < n; i++) {
        mi left = p2[(1+i)/2] * ip2[i+1];
        if (i == n-1) left *= 2;
        else if (i == 0) left = 0;
        
        mi right = dp[n-i-1];
        dbg(left,right);
        ps(left*right);
    }
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