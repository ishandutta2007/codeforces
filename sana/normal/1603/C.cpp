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
 

#define each(a,x) for (auto& a: x)
#define tcT template<class T


template<class T> using V = vector<T>; 


typedef string str;
typedef long long ll;

typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(V<T>& v);


tcT> void re(T& x) { cin >> x; }


tcT> void re(V<T>& x) { each(a,x) re(a); }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


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
	
	
	friend mint operator+(mint a, const mint& b) { return a += b; }
	
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	
};

using mi = mint<998244353>;

vi a;

void go() {
    ints(n);
    a = vi(n); re(a);
    
    vector< vector<mi> > dp(2, vector<mi>(400));
    vector< vector<mi> > pdp(2, vector<mi>(400));
    
    auto get = [&](int j, int els) {
        if (els <= 317) return mi(els-1)*(j+1) + pdp[0][els];
        else return mi(els-1)*(j+1) + pdp[1][a[j] / els];
    };
    
    mi ans = 0;
    for (int i = 0; i < n; i++) {
        for (int els = 1; els <= 317 && els <= a[i]; els++) {          
            mi ops = els - 1;
            int cur_val = a[i] / els;
    
            dp[0][els] = 0; //ops * (i+1);
            if (i != 0) dp[0][els] += get( i-1, (a[i-1]+cur_val-1) / cur_val );
        }
        
        for (int cur_val = 1; cur_val <= 317 && cur_val <= a[i]; cur_val++) {
            int els = a[i] / cur_val;
            mi ops = els - 1;
            
            dp[1][cur_val] = 0;//ops * (i+1);
            if (i != 0) dp[1][cur_val] += get( i-1, (a[i-1]+cur_val-1) / cur_val );
        }
        
        ans += dp[0][1];
        swap(dp,pdp);
    }
    
    ps( (int)ans );
}

void solve()
{
    ints(t);
    for (; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}