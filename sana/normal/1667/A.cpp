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

using namespace std;

#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


typedef long long ll;

typedef vector<int> vi;
 

void solve()
{
    int n; cin >> n;
    vi a(n);
    REP(i,n) cin >> a[i];
    
    ll ans = 1000000000000000000LL;
    for (int z = 0; z < n; z++) {
        ll th = 0;
        
        ll la = 0;
        for (int m = z-1; m >= 0; m--) {
            ll ct = la / a[m] + 1;
            la = ct * a[m];
            th += ct;
        }
        
        la = 0;
        for (int m = z+1; m < n; m++) {
            ll ct = la / a[m] + 1;
            la = ct * a[m];
            th += ct;
        }
        
        ans = min(ans, th);
    }
    
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}