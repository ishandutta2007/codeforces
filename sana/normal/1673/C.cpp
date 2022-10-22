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
 

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)


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
	bool operator==(const mint& o) const {
		return v == o.v; }
	
	
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	
	
};

vi palin;

const int mod = 1000000007;
typedef mint<mod> mi;

mi memo[41000][500];

mi go(int x, int k) {
    if (k == 0) return 1;
    
    if (memo[x][k] == 0) {
        memo[x][k] = go(x, k-1);
        if (palin[k] <= x) memo[x][k] += go(x-palin[k], k);
    }
    
    return memo[x][k];
}

void solve()
{
    for (int i = 1; i <= 40000; i++) {
        stringstream ss;
        ss << i;
        string t = ss.str();
        string k = t;
        reverse(all(k));
        if (k == t) palin.push_back(i);
    }
    
    dbg(sz(palin));
    
    int t;
    for (cin >> t; t; t--) {
        int n; cin >> n;
        ps(go(n, sz(palin)-1));
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}