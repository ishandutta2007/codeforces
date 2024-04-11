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
	
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	
};


using mi = mint<998244353>;

vector<mi> fac(110000);
vector<mi> ifac(110000);

mi C(int n, int k) {
    return fac[n]*ifac[k]*ifac[n-k];
}

void go() {
    ints(n);
    vi a(n); re(a);
    
    vector<ll> pp(n);
    vector<ll> ppr(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) pp[i] += pp[i-1];
        pp[i] += a[i];
    }
    
    for (int i = n-1; i >= 0; i--) {
        if (i < n-1) ppr[i] += ppr[i+1];
        ppr[i] += a[i];
    }
    
    int i = 0;
    int j = n-1;
    
    mi ans = 1;
    while (i < j) {
        while (i < n && pp[i] < ppr[j]) i++;
        while (j >= 0 && ppr[j] < pp[i]) j--;

        if (i<j && pp[i] == ppr[j]) {
            int sti = i;
            while (i+1 < n-1 && pp[i+1] == pp[sti]) i++;
            int stj = j;
            while (j-1 >= 1 && ppr[j-1] == ppr[j]) j--;
            
            int leni = i-sti+1;
            int lenj = stj-j+1;
            mi mult = 1;
            
            dbg(sti,stj);
            if (j <= i) {
                mult = pow(mi(2), leni);
            }
            else {
                for (int div = 1; div <= min(leni,lenj); div++) {
                    mult += C(leni,div) * C(lenj,div);
                }
            }
            
            ans *= mult;
            i++;
            j--;
        }
    }
    
    ps(ans);
}

void solve()
{
    fac[0]=1;
    for (int i = 1; i <= 100000; i++) fac[i] = fac[i-1]*i;
    ifac[100000] = inv(fac[100000]);
    for (int i = 99999; i >= 0; i--) ifac[i] = ifac[i+1]*(i+1);
    
    ints(t);
    for (; t; t--) go();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}