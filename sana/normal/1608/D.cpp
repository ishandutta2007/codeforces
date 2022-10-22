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
 

#define tcT template<class T


typedef string str;
typedef long long ll;
typedef pair<int, int> pii;

 
#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

tcT> void re(T& x) { cin >> x; }


#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);


template<int MOD> struct mint {
	
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint():v(0) {}
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	
	
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
		
	
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	
};

using mi = mint<998244353>;
vector<mi> fac, ifac;

mi C(int n, int k) {
    return fac[n] * ifac[k] * ifac[n-k];
}

void solve()
{
    fac = vector<mi>(110000);
    fac[0] = 1;
    for (int i = 1; i <= 100000; i++) fac[i] = fac[i-1] * i;
    
    ifac = vector<mi>(110000);
    ifac[100000] = inv(fac[100000]);
    for (int i = 99999; i >= 0; i--) ifac[i] = ifac[i+1] * (i+1);
    
    
    ints(n);
    vector< pii > inp(n);
    
    int cur01 = 0, cur10 = 0;
    int pot01 = 0, pot10 = 0, pot_any = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        
        pair<int,int> p;
        if (s[0] == '?') p.first = -1;
        else p.first = (s[0]&1)^1;
        if (s[1] == '?') p.second = -1;
        else p.second = (s[1] == '?' ? -1 : s[1]&1);
        inp[i] = p;
        
        if (inp[i] == pii{0,1}) cur01++;
        else if (inp[i] == pii{1,0}) cur10++;
        else if (inp[i] == pii{1,-1} || inp[i] == pii{-1,0}) pot10++;
        else if (inp[i] == pii{0,-1} || inp[i] == pii{-1,1}) pot01++;
        else if (inp[i] == pii{-1,-1}) pot_any++;
    }
    
    mi ans = 0;
    for (int tot01 = 0; tot01 <= n; tot01++) {
        int tot10 = tot01;
        if (tot01 < cur01 || tot10 < cur10 || tot01 > cur01+pot01+pot_any || tot10 > cur10+pot10+pot_any) continue;
        
        
        ans += C(pot01+pot_any, tot01-cur01) * C(pot10+pot_any, tot10 - cur10);
        dbg(tot01,ans);
    }
    
    mi no_cross = 1;
    for (int i = 0; i < n; i++) {
        if (inp[i] == pii{0,1} || inp[i] == pii{1,0}) no_cross = 0;
        else if (inp[i] == pii{-1,-1}) no_cross *= 2;
    }
    ans -= no_cross;
    
    bool ok00 = true, ok11 = true;
    for (int i = 0; i < n; i++) {
        if (inp[i].first == 1 || inp[i].second == 1) ok00 = false;
        if (inp[i].first == 0 || inp[i].second == 0) ok11 = false;
    }
    
    dbg(ans,no_cross,ok00,ok11);
    if (ok00) ans+=1;
    if (ok11) ans+=1;
    
    ps( (int)ans );
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}