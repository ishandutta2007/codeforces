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
 

typedef vector<int> vi;
 

void go() {
    int n, x;
    cin >> n >> x;
    
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int sm = a[0] - x;
    int bg = a[0] + x;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sm = max(sm, a[i] - x);
        bg = min(bg, a[i] + x);
        
        if (sm > bg) {
            ans++;
            sm = a[i] - x;
            bg = a[i] + x;
        }
    }
    
    cout << ans << '\n';
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