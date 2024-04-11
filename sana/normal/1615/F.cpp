//#define LOCAL
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
	
	mint(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	
	
	friend str ts(mint a) { return ts(a.v); }
   
	mint& operator+=(const mint& o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	
	mint& operator*=(const mint& o) { 
		v = int((ll)v*o.v%MOD); return *this; }
	
	
	friend mint operator+(mint a, const mint& b) { return a += b; }
	
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	
};

const int mod = 1000000007;
typedef mint<mod> mi;


void go() {
    int n; cin >> n;
    string src, tgt;
    cin >> src >> tgt;
    
    vector<vector<mi>> cntdsf = vector< vector<mi> >(n+1, vector<mi>(2*n+2, 0));
    auto cnt = [&](int i, int j) -> mi& { return cntdsf[i][j+n]; };
    
    vector<vector<mi>> mvsdsf = vector< vector<mi> >(n+1, vector<mi>(2*n+2, 0));
    auto mvs = [&](int i, int j) -> mi& { return mvsdsf[i][j+n]; };
    
    cnt(0, 0) = 1;
    for (int i = 0; i < n; i++) {
        for (int diff = -n; diff <= n; diff++) {
            dbg(i, diff, cnt(i, diff));
            int nd = diff;
            if (src[i] != '?') nd += (src[i]-'0') * ( (i % 2)*2 - 1 );
            if (tgt[i] != '?') nd -= (tgt[i]-'0') * ( (i % 2)*2 - 1 );
            
            if (src[i] != '?' && tgt[i] != '?') {
                cnt(i+1, nd) += cnt(i, diff);
                mvs(i+1, nd) += mvs(i, diff) + cnt(i, diff) * abs(diff);
            }
            else if (src[i] != '?') {
                cnt(i+1, nd) += cnt(i, diff);
                cnt(i+1, nd - ( (i % 2)*2 - 1 ) ) += cnt(i, diff);
                
                mvs(i+1, nd) += mvs(i, diff) + cnt(i, diff) * abs(diff);
                mvs(i+1, nd - ( (i % 2)*2 - 1 )) += mvs(i, diff) + cnt(i, diff) * abs(diff);
            }
            else if (tgt[i] != '?') {
                cnt(i+1, nd) += cnt(i, diff);
                cnt(i+1, nd + ( (i % 2)*2 - 1 ) ) += cnt(i, diff);
                
                mvs(i+1, nd) += mvs(i, diff) + cnt(i, diff) * abs(diff);
                mvs(i+1, nd + ( (i % 2)*2 - 1 )) += mvs(i, diff) + cnt(i, diff) * abs(diff);
            }
            else {
                cnt(i+1, nd) += 2*cnt(i, diff);
                cnt(i+1, nd+1) += cnt(i, diff);
                cnt(i+1, nd-1) += cnt(i, diff);
                
                mvs(i+1, nd) += 2 * (mvs(i, diff) + cnt(i, diff) * abs(diff));
                mvs(i+1, nd+1) += mvs(i, diff) + cnt(i, diff) * abs(diff);
                mvs(i+1, nd-1) += mvs(i, diff) + cnt(i, diff) * abs(diff);
            }
        }
    }
    
    ps( mvs(n, 0) );
}

void solve()
{
    int t;
    for (cin >> t; t; t--) {
        go();
        //break;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}