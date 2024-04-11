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


#define ts to_string


str ts(const char* s) { return (str)s; }


template<class A> void pr(A x) { cout << ts(x); }

void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 

void go() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0 ; i< n; i++) cin >> a[i];
    
    long long ans = 0;
    
    if (k >= n) {
        ans += a[0];
        ans += k-n;
        
        a[0] = 0;
        for (int i = 1; i < n; i++) a[i] += k-(n-1);
        k = n-1;
    }
    
    dbg(ans, a);
    vector<long long> pps(n+1);
    for (int i = 0; i < n; i++) pps[i+1] = pps[i] + a[i];
    
    long long max_i = 0;
    for (int i = 0; i+k <= n; i++) {
        max_i = max(max_i, pps[i + k] - pps[i]);
    }
    
    ans += max_i;
    ans += (k-1) * 1ll * k / 2;
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