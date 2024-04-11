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
 

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

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
	mint& operator-=(const mint& o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	
		
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	
};

const int mod = 998244353;
typedef mint<mod> mi;

mi sumT(ll n) {
    if (n == 0) return 0;
    return n * pow(mi(2), n-1);
}

int cnt[110000];
int m[110000];
int lp[110000];

// cf1436F: write a bunch of sums, do algebra, zzzzz
// sum i * C(n, i) = n * 2^(n-1)
void solve()
{
    memset(cnt,0,sizeof(cnt));
    memset(m,0,sizeof(m));
    memset(lp,0,sizeof(lp));
    
    int n; cin >> n;
    REP(i,n) { 
        int x; cin >> x;
        cin >> cnt[x];
    }
    
    m[1] = 1;
    for (int i = 2; i < 110000; ++i) {
        if (!lp[i]) for (int j = i; j < 110000; j += i)
            if (!lp[j]) lp[j] = i;
        m[i] = [](int x) {
            int cnt = 0;
            while (x > 1) {
                int k = 0, d = lp[x];
                while (x % d == 0) {
                    x /= d;
                    ++k;
                    if (k > 1) return 0;
                }
                ++cnt;
            }
            if (cnt & 1) return -1;
            return 1;
        }(i);
    }
    
    mi ans = 0;
    for (int i = 1; i <= 100000; i++) {
        ll tot = 0;
        mi sum = 0;
        mi sum_sq = 0;
        
        for (int j = i; j <= 100000; j+=i) {
            tot += cnt[j];
            sum += mi(j) * cnt[j];
            sum_sq += (mi(j) * mi(j)) * cnt[j];
        }
        
        mi sum_pair = sum * sum - sum_sq;
        
        mi ad = 0;
        if (tot >= 1) ad += sum_sq * sumT(tot-1);
        if (tot >= 2) ad += sum_pair * ( sumT(tot-2) + pow(mi(2), tot-2) );
        
        ans += m[i] * ad;
    }
    
    ps(ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}