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
	mint():v(0) {}
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

const int mod = 998244353;
typedef mint<mod> mi;

const int L = 12252240;
mi v[L];

/// cf1626F: k is small so lcm(1,2,...,k) is small
/// only need to solve the problem for a_i <= 12252240, brute-force might be enough
void solve()
{
    int n, a, x, y, limk, M;
    
    cin >> n >> a >> x >> y >> limk >> M;
    
    memset(v,0,sizeof(v));
    
    mi ds = 0;
    for (int i = 0; i < n; i++) {
        //dbg(a);
        v[a % L] += 1;
        ds += a / L;
        a = (a * 1ll * x + y) % M;
    }
    
    vector<mi> potn(20);
    potn[0] = 1;
    for (int i = 1; i <= 20; i++) potn[i] = potn[i-1] * n;
    
    mi ans = ds * L * limk * potn[limk-1];
    
    for (int k = 1; k <= limk; k++) {
        for (int p = 0; p < L; p++) {
            //dbg(p, v[p]);
            ans += p * v[p] * potn[limk-k];
            mi vp = v[p];
            v[p - (p%k)] += vp;
            v[p] += vp * (n-2);
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