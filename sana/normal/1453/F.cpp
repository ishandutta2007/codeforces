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


typedef vector<int> vi;
 

#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

int dp[3100][3100];

// greedy doesn't work because optimal decision depends on information obtained later
// consider forming a chain of platforms: a chain is invalid if there are platforms x, y, z such that x+a[x] >= z
// therefore to make a dp we need the last two platforms in our state.
void go() {
    int n; cin >> n;
    vi a(n);
    REP(i,n) cin >> a[i];
    
    REP(i,n+1) REP(j,n+1) dp[i][j] = 1000000000;
    dp[n-1][n] = 0;
    
    vi pref_min(n+1);
    for (int sec = n-1; sec >= 0; sec--) {
        pref_min[n] = dp[sec][n];
        for (int i = n-1; i >= sec; i--) pref_min[i] = min(dp[sec][i], pref_min[i+1]);
 
        int pass = 0;
        for (int fi = sec-1; fi >= 0; fi--) if (fi + a[fi] >= sec) {
            dp[fi][sec] = pass + pref_min[fi + a[fi] + 1];
            pass++;
        }
    }
    
    int ans = 1000000000;
    for (int i = 1; i < n; i++) ans = min(ans, dp[0][i]);
    ps(ans);
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