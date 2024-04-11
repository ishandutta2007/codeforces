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

#define tcTUU tcT, class ...U
 

typedef string str;
typedef long long ll;


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


tcTUU> void re(T& t, U&... u) { re(t); re(u...); }


using ul = uint64_t;
struct FastMod {
	ul b, m; FastMod(ul b) : b(b), m(-1ULL / b) {}
	ul reduce(ul a) {
		ul q = (ul)((__uint128_t(m) * a) >> 64), r = a - q * b;
		return r - (r >= b) * b; }
};

template<int id> struct mint_dyn {
	static FastMod MF;
	static int mod() { return (int)MF.b; }
	static void set_mod(int m) { assert(1 <= m); MF = FastMod(m); }
	int v;  // explicit -> don't silently convert to int
	mint_dyn() { v = 0; }
	mint_dyn(ll _v) { v = int((-mod() < _v && _v < mod()) ? _v : _v % mod());
		if (v < 0) v += mod(); }
	
	
	friend str ts(mint_dyn a) { return ts(a.v); }
   
	mint_dyn& operator+=(const mint_dyn& m) { 
		if ((v += m.v) >= mod()) v -= mod(); 
		return *this; }
	
	mint_dyn& operator*=(const mint_dyn& m) { 
		v = (int)MF.reduce((ll)v*m.v); return *this; }
	
	
	friend mint_dyn operator+(mint_dyn a, const mint_dyn& b) { return a += b; }
	
	friend mint_dyn operator*(mint_dyn a, const mint_dyn& b) { return a *= b; }
	
};
template<int id> FastMod mint_dyn<id>::MF = FastMod(1);

using mod_int = mint_dyn<0>;
mod_int dp[210][23][8000];
mod_int C[210][210];
int n, m;

void solve()
{
    re(n,m);
    mint_dyn<0>::set_mod(m);
    
    for (int i = 0; i <= 200; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]);
        }
    }
    
    mod_int ans = 1;
    
    for (int mi = max(1, n-21); mi <= n; mi++) {
        for (int rem = 0; rem <= n; rem++) {
            for (int cur = n+1; cur > mi; cur--) {
                for (int sum = 0; sum <= (n+1) * (n+1) - mi * (n+1); sum++) {
                    if (rem == 0) dp[rem][cur-mi][sum] = 1;
                    else dp[rem][cur-mi][sum] = 0;
                }
            }
        }
        
        for (int rem = 1; rem <= n; rem++) {
            int placed = n - rem;
            for (int cur = n+1; cur > mi; cur--) {
                for (int sum = 0; sum <= min((n+1) * (mi-1) - (rem-1) * cur, (cur-1) * placed) - mi * placed; sum++) {
                    int real_sum = sum + mi * placed;
                
                    if (cur < n+1) dp[rem][cur-mi][sum] += dp[rem][cur-mi+1][sum];
                    
                    //real_sum + put * cur <= cur * mi
                    //put <= mi - (real_sum + cur - 1) / cur
                    for (int put = 1; put <= rem; put++) {
                        if (real_sum + put * cur > cur * mi) break;
                        if (put == rem) dp[rem][cur-mi][sum] += 1;
                        else if (cur < n+1) dp[rem][cur-mi][sum] += dp[rem - put][cur-mi+1][sum + put * (cur-mi)] * C[rem][put];
                    }
                    
                }
            }
        }
        
        for (int put = 1; put <= n && put <= mi; put++) {
            ans += dp[n - put][1][0] * C[n][put];
        }
    }
    
    ps(ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}