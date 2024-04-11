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
 

void go() {
    int n, m;
    cin >> n >> m;
    
    long long bg = 0, sm = 1000000000000000000LL;
    int ans = 1;
    
    for (int i = 0; i < n; i++) {
        long long t = 0;
        for (int j = 0; j < m; j++) {
            long long x; cin >> x;
            t += j * x;
        }
        sm = min(sm, t);
        
        if (t > bg) {
            bg = t;
            ans = i+1;
        }
    }
    
    cout << ans << " " << bg - sm << '\n';
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